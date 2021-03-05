#include "DBDump.h"


#include <sstream>
#include <SQLiteCpp/Statement.h>

#include "../Hook/SQLiteDB.h"

using namespace std;

void DBDump::dump()
{
    db.exec("PRAGMA cache_size=10000");
    db.exec("PRAGMA synchronous = OFF");
    db.exec("PRAGMA journal_mode = MEMORY");


    vector<string> tables;
    try
    {
        auto result = query("select name,sql from sqlite_master where type='table'");
        if (result != SQLITE_ROW)
        {
            printf("No tables with result %d.\n", result);
            nextRow();
            return;
        }
        while (auto row = nextRow())
        {
            auto sql  = row->fields(1).string();
            auto name = row->fields(0).string();
            if (!db.tableExists(name))
            {
                db.exec(sql);
            }
            tables.push_back(name);
        }
    }
    catch (std::exception& ex)
    {
        cerr << "Failed to create tables" << endl;
        cerr << ex.what();
        throw ex;
    }

    try
    {
        for (auto& table : tables)
        {
            int total = 0;
            if (query("SELECT COUNT(*) FROM " + table) != SQLITE_ROW)
            {
                nextRow();
                printf("Empty table %s\n", table.c_str());
                continue;
            }
            if (auto info = nextRow())
            {
                nextRow();
                total = info->fields(0).int_();
                printf("%d records in %s\n", total, table.c_str());
            }
            else
            {
                printf("Empty table %s\n", table.c_str());
                continue;
            }

            unique_ptr<SQLite::Statement> statement;
            bool firstRow = true;
            
            const int LIMIT = 100;
            for (auto skip = 0; skip < total; skip += LIMIT)
            {
                printf("%d/%d\n", skip, total);
                char sql[1024];
                sprintf_s(sql, sizeof(sql), "SELECT * FROM %s LIMIT %d OFFSET %d", table.c_str(), LIMIT, skip);

                if (query(string(sql)) != SQLITE_ROW)
                {
                    nextRow();
                    printf("Empty table %s\n", table.c_str());
                    break;
                }

                db.exec("BEGIN TRANSACTION");

                while (auto row = nextRow())
                {
                    if (firstRow)
                    {
                        firstRow = false;
                        ostringstream sqlBuf;
                        sqlBuf << "INSERT INTO " << table << " VALUES(";
                        for (auto i = 0; i < row->fields_size(); i++)
                        {
                            sqlBuf << (i == 0 ? "" : ", ") << "?";
                        }
                        sqlBuf << ");";
                        string sql = sqlBuf.str();
                        cout << sql << endl;
                        statement = make_unique<SQLite::Statement>(db, sql);
                    }
                    for (auto i = 0; i < row->fields_size(); i++)
                    {
                        auto field = row->fields(i);
                        switch (field.value_case())
                        {
                        case faq::SQLiteField::kNull:
                            statement->bind(i + 1);
                            break;
                        case faq::SQLiteField::kInt:
                            statement->bind(i + 1, field.int_());
                            break;
                        case faq::SQLiteField::kInt64:
                            statement->bind(i + 1, field.int64());
                            break;
                        case faq::SQLiteField::kFloat:
                            statement->bind(i + 1, field.float_());
                            break;
                        case faq::SQLiteField::kString:
                            statement->bind(i + 1, field.string());
                            break;
                        case faq::SQLiteField::kBlob:
                            {
                                auto data = field.blob();
                                statement->bind(i + 1, data.c_str(), data.size());
                            }
                            break;
                        case faq::SQLiteField::VALUE_NOT_SET:
                            printf("%16s ", "NOT_SET");
                            statement->bind(i + 1);

                            break;
                        }
                    }

                    try
                    {
                        statement->exec();
                    }
                    catch (SQLite::Exception& ex)
                    {
                        printf("Insert failed: %s, ignored.\n", ex.what());
                    }
                    try
                    {
                        statement->reset();
                    }
                    catch (SQLite::Exception& ex)
                    {
                    }

                    statement->clearBindings();
                }

                db.exec("END TRANSACTION");
            }
        }
    }
    catch (exception& ex)
    {
        cerr << "Failed to dump" << endl;
        cerr << ex.what() << endl;
        throw ex;
    }
}

int DBDump::query(std::string sql)
{
    if (!client.send(sql))
        throw runtime_error("Failed to send sql");

    int result;
    if (!client.recv(result))
        throw runtime_error("Failed to send sql");
    return result;
}

std::unique_ptr<faq::SQLiteQueryRow> DBDump::nextRow()
{
    string data;
    if (!client.recv(data))
        throw runtime_error("Failed to recv sql");

    if (data.size() == 0)
        return unique_ptr<faq::SQLiteQueryRow>();

    auto row = make_unique<faq::SQLiteQueryRow>();
    row->ParseFromString(data);
    return row;
}

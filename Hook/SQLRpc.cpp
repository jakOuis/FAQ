#include "pch.h"
#include "SQLRpc.h"

#include <vector>



#include "faq_hook.pb.h"
#include "SQLiteQuery.h"
#include "Utils.h"

using namespace std;


struct FieldInfo
{
    string name;
    int type;
};

::grpc::Status SQLRpc::Query(::grpc::ServerContext* context, const ::faq::SQLiteQueryString* request, ::grpc::ServerWriter<::faq::SQLiteQueryRow>* writer)
{
    logf("Call to query");

    auto query = HookSQLite3Query();
    int result;
    db->execQuery(query.innerPtr, request->sql().c_str(), &result);
    int fieldCount = 0;
    bool firstRow = true;
    vector<string> fieldNames;

    logf("SQL: %s", request->sql().c_str());
    logf("Result: %d", result);
    if (result == SQLITE_ROW || result == SQLITE_OK)
    {
        while(!query.eof())
        {
            faq::SQLiteQueryRow resultRow;
            if(firstRow)
            {
                fieldCount = query.numFields();
                for(int i = 0; i < fieldCount; i ++)
                    fieldNames.push_back(string(query.fieldName(i)));
            }

            for(int idx = 0; idx < fieldCount; idx++)
            {
                auto resultField = resultRow.add_fields();
                
                if(firstRow)
                    resultField->set_name(fieldNames[idx]);
                auto type = query.fieldDataType(idx);
                switch (type)
                {
                    case SQLITE_INTEGER:
                        resultField->set_int_(query.getIntField(idx, 0));
                        break;
                    case SQLITE_BLOB:
                        {
                            int size;
                            auto buf = query.getBlobField(idx, &size);
                            resultField->set_blob(buf, size);
                            break;
                        }
                    case SQLITE_FLOAT:
                        resultField->set_float_(query.getFloatField(idx, 0));
                        break;
                    case SQLITE_TEXT:
                        {
                            int size;
                            auto buf = query.getStringField(idx, "");
                            resultField->set_string(buf);
                            break;
                        }
                    case SQLITE_NULL:
                        resultField->set_null(true);
                        break;
                    default:
                        resultField->set_null(false);
                }
            }

            firstRow = false;
            query.nextRow();
            writer->Write(resultRow);
        }
        
    }

    return grpc::Status::OK;
}

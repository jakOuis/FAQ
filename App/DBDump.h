#pragma once
#include <SQLiteCpp/SQLiteCpp.h>


#define FAQ_PROTOS __declspec(dllimport)
#include "TCPClient.h"
#include "faq_hook.grpc.pb.h"

class DBDump
{
public:
    SQLite::Database db;
    TCPClient client;
    std::string dbFile;
    DBDump(TCPClient client, std::string dbFile) :
        client(client),
        db(dbFile, SQLite::OPEN_CREATE | SQLite::OPEN_READWRITE) {}

    void dump();

    int query(std::string sql);
    std::unique_ptr<faq::SQLiteQueryRow> nextRow();    
    
};

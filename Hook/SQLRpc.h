#pragma once

#include "faq_hook.grpc.pb.h"
#include "SQLiteDB.h"
#include "TcpServer.h"

class SQLRpc
{
public:
    HookSQLite3DB* db;
    TcpServer server;
    SQLRpc(HookSQLite3DB* db): db(db), server("0.0.0.0", "47382"){}
    void serve();
    bool query(std::string sql);
    bool sendQueryRow(const faq::SQLiteQueryRow&  row);
};

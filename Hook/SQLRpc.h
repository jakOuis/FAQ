#pragma once

#include "TcpServer.h"
#include "faq_hook.grpc.pb.h"
#include "SQLiteDB.h"

class SQLRpc
{
public:
    static SQLRpc* _rpcInstance;
    
    HookSQLite3DB* db;
    TcpServer server;
    SQLRpc(HookSQLite3DB* db);
    ~SQLRpc();
    void serve();
    bool query(std::string sql);
    bool sendQueryRow(const faq::SQLiteQueryRow&  row);

    static SQLRpc * Get();
};

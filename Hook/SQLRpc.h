#pragma once

#include "faq_hook.grpc.pb.h"
#include "SQLiteDB.h"

class SQLRpc final : public faq::FaQSQLite::Service
{
public:
    HookSQLite3DB* db;
    SQLRpc(HookSQLite3DB* db) : db(db){}
    ::grpc::Status Query(::grpc::ServerContext* context, const ::faq::SQLiteQueryString* request,
        ::grpc::ServerWriter<::faq::SQLiteQuery>* writer) override;
};

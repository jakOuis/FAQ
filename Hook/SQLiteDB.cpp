#include "pch.h"
#include "SQLiteDB.h"
#include "Mutex.h"
#include <set>
#include <grpcpp/grpcpp.h>

#include "ModuleHook.h"
#include "SQLiteQuery.h"
#include "SQLRpc.h"
#include "Utils.h"


int SQLite3DB_execDML(void* self, const char* sql, int* error);
decltype(SQLite3DB_execDML)* OriginalSQLite3DB_execDML = nullptr;

int SQLite3DB_execQueryEx(void *self, int a2, char *sql, int *errOut, int a5);
decltype(SQLite3DB_execQueryEx)* OriginalSQLite3DB_execQueryEx = nullptr;

int SQLite3DB_open(void* self, const char *filename);
decltype(SQLite3DB_open)* OriginalSQLite3DB_open;

void SQLite3DB_key(void* self, const void *key, int a3);
decltype(SQLite3DB_key)* OriginalSQLite3DB_key;

void SQLite3DB_rekey(void* self, const void *key, int a3);
decltype(SQLite3DB_rekey)* OriginalSQLite3DB_rekey;

void SQLite3DB_execQuery(void* self, int a2, char *sql, int *a4);
decltype(SQLite3DB_execQuery)* OriginalSQLite3DB_execQuery;

static Mutex<std::set<void*>> SQLite3DBPointers = Mutex<std::set<void*>>(std::set<void*>());


void HookSQLite3DB::initHook(ModuleHook& hook)
{

    hook.begin();

    auto fn = &HookSQLite3DB::execDML;
    hook.hookFunc("SQLite3DB::execDML",
        "?execDML@CppSQLite3DB@@QAEHPBDPAH@Z",
        (void**)&OriginalSQLite3DB_execDML,
        (void*&)fn);

    auto fn2 = &HookSQLite3DB::execQueryEx;
    hook.hookFunc("SQLite3DB::execQueryEx",
        "?execQueryEx@CppSQLite3DB@@QAE?AVCppSQLite3Query@@PBDPAHH@Z",
        (void**)&OriginalSQLite3DB_execQueryEx,
        (void*&)fn2);

    auto fexecQuery = &HookSQLite3DB::execQuery;
    hook.hookFunc("SQLite3DB::execQuery",
        "?execQuery@CppSQLite3DB@@QAE?AVCppSQLite3Query@@PBDPAH@Z",
        (void**)&OriginalSQLite3DB_execQuery,
        (void*&)fexecQuery);

    auto fn3 = &HookSQLite3DB::open;
    hook.hookFunc("SQLite3DB::open",
        "?open@CppSQLite3DB@@QAEHPBD@Z",
        (void**)&OriginalSQLite3DB_open,
        (void*&)fn3);

    auto fkey = &HookSQLite3DB::key;
    hook.hookFunc("SQLite3DB::key",
        "?key@CppSQLite3DB@@QAEXPBXH@Z",
        (void**)&OriginalSQLite3DB_key,
        (void*&)fkey);

    auto frekey = &HookSQLite3DB::rekey;
    hook.hookFunc("SQLite3DB::rekey",
        "?rekey@CppSQLite3DB@@QAEXPBXH@Z",
        (void**)&OriginalSQLite3DB_rekey,
        (void*&)frekey);

    hook.commit();
}


int HookSQLite3DB::execDML(const char* sql, int* error)
{
    {
        auto guard = SQLite3DBPointers.lock();
        if (guard->find(this) != guard->end())
        {
            logf("Call to execDML %s", sql);
        }
    }
    int result;
    __asm {
        mov eax, error
        push eax
        mov eax, sql
        push eax
        mov ecx, this
        call OriginalSQLite3DB_execDML
        mov result, eax
        };

    return result;
    // return OriginalSQLite3DB_execDML(this, sql, error);
}

int HookSQLite3DB::execQueryEx(int a2, char* sql, int* a4, int a5)
{
    {
        auto guard = SQLite3DBPointers.lock();
        if (guard->find(this) != guard->end())
        {
            logf("Call to execQueryEx %s", sql);
        }
    }
    int result;
    __asm {
        mov eax, a5
        push eax
        mov eax, a4
        push eax
        mov eax, sql
        push eax
        mov eax, a2
        push eax
        mov ecx, this
        call OriginalSQLite3DB_execQueryEx
        mov result, eax
        };
    return result;
}

__declspec(dllexport) int HookSQLite3DB::execQuery(void* query, const char* sql, int* errOut)
{
    static bool queryed = false;

    {
        auto guard = SQLite3DBPointers.lock();
        if (guard->find(this) != guard->end())
        {
            logf("Call to execQuery %s", sql);
            if (!queryed)
            {
                queryed = true;

                SQLRpc service(this);
                grpc::ServerBuilder builder;
                builder.AddListeningPort("0.0.0.0:47382", grpc::InsecureServerCredentials());
                builder.RegisterService(&service);
                auto server = builder.BuildAndStart();

                logf("SQLite server listening on 0.0.0.0:47382");
                
                server->Wait();

                // HookSQLite3Query queryWrap = HookSQLite3Query();
                // int err;
                // auto result = this->execQuery(
                //     queryWrap.innerPtr,
                //     "SELECT * FROM 'group_665155905' ORDER BY Time DESC LIMIT 20;",
                //     &err);
                //
                // logf("query out %d, return %d, query %p", err, result, &queryWrap.innerPtr);
                // const uint8_t* valueBuf = nullptr;
                // char formatBuffer[16384];
                // bool firstLine = true;
                // while (!queryWrap.eof())
                // {
                //     logf("!eof");
                //     auto count = queryWrap.numFields();
                //     logf("Nums of row: %d", count);
                //     for (auto i = 0; i < count; i++)
                //     {
                //         auto type = queryWrap.fieldDataType(i);
                //         auto name = queryWrap.fieldName(i);
                //         switch (type)
                //         {
                //         case SQLITE_INTEGER:
                //             logf("%s Int: %d", name, queryWrap.getIntField(i, -1));
                //             break;
                //         case SQLITE_FLOAT:
                //             logf("%s Float: %lf", name, queryWrap.getFloatField(i, -1));
                //             break;
                //         case SQLITE_TEXT:
                //             logf("%s String: %s", name, queryWrap.getStringField(i, "<?null>"));
                //             break;
                //         case SQLITE_BLOB:
                //             {
                //                 int size;
                //                 valueBuf = queryWrap.getBlobField(i, &size);
                //                 logf("%s Blob(%d)", name, size);
                //                 // auto ptr = formatBuffer;
                //                 // for(int j=0;j<size; j+= 4)
                //                 // {
                //                 //     unsigned int hex = *(int*)(valueBuf+ j);
                //                 //     ptr += sprintf_s(ptr,
                //                 //         16384 - (ptr - formatBuffer),
                //                 //         "%02x%02x%02x%02x",
                //                 //         (hex & 0xFF) >> 0,
                //                 //         (hex & 0xFF00) >> 8,
                //                 //         (hex & 0xFF0000) >> 16,
                //                 //         (hex & 0xFF000000) >> 24);
                //                 // }
                //                 // log((const char*)valueBuf, size);
                //                 // log(formatBuffer, size * 2);
                //                 // valueBuf += 4 *8;
                //                 // logf("%08x %08x %08x %08x  %08x %08x %08x %08x",
                //                 //     ((int*)valueBuf)[0],((int*)valueBuf)[1],((int*)valueBuf)[2],((int*)valueBuf)[3],
                //                 //     ((int*)valueBuf)[4],((int*)valueBuf)[5],((int*)valueBuf)[6],((int*)valueBuf)[7]);
                //                 break;
                //             }
                //         case SQLITE_NULL:
                //             logf("%s Null", name);
                //             break;
                //         default:
                //             logf("%s Unknown type", name);
                //         }
                //     }
                //     return 0;
                //
                //     // Sleep(1000);
                //
                //     queryWrap.nextRow();
                // }
                //
                // return 0;
            }
        }
    }
    int result;
    __asm {
        mov eax, errOut
        push eax
        mov eax, sql
        push eax
        mov eax, query
        push eax
        mov ecx, this
        call OriginalSQLite3DB_execQuery
        mov result, eax
        };
    return result;
}

int HookSQLite3DB::open(const char* filename)
{
    logf("Call to open %s", filename);
    auto basename = Utils::PathBaseName(std::string(filename));
    if (basename == "Msg3.0.db")
    {
        logf("Got Msg3.0.db");
        {
            auto guard = SQLite3DBPointers.lock();
            guard->insert(this);
        }
        logf("Added to collection");
    }
    int result;
    __asm {
        mov eax, filename
        push eax
        mov ecx, this
        call OriginalSQLite3DB_open
        mov result, eax
        };
    return result;
}

void HookSQLite3DB::key(const void* key, int a3)
{
    logf("Call to key %p %x", key, a3);
    {
        auto guard = SQLite3DBPointers.lock();
        if (guard->find(this) != guard->end())
        {
        }
    }
    __asm {
        mov eax, a3
        push eax
        mov eax, key
        push eax
        mov ecx, this
        call OriginalSQLite3DB_key
        }
}

void HookSQLite3DB::rekey(const void* key, int a3)
{
    logf("Call to rekey %p %x", key, a3);
    {
        auto guard = SQLite3DBPointers.lock();
        if (guard->find(this) != guard->end())
        {
        }
    }
    __asm {
        mov eax, a3
        push eax
        mov eax, key
        push eax
        mov ecx, this
        call OriginalSQLite3DB_rekey
        }
}

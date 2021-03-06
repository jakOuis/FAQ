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

const char* SQLite3DB_db_filename(void* self, const char* dbName);
decltype(SQLite3DB_db_filename)* OriginalSQLite3DB_db_filename;

void SQLite3DB_close(void* self);
decltype(SQLite3DB_close)* OriginalSQLite3DB_close;

static Mutex<std::set<void*>> SQLite3DBPointers = Mutex<std::set<void*>>(std::set<void*>());

static Mutex<bool> MsgDBFound = Mutex<bool>(false);

static std::unique_ptr<Mutex<bool>> DBLock = std::make_unique<Mutex<bool>>(false);

void setupShell(HookSQLite3DB* db);


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
        
    auto dbName = &HookSQLite3DB::db_filename;
    hook.hookFunc("SQLite3DB::db_name",
        "?db_filename@CppSQLite3DB@@QAEPBDPBD@Z",
        (void**)&OriginalSQLite3DB_db_filename,
        (void*&)dbName);

    auto close = &HookSQLite3DB::close;
    hook.hookFunc("SQLite3DB::close",
        "?close@CppSQLite3DB@@QAEXXZ",
        (void**)&OriginalSQLite3DB_close,
        (void*&)close);

    hook.commit();
}


int HookSQLite3DB::execDML(const char* sql, int* error)
{
    // logFmt("Call to execDML %s", sql);
    if(DBLock)
        DBLock->lock();
    
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
}

int HookSQLite3DB::execQueryEx(int a2, char* sql, int* a4, int a5)
{
    if(DBLock)
        DBLock->lock();
    // logFmt("Call to execQueryEx %s", sql);
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
    if(DBLock)
        DBLock->lock();
    // logFmt("Call to execQuery %s", sql);
    bool dbFound = false;
    {
        auto guard = MsgDBFound.lock();
        if(!*guard)
        {
            auto filename = this->db_filename("main");
            auto basename = Utils::PathBaseName(std::string(filename));
            logFmt("db_filename: %s", basename.c_str());
            if (basename == "Msg3.0.db")
            {
                logFmt("Got Msg3.0.db");

                *guard = true;
                dbFound = true;
            }
        }
    }
    if(dbFound)
        setupShell(this);
    
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

const char* HookSQLite3DB::db_filename(const char* dbName)
{
    if(DBLock)
        DBLock->lock();
    const char* result;
    __asm {
        push dbName
        mov ecx, this
        call OriginalSQLite3DB_db_filename
        mov result, eax
    }
    return result;
}


int HookSQLite3DB::open(const char* filename)
{
    if(DBLock)
        DBLock->lock();
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
    if(DBLock)
        DBLock->lock();
    logFmt("Call to key %p %x", key, a3);
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
    if(DBLock)
        DBLock->lock();
    logFmt("Call to rekey %p %x", key, a3);
    __asm {
        mov eax, a3
        push eax
        mov eax, key
        push eax
        mov ecx, this
        call OriginalSQLite3DB_rekey
        }
}

void HookSQLite3DB::close()
{
    auto filename = this->db_filename("main");
    auto basename = Utils::PathBaseName(std::string(filename));
    if(basename == "Msg3.0.db")
    {
        logFmt("Attempt to close msg db.");
        DBLock->lock();
    }
    __asm {
        mov ecx, this
        call OriginalSQLite3DB_close
    }
}



void setupShell(HookSQLite3DB* db)
{
    auto guard = DBLock->lock();
    SQLRpc service(db);
                
    logFmt("server start on 0.0.0.0:47382");
    service.serve();

    logFmt("Server down");
}

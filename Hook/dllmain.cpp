// dllmain.cpp : Defines the entry point for the DLL application.
#include "pch.h"

#include <psapi.h>

#include "header.h"
#include "Utils.h"
#include <stdio.h>
#include <winsock.h>
#include <string>
#include <detours.h>
#include <set>


#include "ModuleHook.h"
#include "Mutex.h"
#include "SQLiteQuery.h"

#pragma comment(lib,"ws2_32.lib") //Winsock Library
#pragma comment(lib,"ntdll.lib") //Winsock Library

DWORD WINAPI thread_func(LPVOID lpParam);
void log(std::string text);
bool loaded = false;

BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
                     )
{
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
        log("dll process attach");
        break;
    case DLL_THREAD_ATTACH:
        log("dll thread attach");
        break;
    case DLL_THREAD_DETACH:
        log("dll thread detach");
        break;
    case DLL_PROCESS_DETACH:
        log("dll process detach");
        break;
    }
    
    if(loaded)
        return TRUE;
    loaded = true;
    
    init_logger();
    
    
    DWORD thread_id;
    CreateThread(
        nullptr,
        0,
        thread_func,
        nullptr,
        0,
        &thread_id
    );

    auto pid = GetCurrentProcessId();
    printf("pid: %d\n", pid);
    printf("Create thread %d\n", thread_id);


    return TRUE;
}

static Mutex<std::set<void*>> SQLite3DBPointers = Mutex<std::set<void*>>(std::set<void*>());

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


__declspec(dllexport) class HookSQLite3DB
{
public:
    void* sqlite;
    int execDML(const char* sql, int* error)
    {
        {
            auto guard = SQLite3DBPointers.lock();
            if(guard->find(this) != guard->end())
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
    int execQueryEx(int a2, char *sql, int *a4, int a5)
    {
        {
            auto guard = SQLite3DBPointers.lock();
            if(guard->find(this) != guard->end())
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
    __declspec(dllexport) int execQuery(void* query, const char *sql, int *errOut)
    {
        static bool queryed = false;
        {
            auto guard = SQLite3DBPointers.lock();
            if(guard->find(this) != guard->end())
            {
                logf("Call to execQuery %s", sql);
                if(!queryed)
                {
                    queryed = true;

                    char query[8192];
                    int err;
                    auto result = this->execQuery(&query, "SELECT * FROM 'group_665155905' limit 10", &err);
                    logf("query out %d, return %d, query %p", err, result, &query);
                    auto queryWrap = HookSQLite3Query(&query);
                    const uint8_t* valueBuf = nullptr;
                    while(!queryWrap.eof())
                    {
                        logf("!eof");
                        auto count = queryWrap.numFields();
                        logf("Nums of row: %d", count);
                        for(auto i = 0; i < count; i++)
                        {
                            auto type = queryWrap.fieldDataType(i);
                            switch(type)
                            {
                                case SQLITE_INTEGER:
                                    logf("Int: %d", queryWrap.getIntField(i, -1));
                                    break;
                                case SQLITE_FLOAT:
                                    logf("Float: %lf", queryWrap.getFloatField(i, -1));
                                    break;
                                case SQLITE_TEXT:
                                    logf("String: %s", queryWrap.getStringField(i, "<?null>"));
                                    break;
                                case SQLITE_BLOB:
                                    int size;
                                    valueBuf = queryWrap.getBlobField(i, &size);
                                    logf("Blob:");
                                    log((const char *)valueBuf, size);
                                    break;
                                case SQLITE_NULL:
                                    logf("Null");
                                    break;
                                default:
                                    logf("Unknown type");
                            }
                            
                        }

                        Sleep(1000);
                    
                        queryWrap.nextRow();
                    }
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
    int open(const char* filename)
    {
        logf("Call to open %s", filename);
        auto basename = Utils::PathBaseName(std::string(filename));
        if(basename == "Msg3.0.db")
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
    void key(const void *key, int a3)
    {
         logf("Call to key %p %x", key, a3);
        {
            auto guard = SQLite3DBPointers.lock();
            if(guard->find(this) != guard->end())
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
    void rekey(const void *key, int a3)
    {
        logf("Call to rekey %p %x", key, a3);
        {
            auto guard = SQLite3DBPointers.lock();
            if(guard->find(this) != guard->end())
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
};

DWORD WINAPI thread_func(LPVOID lpParam)
{
    auto processName = Utils::GetProcessName(GetCurrentProcessId());
    logf("%ls", processName.c_str());
    if(processName != TEXT("QQ.exe") && processName != TEXT("TIM.exe"))
        return 0;

    logf("start hook");

    ModuleHook hook("KernelUtil.dll");

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

    HookSQLite3Query::initLib(hook.hMod);

    return 0;
}

__declspec(dllexport) LRESULT hook_func(int nCode, WPARAM wParam, LPARAM lParam)
{
    return 0;
}
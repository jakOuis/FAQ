// dllmain.cpp : Defines the entry point for the DLL application.
#include "pch.h"

#include <psapi.h>

#include "header.h"
#include "Utils.h"
#include <stdio.h>
#include <winsock.h>
#include <string>
#include <detours.h>

#include "ModuleHook.h"

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

int SQLite3DB_execDML(void* self, const char* sql, int* error);
decltype(SQLite3DB_execDML)* OriginalSQLite3DB_execDML = nullptr;

int SQLite3DB_execQueryEx(void *self, int a2, char *sql, int *errOut, int a5);
decltype(SQLite3DB_execQueryEx)* OriginalSQLite3DB_execQueryEx = nullptr;

__declspec(dllexport) class HookSQLite3DB
{
public:
    void* sqlite;
    int execDML(const char* sql, int* error)
    {
        logf("Call to execDM %s", sql);
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
        logf("Call to execQueryEx %s", sql);
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

    hook.commit();
    

    return 0;
}

__declspec(dllexport) LRESULT hook_func(int nCode, WPARAM wParam, LPARAM lParam)
{
    return 0;
}
// dllmain.cpp : Defines the entry point for the DLL application.
#include "pch.h"

#include <psapi.h>

#include "header.h"

#include <stdio.h>
#include <winsock.h>
#include <string>
#include <detours.h>
#include <set>


#include "ModuleHook.h"
#include "Mutex.h"
#include "SQLiteDB.h"
#include "SQLiteQuery.h"
#include "SQLRpc.h"
#include "Utils.h"

#pragma comment(lib,"ws2_32.lib") //Winsock Library
#pragma comment(lib,"ntdll.lib") //Winsock Library

DWORD WINAPI thread_func(LPVOID lpParam);
void log(std::string text);
bool loaded = false;

void* _malloc(size_t size);

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
        if(SQLRpc::Get())
            SQLRpc::Get()->server.close();
        if(ModuleHook::Get())
            delete ModuleHook::Get();
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




DWORD WINAPI thread_func(LPVOID lpParam)
{
    auto processName = Utils::GetProcessName(GetCurrentProcessId());
    logFmt("%ls", processName.c_str());
    if(processName != TEXT("QQ.exe") && processName != TEXT("TIM.exe"))
        return 0;

    logFmt("start hook");

    auto hook = new ModuleHook("KernelUtil.dll");

    HookSQLite3DB::initHook(*hook);

    HookSQLite3Query::initLib(hook->hMod);

    return 0;
}

__declspec(dllexport) LRESULT hook_func(int nCode, WPARAM wParam, LPARAM lParam)
{
    return 0;
}
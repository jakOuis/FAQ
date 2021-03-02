// dllmain.cpp : Defines the entry point for the DLL application.
#include "pch.h"

#include <psapi.h>

#include "header.h"
#include "Utils.h"
#include <stdio.h>
#include <winsock.h>
#include <string>

#pragma comment(lib,"ws2_32.lib") //Winsock Library

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

DWORD WINAPI thread_func(LPVOID lpParam)
{
    auto processName = Utils::GetProcessName(GetCurrentProcessId());
    logf("%ls", processName.c_str());
    if(processName != TEXT("QQ.exe") && processName != TEXT("TIM.exe"))
        return 0;

    

    logf("start hook");

    auto hProcess = GetCurrentProcess();
    if (NULL == hProcess)
        return 1;

    // Get a list of all the modules in this process.

    HMODULE hMods[1024];
    DWORD count;
    
    if( EnumProcessModules(hProcess, hMods, sizeof(hMods), &count))
    {
        for (size_t i = 0; i < (count / sizeof(HMODULE)); i++ )
        {
            TCHAR szModName[MAX_PATH];

            // Get the full path to the module's file.

            if ( GetModuleBaseName( hProcess, hMods[i], szModName,
                                      sizeof(szModName) / sizeof(TCHAR)))
            {
                // Print the module name and handle value.

                logf("%ls", szModName);
            }
        }
    }
    
    // Release the handle to the process.

    CloseHandle( hProcess );

    auto module = GetModuleHandleA("KernelUtil.dll");
    logf("KernelUtils: %p", module);
    if(module == NULL)
    {
        log_error("Invalid HMODULE");
        return 0;
    }

    auto execDML = GetProcAddress(module, "?execDML@CppSQLite3DB@@QAEHPBDPAH@Z");
    logf("SQLite3DB::execDML: %p", execDML);
    if(execDML == NULL)
        return 0;

    return 0;
}

__declspec(dllexport) LRESULT hook_func(int nCode, WPARAM wParam, LPARAM lParam)
{
    return 0;
}
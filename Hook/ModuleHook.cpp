#include "pch.h"
#include "ModuleHook.h"

#include "Utils.h"
#include <detours.h>

ModuleHook::ModuleHook(const char* moduleName)
{
    hMod = GetModuleHandleA("KernelUtil.dll");
    logf("Get Module %s at %p", moduleName, hMod);
    if(hMod == nullptr)
    {
        log_error("Invalid HMODULE");
    }
}

void ModuleHook::begin()
{
    DetourTransactionBegin();
}

void ModuleHook::commit()
{
    const auto err = DetourTransactionCommit();
    if(err != NO_ERROR)
    {
        logf("Failed to commit detour");
        switch(err)
        {
        case ERROR_INVALID_DATA:
            logf("ERROR_INVALID_DATA");
            break;
        case ERROR_INVALID_OPERATION:
            logf("ERROR_INVALID_OPERATION");
            break;
        default:
            logf("Unknown error: %d", err);
        }
    }
    logf("Detour transaction successfully committed");
}

void ModuleHook::hookFunc(const char* name, PVOID* originalFunc, void*& hookFunc)
{
    auto funcAddr = GetProcAddress(hMod, "?execDML@CppSQLite3DB@@QAEHPBDPAH@Z");
    logf("SQLite3DB::execDML: %p", funcAddr);
    if(funcAddr == NULL)
    {
        logf("Get null of function %s", name);
    }

    DetourTransactionBegin();
    logf("Try hook SQLite3DB::execDML");
    *originalFunc = (void*)funcAddr;
    auto err = DetourAttach(originalFunc, hookFunc);
    if(err != NO_ERROR)
    {
        logf("Failed to detour");
        switch(err)
        {
        case ERROR_INVALID_BLOCK:
            logf("ERROR_INVALID_BLOCK");
            break;
        case ERROR_INVALID_HANDLE:
            logf("ERROR_INVALID_HANDLE");
            break;
        case ERROR_INVALID_OPERATION:
            logf("ERROR_INVALID_OPERATION");
            break;
        case ERROR_NOT_ENOUGH_MEMORY:
            logf("ERROR_NOT_ENOUGH_MEMORY");
            break;
        default:
            logf("Unknown error: %d", err);
        }
    }
}

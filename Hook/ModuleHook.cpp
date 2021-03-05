#include "pch.h"
#include "ModuleHook.h"

#include <detours.h>
#include "Utils.h"

ModuleHook* ModuleHook::_modHookInstance;

ModuleHook::ModuleHook(const char* moduleName)
{
    hMod = GetModuleHandleA("KernelUtil.dll");
    logFmt("Get Module %s at %p", moduleName, hMod);
    if(hMod == nullptr)
    {
        log_error("Invalid HMODULE");
    }
    _modHookInstance = this;
}
ModuleHook::~ModuleHook()
{
    DetourTransactionBegin();

    for(auto& hook : hooks)
    {
        DetourDetach(hook.originalFuncPtr, hook.hookFunc);
    }

    DetourTransactionCommit();

    logFmt("Detached hooks");
    
    _modHookInstance = nullptr;
}

ModuleHook* ModuleHook::Get()
{
    return _modHookInstance;
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
        logFmt("Failed to commit detour");
        switch(err)
        {
        case ERROR_INVALID_DATA:
            logFmt("ERROR_INVALID_DATA");
            break;
        case ERROR_INVALID_OPERATION:
            logFmt("ERROR_INVALID_OPERATION");
            break;
        default:
            logFmt("Unknown error: %d", err);
        }
    }
    logFmt("Detour transaction successfully committed");
}

void ModuleHook::hookFunc(const char* logName, const char* name, PVOID* originalFunc, void* hookFunc)
{
    auto funcAddr = GetProcAddress(hMod, name);
    logFmt("%s: %p", logName, funcAddr);
    if(funcAddr == NULL)
    {
        logFmt("Get null of function %s", name);
    }

    DetourTransactionBegin();
    logFmt("Try hook %s", logName);
    *originalFunc = (void*)funcAddr;
    auto err = DetourAttach(originalFunc, hookFunc);
    if(err != NO_ERROR)
    {
        logFmt("Failed to detour");
        switch(err)
        {
        case ERROR_INVALID_BLOCK:
            logFmt("ERROR_INVALID_BLOCK");
            break;
        case ERROR_INVALID_HANDLE:
            logFmt("ERROR_INVALID_HANDLE");
            break;
        case ERROR_INVALID_OPERATION:
            logFmt("ERROR_INVALID_OPERATION");
            break;
        case ERROR_NOT_ENOUGH_MEMORY:
            logFmt("ERROR_NOT_ENOUGH_MEMORY");
            break;
        default:
            logFmt("Unknown error: %d", err);
        }
    }
    else
    {
        hooks.push_back({
            originalFunc,
            hookFunc
        });
    }
}

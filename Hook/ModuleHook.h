#pragma once

#include <vector>

struct HookInfo
{
    void** originalFuncPtr;
    void* hookFunc;
};

class ModuleHook
{
public:
    HMODULE hMod;
    std::vector<HookInfo> hooks;

    ModuleHook(const char* moduleName);
    ~ModuleHook();

    static ModuleHook* Get();

    void begin();

    void commit();

    void hookFunc(const char* logName, const char* name, PVOID* originalFunc, void* hookFunc);
private:
    static ModuleHook* _modHookInstance;
};

#pragma once

class ModuleHook
{
public:
    HMODULE hMod;

    ModuleHook(const char* moduleName);

    void begin();

    void commit();

    void hookFunc(const char* logName, const char* name, PVOID* originalFunc, void* hookFunc);
};

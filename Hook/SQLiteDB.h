#pragma once
#include "ModuleHook.h"

__declspec(dllexport) class HookSQLite3DB
{
public:
    void* sqlite;
    static void initHook(ModuleHook& hook);
    int execDML(const char* sql, int* error);
    int execQueryEx(int a2, char *sql, int *a4, int a5);
    __declspec(dllexport) int execQuery(void* query, const char *sql, int *errOut);
    int open(const char* filename);
    void key(const void *key, int a3);
    void rekey(const void *key, int a3);
};

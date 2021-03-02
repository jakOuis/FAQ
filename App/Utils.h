#pragma once

#include <cstdio>
#include <Windows.h>
#include <strsafe.h>
#include <TlHelp32.h>
#include <vector>
#include <string>
#include <map>


struct ProcessInfo
{
    std::wstring processName;
    DWORD pid;
    std::vector<DWORD> threads;

    ProcessInfo(): pid(0), processName(TEXT("unknown")) {}
    ProcessInfo(DWORD pid);
};


std::map<DWORD, ProcessInfo> get_process_info();
void print_error(const char * msg);
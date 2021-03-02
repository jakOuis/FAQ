// App.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <cstdio>
#include <Windows.h>
#include <strsafe.h>
#include <TlHelp32.h>
#include <vector>

#include "Utils.h"

int main()
{
    auto dll = LoadLibrary(TEXT("Hook.dll"));
    if (!dll)
    {
        print_error("Faied to load dll");
        return -1;
    }
    printf("Load Hook.dll (%p)", dll);
    auto procAddr = (HOOKPROC)GetProcAddress(dll, "hook_func");
    if(!procAddr)
    {
        print_error("Failed to get hook_func addr");
        return -1;
    }
    printf("Get hook_func (%p)", procAddr);

    auto processInfo = get_process_info();
    for(auto& p: processInfo)
    {
        if(p.second.processName != TEXT("TIM.exe") && p.second.processName != TEXT("QQ.exe"))
            continue;
        printf("[%ld] %ls: \n", p.second.pid, p.second.processName.c_str());

        int count = 0;
        for(auto & threadId : p.second.threads)
        {
            if(++count > 3)
            {
                printf("...\n");
                break;
            }
            printf("\t%ld\n", threadId);
        }
    }
    DWORD hookThread = 0;
    printf("Hook ThreadID >");
    std::cin >> hookThread;
    
    auto hook = SetWindowsHookEx(WH_MSGFILTER, procAddr, dll, hookThread);
    if (!hook)
    {
        print_error("Failed to set hook");
        return -1;
    }
    printf("Hooked.\n");

    while (true)
    {
        getchar();
    }
}


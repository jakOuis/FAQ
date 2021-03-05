// App.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "TCPClient.h"
#include <iostream>
#include <cstdio>
#include <Windows.h>
#include <strsafe.h>
#include <TlHelp32.h>
#include <vector>
#include <grpcpp/grpcpp.h>
#include <grpcpp/impl/codegen/client_context.h>


#define FAQ_PROTOS __declspec(dllimport)

#include "faq_hook.grpc.pb.h"
#include "faq_hook.pb.h"
#include "Utils.h"

#pragma comment(lib, "Ws2_32.lib")

using namespace std;

void sqlShell(TCPClient client);

int main()
{
    auto dll = LoadLibrary(TEXT("Hook.dll"));
    if (!dll)
    {
        print_error("Faied to load dll");
        return -1;
    }
    printf("Load Hook.dll (%p)\n", dll);
    auto procAddr = (HOOKPROC)GetProcAddress(dll, "hook_func");
    if(!procAddr)
    {
        print_error("Failed to get hook_func addr");
        return -1;
    }
    printf("Get hook_func (%p)", procAddr);

    while(true)
    {
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
        
        char buf[1024];
        printf("Hook ThreadID>");
        cin.getline(buf, sizeof(buf));
        
        if(strlen(buf) <= 0)
            continue;
        
        sscanf_s(buf,  "%d", &hookThread);
        auto hook = SetWindowsHookEx(WH_MSGFILTER, procAddr, dll, hookThread);
        if (!hook)
        {
            print_error("Failed to set hook");
            continue;
        }
        
        break;
    }
    
    printf("Hooked.\n");

    TCPClient client;
    while(true)
    {
        do
        {
            printf("Connecting to hook sql server...\n");
        } while(!client.connect("localhost", "47382"));
        
        sqlShell(client);
    }
}

void sqlShell(TCPClient client)
{
    char buf[1024];
    while (true)
    {
        do
        {
            cout << "sql>";
            cin.getline(buf, sizeof(buf));
        } while(strlen(buf) <= 0);
        
        auto sql = string(buf);
        if(!client.send(sql))
            return;

        int result;
        if(!client.recv<int>(result))
            return;

        printf("Execute with result %d\n", result);
        
        bool firstRow = true;
        while(true)
        {
            string raw;
            if(!client.recv(raw))
                return;
            if(raw.size() == 0)
            {
                printf("<EOF>\n");
                break;
            }
            
            faq::SQLiteQueryRow row;
            row.ParseFromString(raw);

            
            if(firstRow)
            {
                for(auto& field :row.fields())
                {
                    printf("%16s ", field.name().c_str());
                }
                printf("\n");
                
                for(auto& field :row.fields())
                {
                    for(auto i = 0; i < 16; i++)
                    {
                        printf("-");
                    }
                    printf(" ");
                }
                printf("\n");
            }
            for(auto field : row.fields())
            {
                char formatBuf[1024];
                size_t length;
                switch(field.value_case())
                {
                    case faq::SQLiteField::kNull:
                        printf("%16s ", field.null() ? "NULL": "UNKNOWN");
                        break;
                    case faq::SQLiteField::kInt:
                        printf("%16d ", field.int_());
                        break;
                    case faq::SQLiteField::kInt64:
                        printf("%16lld ", field.int64());
                        break;
                    case faq::SQLiteField::kFloat:
                        printf("%16lf ", field.float_());
                        break;
                    case faq::SQLiteField::kString:
                        printf("%16s ", field.string().c_str());
                        break;
                    case faq::SQLiteField::kBlob:
                        length = sprintf_s(formatBuf, sizeof(formatBuf), "Blob(%d)", field.blob().size());
                        formatBuf[length] = 0;
                        printf("%16s ", formatBuf);
                        break;
                case faq::SQLiteField::VALUE_NOT_SET:
                    printf("%16s ", "NOT_SET");
                    break;
                }
            }
            printf("\n");
            
            firstRow = false;
        }
    }
}



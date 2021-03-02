// dllmain.cpp : Defines the entry point for the DLL application.
#include "pch.h"
#include "header.h"
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

SOCKET SendSocket = INVALID_SOCKET;
sockaddr_in RecvAddr;

#define logf(...) \
    if(SendSocket != INVALID_SOCKET) \
    { \
        char buf[1024]; \
        sprintf_s(buf, sizeof(buf), __VA_ARGS__); \
        char fmt_buf[1024]; \
        sprintf_s(fmt_buf, sizeof(fmt_buf), "[%d] %s", GetCurrentProcessId(), buf); \
        sendto(SendSocket,fmt_buf, strlen(fmt_buf), 0, (SOCKADDR*)&RecvAddr, sizeof(RecvAddr)); \
    }


void log(std::string text)
{
    logf("%s", text.c_str());
}

void init_logger()
{
    int iResult;
        WSADATA wsaData;
        unsigned short Port = 47381;
    
        char SendBuf[1024];
        int BufLen = 1024;
    
        //----------------------
        // Initialize Winsock
        iResult = WSAStartup(MAKEWORD(2, 2), &wsaData);
        if (iResult != NO_ERROR) {
            wprintf(L"WSAStartup failed with error: %d\n", iResult);
            return ;
        }
    
        //---------------------------------------------
        // Create a socket for sending data
        SendSocket = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
        if (SendSocket == INVALID_SOCKET) {
            wprintf(L"socket failed with error: %ld\n", WSAGetLastError());
            WSACleanup();
            return ;
        }
        //---------------------------------------------
        // Set up the RecvAddr structure with the IP address of
        // the receiver (in this example case "192.168.1.1")
        // and the specified port number.
        RecvAddr.sin_family = AF_INET;
        RecvAddr.sin_port = htons(Port);
        RecvAddr.sin_addr.s_addr = inet_addr("127.0.0.1");
    
        while (true)
        {
            log("Initialize udp logger.");
    
            return ;
            Sleep(10000);
        }
        //---------------------------------------------
        // Send a datagram to the receiver
        //---------------------------------------------
        // When the application is finished sending, close the socket.
        wprintf(L"Finished sending. Closing socket.\n");
        iResult = closesocket(SendSocket);
        if (iResult == SOCKET_ERROR) {
            wprintf(L"closesocket failed with error: %d\n", WSAGetLastError());
            WSACleanup();
            return ;
        }
        //---------------------------------------------
        // Clean up and quit.
        wprintf(L"Exiting.\n");
        WSACleanup();
        return ;
}


DWORD WINAPI thread_func(LPVOID lpParam)
{
    init_logger();

    logf("start hook");

    auto module = GetModuleHandleA("KernelUtils.dll");
    logf("KernelUtils: %p", module);
    if(module == NULL)
        return 0;

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
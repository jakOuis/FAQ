#include "pch.h"
#include "Utils.h"

#include <psapi.h>
#include <strsafe.h>
#include <vector>
#include <winsock.h>

using namespace Utils;

std::wstring Utils::GetProcessName(DWORD pid)
{
    TCHAR nameBuf[MAX_PATH] = TEXT("<unknown>");
    if (auto process = OpenProcess(PROCESS_QUERY_INFORMATION | PROCESS_VM_READ, false, pid))
    {
        HMODULE hMod;
        DWORD cbNeeded;
        if (EnumProcessModules(process, &hMod, sizeof(hMod), &cbNeeded))
        {
            GetModuleBaseName(process, hMod, nameBuf, sizeof(nameBuf) / sizeof(TCHAR));
            return std::wstring(nameBuf);
        }
    }
}

std::string Utils::PathBaseName(std::string path)
{
    return path.substr(path.find_last_of("/\\")  + 1);
}

std::vector<std::wstring> list_module_names()
{
    std::vector<std::wstring> list;
    HMODULE hMods[1024];
    DWORD count;
    
    auto hProcess = GetCurrentProcess();
    if (NULL == hProcess)
        return list;
    
    
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
                list.push_back(std::wstring(szModName));
            }
        }
    }
    
    // Release the handle to the process.

    CloseHandle( hProcess );
    return list;
}


void log(std::string text)
{
    logf("%s", text.c_str());
}

static SOCKET SendSocket = INVALID_SOCKET;
static sockaddr_in RecvAddr;
static HANDLE LogMutex;

void log(const char* str, size_t len)
{
    if(SendSocket == INVALID_SOCKET)
        return;
    auto recv_addr = RecvAddr;
    sendto(SendSocket, str, len, 0, (SOCKADDR*)&recv_addr, sizeof(RecvAddr));
}

bool init_logger()
{

    if(SendSocket != INVALID_SOCKET)
        return true;

    LogMutex = CreateMutex(nullptr, false, nullptr);
    
    int iResult;
    WSADATA wsaData;
    unsigned short Port = 47381;

    char SendBuf[1024];
    int BufLen = 1024;

    //----------------------
    // Initialize Winsock
    iResult = WSAStartup(MAKEWORD(2, 2), &wsaData);
    if (iResult != NO_ERROR)
    {
        wprintf(L"WSAStartup failed with error: %d\n", iResult);
        return false;
    }

    //---------------------------------------------
    // Create a socket for sending data
    SendSocket = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
    if (SendSocket == INVALID_SOCKET)
    {
        wprintf(L"socket failed with error: %ld\n", WSAGetLastError());
        WSACleanup();
        return false;
    }
    //---------------------------------------------
    // Set up the RecvAddr structure with the IP address of
    // the receiver (in this example case "192.168.1.1")
    // and the specified port number.
    RecvAddr.sin_family      = AF_INET;
    RecvAddr.sin_port        = htons(Port);
    RecvAddr.sin_addr.s_addr = inet_addr("127.0.0.1");

    
    log("Initialize udp logger.");

    // return true;
    
    while (true)
    {
        log("Initialize udp logger.");
    
        return true;
        Sleep(10000);
    }
    // //---------------------------------------------
    // // Send a datagram to the receiver
    // //---------------------------------------------
    // // When the application is finished sending, close the socket.
    // wprintf(L"Finished sending. Closing socket.\n");
    // iResult = closesocket(SendSocket);
    // if (iResult == SOCKET_ERROR)
    // {
    //     wprintf(L"closesocket failed with error: %d\n", WSAGetLastError());
    //     WSACleanup();
    //     return;
    // }
    // //---------------------------------------------
    // // Clean up and quit.
    // wprintf(L"Exiting.\n");
    // WSACleanup();
    // return;
}

void log_error(const char* msg)
{
    LPSTR lpMsgBuf;
    LPSTR lpDisplayBuf;
    DWORD dw = GetLastError();

    FormatMessage(
        FORMAT_MESSAGE_ALLOCATE_BUFFER |
        FORMAT_MESSAGE_FROM_SYSTEM |
        FORMAT_MESSAGE_IGNORE_INSERTS,
        NULL,
        dw,
        MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT),
        (LPTSTR)&lpMsgBuf,
        0,
        NULL);

    // Display the error message and exit the process

    auto len = (lstrlen((LPCTSTR)lpMsgBuf) + strlen(msg) + 128) * sizeof(TCHAR);
    lpDisplayBuf = (LPSTR)LocalAlloc(
        LMEM_ZEROINIT,
        len);

    sprintf_s(lpDisplayBuf, len, "%s: %d: %s", msg, dw, lpMsgBuf);

    log(lpDisplayBuf, strlen(lpDisplayBuf));

    LocalFree(lpMsgBuf);
    LocalFree(lpDisplayBuf);
}

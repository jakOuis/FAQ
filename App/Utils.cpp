#include "Utils.h"

#include <psapi.h>
#include <string>

std::map<DWORD, ProcessInfo> get_process_info()
{
    HANDLE hThreadSnap = INVALID_HANDLE_VALUE;
    THREADENTRY32 te32;
    
    auto process_map = std::map<DWORD, ProcessInfo>();

    // Take a snapshot of all running threads  
    hThreadSnap = CreateToolhelp32Snapshot(TH32CS_SNAPTHREAD, 0);
    if (hThreadSnap == INVALID_HANDLE_VALUE)
        return process_map;

    // Fill in the size of the structure before using it. 
    te32.dwSize = sizeof(THREADENTRY32);

    // Retrieve information about the first thread,
    // and exit if unsuccessful
    if (!Thread32First(hThreadSnap, &te32))
    {
        print_error("Failed to retrieve thread info");
        
        CloseHandle(hThreadSnap); // Must clean up the snapshot object!
        return process_map;
    }

    // Now walk the thread list of the system,
    // and display information about each thread
    // associated with the specified process
    do
    {
        auto it = process_map.find(te32.th32OwnerProcessID);
        if(it == process_map.end())
        {
            process_map[te32.th32OwnerProcessID] = ProcessInfo(te32.th32OwnerProcessID);
        }
        process_map[te32.th32OwnerProcessID].threads.push_back(te32.th32ThreadID);
    }
    while (Thread32Next(hThreadSnap, &te32));


    //  Don't forget to clean up the snapshot object.
    CloseHandle(hThreadSnap);

    return process_map;
}

std::wstring get_process_name( DWORD processID )
{
    TCHAR szProcessName[MAX_PATH] = TEXT("<unknown>");

    // Get a handle to the process.

    HANDLE hProcess = OpenProcess( PROCESS_QUERY_INFORMATION |
                                   PROCESS_VM_READ,
                                   FALSE, processID );

    // Get the process name.

    if (NULL != hProcess )
    {
        HMODULE hMod;
        DWORD cbNeeded;

        if ( EnumProcessModules( hProcess, &hMod, sizeof(hMod), 
             &cbNeeded) )
        {
            GetModuleBaseName( hProcess, hMod, szProcessName, 
                               sizeof(szProcessName)/sizeof(TCHAR) );
        }
    }

    // Print the process name and identifier.


    // Release the handle to the process.

    CloseHandle( hProcess );

    return std::wstring(szProcessName);
}

ProcessInfo::ProcessInfo(DWORD pid): pid(pid), processName(TEXT("<unknown>")) 
{
    TCHAR nameBuf[MAX_PATH] = TEXT("<unknown>");
    if (auto process = OpenProcess(PROCESS_QUERY_INFORMATION | PROCESS_VM_READ, false, pid))
    {
        HMODULE hMod;
        DWORD cbNeeded;
        if(EnumProcessModules(process, &hMod, sizeof(hMod), &cbNeeded))
        {
            GetModuleBaseName(process, hMod, nameBuf, sizeof(nameBuf) / sizeof(TCHAR));
            processName = std::wstring(nameBuf);
        }
    }
}


void print_error(const char* msg)
{
    LPVOID lpMsgBuf;
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

    lpDisplayBuf = (LPSTR)LocalAlloc(
        LMEM_ZEROINIT,
        (lstrlen((LPCTSTR)lpMsgBuf) + strlen(msg) + 128) * sizeof(TCHAR));
    
    StringCchPrintf(
        (LPTSTR)lpDisplayBuf,
        LocalSize(lpDisplayBuf) / sizeof(TCHAR),
        TEXT("%s: failed with error %d: %s"),
        msg,
        dw,
        lpMsgBuf);

    fprintf(stderr, lpDisplayBuf);
    fprintf(stderr, "\n");

    LocalFree(lpMsgBuf);
    LocalFree(lpDisplayBuf);
}

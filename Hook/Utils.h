#pragma once

#include <string>
#include <winsock.h>

namespace Utils
{
std::wstring GetProcessName(DWORD pid);
}

bool init_logger();
void log(std::string text);
void log(const char* str, size_t len);
void log_error(const char* msg);

#define logf(...) \
{ \
    char buf[1024]; \
    sprintf_s(buf, sizeof(buf), __VA_ARGS__); \
    char fmt_buf[1024]; \
    sprintf_s(fmt_buf, sizeof(fmt_buf), "[%d] %s", GetCurrentProcessId(), buf); \
    log(fmt_buf, strlen(fmt_buf)); \
}
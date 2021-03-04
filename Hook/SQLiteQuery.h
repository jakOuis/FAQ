#pragma once

#include <stdint.h>


#define SQLITE_INTEGER  1
#define SQLITE_FLOAT    2
#define SQLITE_BLOB     4
#define SQLITE_NULL     5
#define SQLITE_TEXT     3

__declspec(dllexport) class HookSQLite3Query
{
public:
    HookSQLite3Query();
    ~HookSQLite3Query();
    
    void* innerPtr;
    
    // __declspec(dllexport) HookSQLite3Query(void* self): innerPtr(self){}
    __declspec(dllexport) static void initLib(HMODULE hMod);
    __declspec(dllexport) void nextRow();
    __declspec(dllexport) bool eof();
    __declspec(dllexport) int numFields();
    __declspec(dllexport) const char* fieldName(int idx);
    __declspec(dllexport) int fieldDataType(int idx);
    __declspec(dllexport) bool fieldIsNull(int idx);
    __declspec(dllexport) const uint8_t* getBlobField(int idx, int* sizeOut);
    __declspec(dllexport) double getFloatField(int idx, double defaultValue);
    __declspec(dllexport) int64_t getInt64Field(int idx, int64_t defaultValue);
    __declspec(dllexport) int getIntField(int idx, int defaultValue);
    __declspec(dllexport) const char* getStringField(int idx, const char* defaultValue);
};
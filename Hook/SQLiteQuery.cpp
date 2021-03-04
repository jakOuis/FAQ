#include "pch.h"
#include "SQLiteQuery.h"
#include "Utils.h"


void* SQLite3Query_nextRow;
void* SQLite3Query_eof;
void* SQLite3Query_numFields;
void* SQLite3Query_fieldDataType;
void* SQLite3Query_fieldIsNull;
void* SQLite3Query_fieldName;
void* SQLite3Query_getBlobField;
void* SQLite3Query_getFloatField;
void* SQLite3Query_getInt64Field;
void* SQLite3Query_getIntField;
void* SQLite3Query_getStringField;

__declspec(dllexport) void HookSQLite3Query::initLib(HMODULE hMod)
{
    logf("get %p", SQLite3Query_eof = GetProcAddress(hMod, "?eof@CppSQLite3Query@@QAE_NXZ"));
    logf("get %p", SQLite3Query_fieldName = GetProcAddress(hMod, "?fieldName@CppSQLite3Query@@QAEPBDH@Z"));
    logf("get %p", SQLite3Query_fieldIsNull = GetProcAddress(hMod, "?fieldIsNull@CppSQLite3Query@@QAE_NH@Z"));
    logf("get %p", SQLite3Query_nextRow = GetProcAddress(hMod, "?nextRow@CppSQLite3Query@@QAEXXZ"));
    logf("get %p", SQLite3Query_numFields = GetProcAddress(hMod, "?numFields@CppSQLite3Query@@QAEHXZ"));
    logf("get %p", SQLite3Query_fieldDataType = GetProcAddress(hMod, "?fieldDataType@CppSQLite3Query@@QAEHH@Z"));
    logf("get %p", SQLite3Query_getBlobField = GetProcAddress(hMod, "?getBlobField@CppSQLite3Query@@QAEPBEHAAH@Z"));
    logf("get %p", SQLite3Query_getFloatField = GetProcAddress(hMod, "?getFloatField@CppSQLite3Query@@QAENHN@Z"));
    logf("get %p", SQLite3Query_getInt64Field = GetProcAddress(hMod, "?getInt64Field@CppSQLite3Query@@QAE_JH_J@Z"));
    logf("get %p", SQLite3Query_getIntField = GetProcAddress(hMod, "?getIntField@CppSQLite3Query@@QAEHHH@Z"));
    logf("get %p", SQLite3Query_getStringField = GetProcAddress(hMod, "?getStringField@CppSQLite3Query@@QAEPBDHPBD@Z"));
}


__declspec(dllexport) void HookSQLite3Query::nextRow()
{
    void* self = this->selfPtr;
    __asm {
        mov ecx, self
        call SQLite3Query_nextRow
        };
}

__declspec(dllexport) bool HookSQLite3Query::eof()
{
    void* self = this->selfPtr;
    bool result;
    __asm {
        mov ecx, self
        call SQLite3Query_eof
        mov result, al
        }
    return result;
}

__declspec(dllexport) int HookSQLite3Query::numFields()
{
    void* self = this->selfPtr;
    int result;
    __asm {
        mov ecx, self
        call SQLite3Query_numFields
        mov result, eax
        }
    return result;
}

__declspec(dllexport) const char* HookSQLite3Query::fieldName(int idx)
{
    void* self = this->selfPtr;
    const char* result;
    __asm {
        push idx
        mov ecx, self
        call SQLite3Query_fieldName
        mov result, eax
        }
    return result;
}

__declspec(dllexport) int HookSQLite3Query::fieldDataType(int idx)
{
    void* self = this->selfPtr;
    int result;
    __asm {
        push idx
        mov ecx, self
        call SQLite3Query_fieldDataType
        mov result, eax
        }
    return result;
}

__declspec(dllexport) bool HookSQLite3Query::fieldIsNull(int idx)
{
    void* self = this->selfPtr;
    bool result;
    __asm {
        push idx
        mov ecx, self
        call SQLite3Query_fieldIsNull
        mov result, al
        }
    return result;
}

__declspec(dllexport) const uint8_t* HookSQLite3Query::getBlobField(int idx, int* sizeOut)
{
    void* self = this->selfPtr;
    const uint8_t* result;
    __asm {
        push sizeOut
        push idx
        mov ecx, self
        call SQLite3Query_getBlobField
        mov result, eax
        };
    return result;
}

__declspec(dllexport) double HookSQLite3Query::getFloatField(int idx, double defaultValue)
{
    void* self = this->selfPtr;
    double result;
    __asm {
        movsd xmm0, defaultValue
        push ecx
        push ecx
        movsd [esp], xmm0

        push idx

        mov ecx, self
        call SQLite3Query_getFloatField
        fst result
        }
    return result;
}

__declspec(dllexport) int64_t HookSQLite3Query::getInt64Field(int idx, int64_t defaultValue)
{
    void* self = this->selfPtr;
    int64_t result;
    __asm {
        push dword ptr [defaultValue + 4]
        push dword ptr [defaultValue]
        push idx
        mov ecx, self
        call SQLite3Query_getInt64Field
        mov dword ptr [result], eax
        mov dword ptr [result + 4], edx
        }
    return result;
}

__declspec(dllexport) int HookSQLite3Query::getIntField(int idx, int defaultValue)
{
    void* self = this->selfPtr;
    int result;
    __asm {
        push defaultValue
        push idx
        mov ecx, self
        call SQLite3Query_getIntField
        mov result, eax
        }
    return result;
}

__declspec(dllexport) const char* HookSQLite3Query::getStringField(int idx, const char* defaultValue)
{
    void* self = this->selfPtr;
    const char* result;
    __asm {
        push defaultValue
        push idx
        mov ecx, self
        call SQLite3Query_getStringField
        mov result, eax
        }
    return result;
}

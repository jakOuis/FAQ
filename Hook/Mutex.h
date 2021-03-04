#pragma once

template<typename T>
class MutexGuard
{
public:
    MutexGuard(): inner(*(T*)nullptr), mutex() {}
    MutexGuard(HANDLE mutex, T& inner): inner(inner), mutex(mutex){}
    ~MutexGuard()
    {
        ReleaseMutex(mutex);
    }

    T* operator->()
    {
        return &inner;
    }
    
    
    T& operator* ()
    {
        return *inner;
    }
private:
    HANDLE mutex;
    T& inner;
};



template<typename T>
class Mutex
{
public:
    Mutex(T&& value);
    MutexGuard<T> lock();
private:
    HANDLE mutex;
    T inner;
};

template <typename T>
Mutex<T>::Mutex(T&& value): inner(value)
{
    mutex = CreateMutex(nullptr, false, nullptr);
}


template <typename T>
MutexGuard<T> Mutex<T>::lock()
{
    auto result = WaitForSingleObject(mutex, INFINITE);
    
    switch (result)
    {
        case WAIT_OBJECT_0:
            return MutexGuard<T>(mutex, inner);
        default:
            return MutexGuard<T>();
    }
}

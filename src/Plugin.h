#pragma once

#include <stdlib.h>
#include <stdio.h>
#include <string>


#ifdef __linux__
#include <dlfcn.h>

class Plugin
{
private:
    void *handle;
	char *error;

public:

    void Load(std::string Name);
    template<typename T>void Assign(std::string Key, T &func);
    void* Get_Function(std::string Key);
    ~Plugin();
};

void Plugin::Load(std::string Name)
{
    if(handle != nullptr) dlclose(handle);
    std::string Lib = "./" + Name + ".so";
    handle = dlopen (Lib.c_str(), RTLD_LAZY);
	if (!handle) {
        fputs (dlerror(), stderr);
        exit(1);
    }

}


template<typename T>void Plugin::Assign(std::string Key, T &func)
{
    void *Value = dlsym(handle, Key.c_str());
    if ((error = dlerror()) != NULL)  
    {
        fputs(error, stderr);
        exit(1);
    } 
    
    func = reinterpret_cast<decltype(func)>(Value);
}

void* Plugin::Get_Function(std::string Key)
{
    void *Value = dlsym(handle, Key.c_str());
    if ((error = dlerror()) != NULL)  
    {
        fputs(error, stderr);
        exit(1);
    } 
    
    return Value;
}

Plugin::~Plugin()
{
    dlclose(handle);
}

#endif

#ifdef __MINGW32__

#include <windows.h>
#include <iostream>

class Plugin
{
    private:
    HINSTANCE handle;
    char *error;

    public:
    void Load(std::string Name);
    template<typename T>
    void Assign(std::string Key, T &func);
    ~Plugin();
};


void Plugin::Load(std::string Name)
{
    if(handle != nullptr) FreeLibrary(handle);
    std::string Lib = Name + ".dll";
    handle = LoadLibrary(Lib.c_str());
    if (!handle)
    {
        std::cerr << "Failed to load DLL: " << GetLastError() << std::endl;
        exit(1);
    }
}

template<typename T>
void Plugin::Assign(std::string Key, T &func)
{
    if(handle != 0){
	func = (T)GetProcAddress(handle, Key.c_str());
}
	else func = nullptr;
}


Plugin::~Plugin()
{
    FreeLibrary(handle);
}
#endif
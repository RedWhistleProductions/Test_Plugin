#pragma once

#include <stdlib.h>
#include <stdio.h>
#include <dlfcn.h>
#include <string>


class Plugin
{
private:
    void *handle;
	char *error;
public:
    Plugin();
    void Load(std::string Name);
    template<typename T>void Assign(std::string Key, T &func);  
    ~Plugin();
};

Plugin::Plugin(){}

void Plugin::Load(std::string Name)
{
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


Plugin::~Plugin()
{
    dlclose(handle);
}

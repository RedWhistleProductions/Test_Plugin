#include "Plugin.h"

Plugin::Plugin(/* args */){}

Plugin::Plugin(std::string Name){Load(Name);}

void Plugin::Load(std::string Name)
{
    std::string Lib = "./" + Name + ".so";
    handle = dlopen (Lib.c_str(), RTLD_LAZY);
	if (!handle) {
        fputs (dlerror(), stderr);
        exit(1);
    }
}

void Plugin::Get_Function(std::string Key)
{
    //Gets Function from dll and loads it into the Function List
    Function_List.AddNode(Key);

    Function_List.Current->Value = dlsym(handle, Key.c_str());
    if ((error = dlerror()) != NULL)  
    {
        fputs(error, stderr);
        exit(1);
    }
}

void Plugin::Call(std::string Key)
{
    //Call a function from Function List
    void (*a)();
    if(Function_List.Find(Key))
    {
        *(void **)(&a) = Function_List.Current->Value;
        a();
    }
    
}       

Plugin::~Plugin()
{
    dlclose(handle);
}

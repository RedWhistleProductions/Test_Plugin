#include "Plugin.h"

Plugin::Plugin(/* args */)
{

}

void Plugin::Load(std::string Name)
{
    std::string Lib = "./" + Name + ".so";
    handle = dlopen (Lib.c_str(), RTLD_LAZY);
	if (!handle) {
        fputs (dlerror(), stderr);
        exit(1);
    }

    *(void **)(&hello) = dlsym(handle, "hello");
    if ((error = dlerror()) != NULL)  {
        fputs(error, stderr);
        exit(1);
    }

    hello();
}

Plugin::~Plugin()
{
    dlclose(handle);
}

#include <stdlib.h>
#include <stdio.h>
#include <dlfcn.h>
#include <string>
#include "NamedList.h"

class Plugin
{
private:
    void *handle;
	char *error;
public:
    NamedList<void *> Function_List;
    Plugin(/* args */);
    void Load(std::string Name);
    void Get_Function(std::string Key);
    void Call(std::string Key);
    ~Plugin();
};


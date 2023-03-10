#include <stdlib.h>
#include <stdio.h>
#include <dlfcn.h>
#include <string>

class Plugin
{
private:
    /* data */
public:
    void *handle;
	void (*hello)();
	char *error;

    Plugin(/* args */);
    void Load(std::string Name);

    ~Plugin();
};


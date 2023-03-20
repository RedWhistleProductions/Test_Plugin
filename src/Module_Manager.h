#include "Module.h"

class Module_Manager
{
private:
    /* data */
public:
    NamedList<Module> Module_List;
    void Add_Module(std::string Name, std::string Config, std::string Plugin_Name);
    Module_Manager(/* args */);
    ~Module_Manager();
};


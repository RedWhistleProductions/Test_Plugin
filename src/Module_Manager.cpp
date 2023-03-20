#include "Module_Manager.h"

void Module_Manager::Add_Module(std::string Name, std::string Config, std::string Plugin_Name )
{
    Module_List.AddNode(Name);
    Module_List.Current->Value.Set_Config(Config);
    Module_List.Current->Value.Set_Plugin(Plugin_Name);
}

Module_Manager::Module_Manager(/* args */)
{
}

Module_Manager::~Module_Manager()
{
}

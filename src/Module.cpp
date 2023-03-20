#include "Module.h"

void Module::Set_Config(std::string Config){Config__File = Config;}

void Module::Set_Plugin(std::string Plugin_Name)
{
    Selected_Plugin = Plugin_Name;
    Plug.Load(Plugin_Name);
    if(Config__File != "")
    {
        std::string Config__Path = "./res/Modules/" + Config__File;
        FileIO Config(Config__Path);
        std::string Command = Config.S();
        while (Command != "Done")
        {
            Plug.Get_Function(Command);
            Command = Config.S();
        }
    }
}

Module::Module(/* args */)
{
}

Module::Module(std::string Config)
{
    Set_Config(Config);
}

Module::Module(std::string Config, std::string Plugin_Name)
{
    Set_Config(Config);
    Set_Plugin(Plugin_Name);
}

Module::~Module()
{
}

void Module::Reserved_List()
{
    Plug.Function_List.Display();
}

void* Module::Assign(std::string Key)
{
    Plug.Function_List.Find(Key);
    return Plug.Function_List.Current->Value;
}

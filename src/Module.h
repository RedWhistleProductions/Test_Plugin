#pragma once

#include "Plugin.h"
#include "FileIO.h"

class Module
{
private:
    /* data */
public:
    std::string Config__File;
    std::string Selected_Plugin;

    Module(/* args */);
    Module(std::string Config);
    Module(std::string Config, std::string Plugin_Name);
    ~Module();

    Plugin Plug;
    void Set_Config(std::string Config);
    void Set_Plugin(std::string Plugin_Name);
    void Reserved_List();
    void* Assign(std::string Key);
};


#pragma once
#include "Plugin.h"
#include "NamedList.h"

template <typename T>
class Module
{
private:
	Plugin Lib;
public:
	Module(/* args */);
	~Module();
	void Init(std::string Library_Name)
	{   
		Lib.Load(Library_Name); 

	}
};

Module::Module(/* args */)
{
}

Module::~Module()
{
}

#pragma once

#include <string>

class Base_List
{
	public:
		bool Looped;
    	int Nodes;//Total Number of Nodes
    	int CurrentNode;//The Number of the Current Node in the NamedList
    	std::string CurrentName;//The Name of the Current Node
    	virtual void Next() = 0;
    	virtual void Back() = 0;
};



#pragma once
#include "Plugin.h"
#include "FileIO.h"


namespace Test
{
    Plugin Test_Plugin;

    // Functions from the plugin    
    void(*Test)();
    void(*Hello_World)();   
    bool(*Test_2)();
    int (*Add)(int a, int b);
    
    void Init(std::string Library_Name)
    {   
        // Load the plugin
        Test_Plugin.Load(Library_Name);

        // Assign the functions
        Test_Plugin.Assign("Test", Test);
        Test_Plugin.Assign("Test_2", Test_2);
        Test_Plugin.Assign("Hello_World", Hello_World);
        Test_Plugin.Assign("Add", Add);
    }

}



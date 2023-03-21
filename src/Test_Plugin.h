#pragma once
#include "Plugin.h"

extern Plugin Test_Plugin;

namespace Test
{
    void(*Test)();
    void(*Hello_World)();   
    bool (*Test_2)();
    int (*Add)(int a, int b);
    
    void Init()
    {    
        Test_Plugin.Assign("Test", Test);
        Test_Plugin.Assign("Hello_World", Hello_World);
        Test_Plugin.Assign("Test_2", Test_2);
        Test_Plugin.Assign("Add", Add);
    }
}



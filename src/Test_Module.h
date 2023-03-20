#pragma once

#include "Module.h"

extern Module Test_Module;

namespace Test
{
    void (*Test)();
    void (*Hello_World)();
    bool (*Test_2)();
    int (*Add)(int a, int b);

    void Init()
    {
        *(void **)(&Test) = Test_Module.Assign("Test");
        *(void **)(&Hello_World) = Test_Module.Assign("Hello_World");
        *(void **)(&Test_2) = Test_Module.Assign("Test_2");
        *(void **)(&Add) = Test_Module.Assign("Add");
    }
}



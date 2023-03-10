#include "Plugin.h"

int main()
{
    Plugin Test;
    Test.Load("lib");
    Test.Get_Function("Test");
    Test.Call("Test");
    Test.Get_Function("Hello_World");
    Test.Call("Hello_World");
    return 0;
}
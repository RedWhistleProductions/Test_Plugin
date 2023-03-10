#include "Module.h"

int main()
{
    Module Test("Test.Appeal", "lib");
    Test.Plug.Call("Test");
    return 0;
}
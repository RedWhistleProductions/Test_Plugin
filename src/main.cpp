#include <iostream>
#include "Test_Plugin.h"


int main()
{     
    Test::Init("lib");
    Test::Test();
    Test::Hello_World();
    Test::Test_2();
    std::cout << Test::Add(5, 5) << std::endl;
        
    return 0;
}
#include <iostream>
#include "Plugin.h"
#include "Test_Plugin.h"

Plugin Test_Plugin;


int main()
{   
    Test_Plugin.Load("lib");
    Test::Init();
    
    Test::Test();
    
    Test::Hello_World();
    if(Test::Test_2()){std::cout << "Test 2 Success!"<< std::endl;}
    std::cout << Test::Add(5, 5) << std::endl;

    return 0;
}
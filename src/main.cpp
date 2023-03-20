#include "Module_Manager.h"
#include "Test_Module.h"

Module Test_Module;

int main()
{ 
    Test_Module.Set_Config("Test");
    Test_Module.Set_Plugin("lib");
    Test::Init();
    Test::Test();
    Test::Hello_World();
    if(Test::Test_2()){std::cout << "Test 2 Success!"<< std::endl;}
    std::cout << Test::Add(5, 5) << std::endl;
    
    return 0;
}
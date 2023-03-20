#include <iostream>

extern "C" void Test() 
{
    std::cout << "Yay it works! :) " << '\n';
}

extern "C" void Hello_World() 
{
    std::cout << "Hello World!" << '\n';
}

extern "C" bool Test_2()
{
    return true;
}

extern "C" int Add(int x, int y)
{
    return x + y;
}
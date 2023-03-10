#include <iostream>

extern "C" void Test() {
    std::cout << "Yay it works! :) " << '\n';
}

extern "C" void Hello_World() {
    std::cout << "Hello World!" << '\n';
}
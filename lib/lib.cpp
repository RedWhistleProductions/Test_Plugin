#include <iostream>

extern "C" void hello() {
    std::cout << "Yay it works! :) " << '\n';
}

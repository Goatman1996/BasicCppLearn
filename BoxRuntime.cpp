#include <iostream>
#include "BoxRuntime.hpp"
#include "Box.hpp"

void privateTest();
void BoxRuntime::main()
{
    std::cout << "BoxRuntime::main" << std::endl;

    auto b = Box(1, 2, 3);

    std::cout << "Box size: " << b.Size() << std::endl;

    privateTest();
}

void privateTest()
{
    std::cout << "privateTest" << std::endl;
}
#include <iostream>
#include <string>
#include "module_5.h"

int main()
{
    std::cout<<"Enter name or id: ";
    std::string input;
    std::cin>>input;

    try
    {
        auto val = std::stoi(input);
        Shapes::printShape(static_cast<Shapes::Shape>(val));
    }
    catch(std::invalid_argument const&)
    {
        Shapes::printType(input.c_str());
    }
    return 0;
}
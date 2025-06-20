#include "calculator.h"
#include <exception>
#include <iostream>

int main() 
{
    auto value = Calculator::calculate(32.0, 7.0, Calculator::divide);
    std::cout<<"Division result: "<<value<<"\n";
    try 
    {
        value = Calculator::calculate(32.0, 0.0, Calculator::divide);
    }
    catch(std::exception& e)
    {
        std::cout<<e.what()<<"\n\n";
    }

    value = Calculator::calculate(32.0, Calculator::sqroot);
    std::cout<<"Square root result: "<<value<<"\n";
    try 
    {
        value = Calculator::calculate(-32.0, Calculator::sqroot);
    }
    catch(std::exception& e)
    {
        std::cout<<e.what()<<"\n\n";
    }

    value = Calculator::calculate(32.0, Calculator::logNatural);
    std::cout<<"Natural Log result: "<<value<<"\n";
    try 
    {
        value = Calculator::calculate(-32.0, Calculator::logNatural);
    }
    catch(std::exception& e)
    {
        std::cout<<e.what()<<"\n\n";
    }

    value = Calculator::calculate(32.0, Calculator::circleArea);
    std::cout<<"Circle Area result: "<<value<<"\n";
    try 
    {
        value = Calculator::calculate(-32.0, Calculator::circleArea);
    }
    catch(std::exception& e)
    {
        std::cout<<e.what()<<"\n";
    }
    return 0;
}

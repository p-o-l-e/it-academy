#include <iostream>
#include <bitset>
#include "module_4.h"

int main()
{
    int value { 0 };
    do
    {
        std::cout<<"Enter value : ";
        std::cin>>value;
        std::cout<<"Value is "<<(value & 0b1 ? "odd" : "even");
        std::cout<<" and "<<((value < 0) ? "negative" : "positive")<<".\n";
        std::cout<<"Given value is : "<<std::bitset<32>(value)<<"\n";
        std::cout<<"Result      is : "<<std::bitset<32>(check_n_shift(value))<<"\n";
    } 
    while (value);
    return 0;
}
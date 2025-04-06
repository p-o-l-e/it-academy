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
        std::cout<<"Given value is : "<<std::bitset<__SIZEOF_INT__*8>(value)<<"\n";
        std::cout<<"Result      is : "<<std::bitset<__SIZEOF_INT__*8>(check_n_shift(value))<<"\n";
    } 
    while (value);
    return 0;
}

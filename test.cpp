#include <iostream>
#include <string>
#include "module_6.h"

int main()
{
    std::string f("\n1) String Reverse ");
    std::cout<<f<<std::string(128 - f.size(), '-')<<"\n";
    requestAndReverse();

    f = "\n2) Heap allocated 2d array ";
    std::cout<<f<<std::string(128 - f.size(), '-')<<"\n";
    printMatrix();

    f = "\n3) Sorted vector ";
    std::cout<<f<<std::string(128 - f.size(), '-')<<"\n";
    sortVector();

    f = "\n4) Min and Max ";
    std::cout<<f<<std::string(128 - f.size(), '-')<<"\n";
    findMinMax();

    return 0;
}
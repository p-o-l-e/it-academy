#include <cstring>
#include <iostream>
#include <memory>
#include <iomanip>
#include <algorithm>
#include <format>
#include <vector>
#include <cmath>
#include <ctime>
#include "module_6.h"

void reverseString(char* str)
{
    int length = strlen(str);
    if(length)
    {
        int offset = 0;
        char* rptr = &str[length - 1];
        while(offset < length/2)
        {
            xorSwap<char>(*(str  + offset), *(rptr - offset));
            offset++;
        }
    }
}

void reverseStringA(char* str)
{
    std::string rstr(str);
    std::reverse(rstr.begin(), rstr.end());
    std::strcpy(str, rstr.c_str());
}

void requestAndReverse(const int& max)
{
    std::string s;
    int count = 0;
    std::cout<<"Type something : ";
    std::cin>>s;
    char* str = s.data();
    reverseString(str);
    std::cout<<"In reverse     : "<<s<<"\n";
}

void printMatrix(const int& w, const int& h)
{
    auto digits = countDigits((w - 1) * (h - 1));

    int **data = new int*[h];
    for(int i = 0; i < h; ++i) data[i] = new int[w];

    for(int y = 0; y < h; ++y)
    {
        for(int x = 0; x < w; ++x)
        {
            data[y][x] = x * y;
            std::cout<<std::format("{:>{}}", data[y][x], digits)<<" ";
        }
        std::cout<<"\n";
    }

    for(int y = 0; y < h; ++y) delete[] data[y];
    delete[] data;
}

void sortVector(const int& size, const int& min, const int& max)
{
    std::srand(std::time(0));
    std::vector<int> v(size);
    auto digits = std::max(countDigits(min), countDigits(max)) + 1;
    std::stringstream log;

    log<<"Unsorted :";
    for(auto& o: v)
    {
        o = randInRange(min, max);
        log<<std::format("{:>{}}", o, digits);
    }
    log<<"\n"<<"Sorted   :";

    std::sort(v.begin(), v.end());
    for(auto o: v) log<<std::format("{:>{}}", o, digits);
    log<<"\n";
    std::cout<<log.str();
}


void findMinMax(const int& size)
{
    auto data = std::make_unique<int[]>(size);
    int min = INT_MAX, max = INT_MIN;
    auto digits = countDigits(size) + 1;
    for(int i = 0; i < size; ++i)
    {
        std::cout<<std::format("Enter value{:>{}}: ", i + 1, digits);
        int val;
        std::cin>>data[i];
        if (std::cin.fail())
        {
            std::cout<<"\tNot a number!\n";
            return;
        }
        if(data[i] > max) max = data[i];
        else if(data[i] < min) min = data[i];
    }
    std::cout<<"\nEntered values: ";
    for(int i = 0; i < size; ++i)
    {
        std::cout<<data[i]<<"  ";
    }
    std::cout<<"\n"
             <<"Min           : "<<min<<"\n"
             <<"Max           : "<<max<<"\n";
}

template <typename T>
void xorSwap(T& a, T&b) noexcept
{
    a ^= b; b ^= a; a ^= b;
}

const int countDigits(const int& value) noexcept
{
    return value? static_cast<int>(std::log10(std::abs(value))) + 1 : 1; 
}

const int randInRange(const int& l, const int& r) noexcept
{ 
    return (rand() % (r - l + 1)) + l;
}

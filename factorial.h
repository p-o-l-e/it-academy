#pragma once
#include <iostream>
#include <chrono>
#include <cmath>
#include <climits>

#define F_BIG_INTEGER
#ifdef F_BIG_INTEGER

    #define F_INIT 0 
    #include <vector>
    #include <string>
    #include <algorithm>
    const std::string string_multiply(const std::string& a, const std::string& b);
    const std::string factorial(const int& n);

#elif defined F_FLOAT
    #define F_INIT 0.0f

const double factorial(const double& n);

#else
    #define F_INIT 0
    const long factorial(const int& n);

#endif



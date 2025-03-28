#pragma once
#include <iostream>

#ifdef F_BIG_INTEGER

#include <string>
const std::string string_multiply(const std::string& a, const std::string& b)
const std::string factorial(const int& n);

#elif defined F_FLOAT

#include <cmath>
const double factorial(const double& n);

#else
const long factorial(const int& n);

#endif



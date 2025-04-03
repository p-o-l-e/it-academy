#pragma once
#include <iostream>
#include <string>
#include <format>

class mtable
{
    public:
        enum class LOOP { FOR, WHILE, GOTO, DO };
    private:
        const std::string calculate_f(const int&);
        const std::string calculate_w(const int&);
        const std::string calculate_d(const int&);
        const std::string calculate_g(const int&);

    public:
        void repaint(const LOOP&, const int&);
        mtable();
       ~mtable();
};

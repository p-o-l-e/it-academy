#pragma once
#include <exception>
#include <stdexcept>
#include <cmath>

class Calculator 
{
    private:
        class InvalidLogArgument: public std::exception 
        {
            public:
                const char* what() const noexcept override
                {
                    return "Invalid Log Argument";
                }
        };

        class InvalidRadiusArgument: public std::exception 
        {
            public:
                const char* what() const noexcept override
                {
                    return "Invalid Radius Argument";
                }
        };

    public:
        template <typename F>
        static constexpr double calculate(double a, double b, F f) 
        {
            return f(a, b);
        }

        template <typename F>
        static constexpr double calculate(double a, F f) 
        {
            return f(a);
        }

        static constexpr auto divide = [](double a, double b) 
        { 
            if (!b) throw std::invalid_argument("Division by Zero");
            return a / b; 
        };

        static constexpr auto sqroot = [](double a) 
        {
            if(a < 0) throw std::domain_error("Root of negative value");
            return std::pow(a, 0.5);
        };

        static constexpr auto logNatural = [](double a) 
        {
            if(a < 0) throw InvalidLogArgument();
            return std::log(a);
        };
      
        static constexpr auto circleArea = [](double radius) 
        {
            if(radius < 0) throw InvalidRadiusArgument();
            return radius * radius * M_PI;
        };

};

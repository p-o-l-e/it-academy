#pragma once
#include <string>
#include <iostream>

class Book 
{
    public:
        const std::string& title() const { return _title; };
        const std::string& author() const { return _author; };
        const char* ISBN() const    { return _ISBN; };
        const int year() const      { return _year; };
        void printInfo();
        Book(const std::string, const std::string, const char*, const int&);
        Book(const Book&);
        ~Book();

    private:
        const std::string _title;
        const std::string _author;
        char* _ISBN;
        const int   _year;
        
};



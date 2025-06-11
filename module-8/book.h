#pragma once
#include <string>
#include <iostream>

class Book 
{
    public:
        const char* title() const   { return _title; };
        const char* author() const  { return _author; };
        const char* ISBN() const    { return _ISBN; };
        const int year() const      { return _year; };
        void printInfo();
        Book(const char*, const char*, const char*, const int&);
        Book(const Book&);
        ~Book() = default;

    private:
        const char* _title;
        const char* _author;
        const char* _ISBN;
        const int   _year;
        
};



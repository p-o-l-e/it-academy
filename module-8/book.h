// Создайте класс Book, который будет представлять книгу. 
// Класс должен содержать закрытые поля title, author и year (название, автор и год издания соответственно). 
// Также в книге есть поле ISBN, которое хранится в виде char*
//
// Реализуйте:
// Конструктор для инициализации всех полей.
// Конструктор копирования
// Деструктор
// Геттеры для доступа к полям. 
// Метод printInfo(), который будет выводить информацию о книге на экран.
//
// Напишите код, который продемонстрирует работу всех реализованных функций класса.

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



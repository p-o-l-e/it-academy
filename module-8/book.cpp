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
#include "book.h"

void Book::printInfo()
{
    std::cout<<  "Author : "<<_author
             <<"\nTitle  : "<<_title
             <<"\nISBN   : "<<_ISBN
             <<"\nYear   : "<<_year<<"\n\n";
}


Book::Book(const char* title, const char* author, const char* isbn, const int& year): 
    _title(title), _author(author), _ISBN(isbn), _year(year)
{};

Book::Book(const Book& book): 
    _title(book._title), _author(book._author), _ISBN(book._ISBN), _year(book._year)
{};



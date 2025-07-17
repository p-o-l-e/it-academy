#include "book.h"
#include <cstring>

void Book::printInfo()
{
    std::cout<<"Author : "<<_author<<"\n"
             <<"Title  : "<<_title<<"\n"
             <<"ISBN   : "<<_ISBN<<"\n"
             <<"Year   : "<<_year<<"\n\n";
}


Book::Book(const std::string title, const std::string author, const char* isbn, const int& year): 
    _title(title), _author(author), _year(year)
{
    _ISBN = new char[std::strlen(isbn) + 1];
    std::strcpy(_ISBN, isbn);
};

Book::Book(const Book& other): 
    _title(other._title), _author(other._author), _year(other._year)
{
    _ISBN = new char[std::strlen(other._ISBN) + 1];
    std::strcpy(_ISBN, other._ISBN);
};

Book::~Book()
{
    delete[] _ISBN;
}

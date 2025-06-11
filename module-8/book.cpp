#include "book.h"

void Book::printInfo()
{
    std::cout<<"Author : "<<_author<<"\n"
             <<"Title  : "<<_title<<"\n"
             <<"ISBN   : "<<_ISBN<<"\n"
             <<"Year   : "<<_year<<"\n\n";
}


Book::Book(const char* title, const char* author, const char* isbn, const int& year): 
    _title(title), _author(author), _ISBN(isbn), _year(year)
{};

Book::Book(const Book& book): 
    _title(book._title), _author(book._author), _ISBN(book._ISBN), _year(book._year)
{};



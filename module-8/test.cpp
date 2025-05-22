#include <iostream>
#include <iterator>
#include <vector>
#include "book.h"

int main()
{
    std::cout<<"Basic constructor initialization: \n";
    std::cout<<std::string(64, '-')<<"\n\n";
    Book books[]
    {
        {"How to Create a Cult", "Dick Hubbell", "4-271-09235-8", 2076 },
        {"History Of Radiation Burns", "Anonymous", "3-827-19384-9", 2077 },
        {"Mutations: It Could Happen To You", "Anonymous", "6-492-73829-2", 2075 },
        {"You-Nionize Today!", "Labor Union", "9-184-83741-0", 2070 },
        {"Lying, Congressional Style", "Anonymous", "5-309-27385-4", 2064 },
        {"Wasteland Survival Guide", "Moira Brown", "0-928-37461-7", 2084 },
    };

    constexpr int size = std::size(books);
    Book* shelf[size];
    for(int i = 0; i < size; ++i)
    {
        books[i].printInfo();
        shelf[i] = new Book { books[i] }; 
    }

    std::cout<<"Getters and setters: \n";
    std::cout<<std::string(64, '-')<<"\n\n";
    std::cout<<"Author : "<<books[0].author()<<"\n"
             <<"Title  : "<<books[0].title()<<"\n"
             <<"ISBN   : "<<books[0].ISBN()<<"\n"
             <<"Year   : "<<books[0].year()<<"\n\n";


    std::cout<<"Copy constructor initialization: \n";
    std::cout<<std::string(64, '-')<<"\n\n";
    for(int i = size - 1; i > 0; --i)
    {
        shelf[i]->printInfo();
        delete shelf[i]; 
    }
    return 0;
}

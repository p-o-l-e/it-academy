#include <iterator>
#include <vector>
#include "book.h"

int main()
{

    Book books[]
    {
        {"How to Create a Cult", "Dick Hubbell", "4-271-09235-8", 2076 },
        {"Cryptic Cryptids: The Puzzle of Procreation", "Garrison \"Guy\" Foggarty", "2-167-93452-6", 2078 },
        {"The Robotics of Then and Now", "Dr. Clara Song", "8-493-12947-5", 2069 },
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
    std::cout<<std::string(64, '-')<<"\n\n";
    for(int i = size - 1; i > 0; --i)
    {
        shelf[i]->printInfo();
        delete shelf[i]; 
    }
    return 0;
}

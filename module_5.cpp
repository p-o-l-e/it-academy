#include <iostream>
#include <cstring>
#include "module_5.h"

namespace Shapes 
{
    void printShape(const Shape& s, const std::map<Shape, const char*>& map)
    {
        if(map.size() != static_cast<size_t>(Shape::COUNT))
        {
            std::cout<<"Corrupted map!\n";
            return;
        }
        if(map.contains(s)) 
        { 
            std::cout<<"Shape name: "<<map.find(s)->second<<"\n";
            return;
        }
        std::cout<<"Undefined shape!\n";
    }

    void printType(const char* str,  const std::map<Shape, const char*>& map)
    {
        bool found { false };        
        for(auto o: map) 
        { 
            auto length = std::strlen(o.second);
            if(length != std::strlen(str)) continue;
            for(int i = 0; i < length; ++i)
            {
                if(std::tolower(o.second[i]) != std::tolower(str[i]))
                {   
                    found = false;
                    break;
                }
                found = true;
            }
            if(found) 
            {
                printShape(o.first);
                return;
            }
        }
        std::cout<<"Undefined shape!\n";
    }
} // Namespace Shapes
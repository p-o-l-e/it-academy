#include "mtable.h"

int main()
{
    mtable mt;
    mt.repaint(mtable::LOOP::DO, 10);
    // mt.repaint(mtable::LOOP::WHILE, 10);
    // mt.repaint(mtable::LOOP::GOTO, 10);
    // mt.repaint(mtable::LOOP::FOR, 10);

    return 0;
}


const std::string mtable::calculate_f(const int& size)
{
    std::string result {};
    for(int y = 1; y <= size; ++y)
    {
        for(int x = 1; x <= size; ++x)
        {
            result += std::format("{:3} ", x * y);
        }
        result += "\n";
    }
    result += "\n";
    return result;
}

const std::string mtable::calculate_w(const int& size)
{
    std::string result {};
    int x = 0, y = 0;
    while(x++ < size)
    {
        while(y++ < size)
        {
            result += std::format("{:3} ", x * y);
        }
        y = 0;
        result += "\n";
    }
    return result;
}

const std::string mtable::calculate_d(const int& size)
{
    std::string result {};
    int x = 1, y = 1;
    do 
    {
        result += std::format("{:3} ", x * y);
        if(++x > size)
        { 
            x = 1;
            ++y;
            result += "\n";
        }        
    }
    while(y <= size);

    return result;
}

const std::string mtable::calculate_g(const int& size)
{
    std::string result {};
    int x = 1, y = 1;
    outer:
        result += "\n";
    inner:
        result += std::format("{:3} ", x * y);
        if(y++ < size) goto inner;
        y = 1;
        if(x++ < size) goto outer;
        result += "\n";

    return result;
}

void mtable::repaint(const LOOP& l_type, const int& size)
{
    switch (l_type)
    {
        case LOOP::FOR:
            std::cout<<calculate_f(size);
        break;
        
        case LOOP::WHILE:
            std::cout<<calculate_w(size);
        break;
    
        case LOOP::GOTO:
            std::cout<<calculate_g(size);
        break;

        case LOOP::DO:
            std::cout<<calculate_d(size);
        break;

        default:
        break;
    }

}

mtable::mtable(/* args */)
{
}

mtable::~mtable()
{
}

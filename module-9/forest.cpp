#include "forest.h"
#include <iostream>

int Tree::_counter = 0;
int Forest::_counter = 0;

void Tree::wind() const 
{ 
    std::cout<<std::format("Name: {:<8} - ID: {:#010X}\n", _name, _uid); 
};

Tree::Tree(const std::string& name, const Species& species): 
    _name(name), _species(species), _uid((static_cast<int>(_species) << 16) + (_counter++)) 
{
    std::cout<<"-- Default constructor...\n";
}

Tree::Tree(const Tree& tree): 
    _name(tree._name), _species(tree._species), _uid((static_cast<int>(tree._species) << 16) + (_counter++)) 
{
    std::cout<<"-- Copy constructor...\n";
}

Tree::~Tree()
{
    std::cout<<std::format("Tree cut. ID: {:#010X}\n", _uid); 
}



void Forest::growUp(const Tree& tree) 
{   
    grove.emplace_back(std::move(tree)); 
}

void Forest::windAll() const 
{ 
    for(const auto& o: grove) o.wind(); 
}

void Forest::cutAll() 
{ 
    grove.clear(); 
}

const size_t Forest::getTreesNumber() const 
{ 
    return grove.size(); 
}

Forest Forest::operator+(const Forest& forest) const
{
    Forest combined;
    combined.grove.insert(combined.grove.end(), grove.begin(), grove.end());
    combined.grove.insert(combined.grove.end(), forest.grove.begin(), forest.grove.end());
    return combined;
}

Forest::Forest(): id(_counter++)
{
    std::cout<<"-- Forest constructor: "<<id<<"\n";

}

Forest::~Forest()
{
    std::cout<<"-- Forest destructor: "<<id<<"\n";
}

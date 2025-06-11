#include "abstract_forest.h"
#include <iostream>

int Tree::_counter = 0;
int Pine::_counter = 0;
int Maple::_counter = 0;


Tree::Tree(const std::string& name, const TreeType& species): 
    _name(name), treeType(species), _uid((static_cast<int>(treeType) << 16) + (_counter++)) 
{
    // std::cout<<"-- Default constructor...\n";
}

Tree::Tree(const Tree& tree): 
    _name(tree._name), treeType(tree.treeType), _uid((static_cast<int>(tree.treeType) << 16) + (_counter++)) 
{
    // std::cout<<"-- Copy constructor...\n";
}

const size_t Forest::getTreesNumber() const 
{ 
    return grove.size(); 
}



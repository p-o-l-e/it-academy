#include <iostream>
#include "abstract_forest.h"

int main()
{
    std::list<Tree*> trees { new Pine, new Pine, new Maple, new Pine, new Maple, new Maple, new Pine, new Maple };

    auto size = std::size(trees);

    ConiferousForest c_forest;
    DeciduousForest d_forest;

    for(auto& tree: trees)
    {
        c_forest.growUp(tree);
        d_forest.growUp(tree);
    }
    c_forest.wind();
    std::cout<<"\nConiferous trees: "<<c_forest.getTreesNumber()<<"\n\n";
    d_forest.wind();
    std::cout<<"\nDeciduous trees : "<<d_forest.getTreesNumber()<<"\n\n";
    
    for(auto& tree: trees)
    {
        delete tree;
    }
    return 0;
}

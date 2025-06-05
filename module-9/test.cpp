#include <iostream>
#include "forest.h"

int main()
{
    std::cout<<"\nPlanting trees...\n\n";
    std::list<Tree> trees;   
    trees.emplace_back("Ash",    Tree::Species::Ash    ); 
    trees.emplace_back("Pine",   Tree::Species::Pine   ); 
    trees.emplace_back("Cherry", Tree::Species::Cherry ); 
    trees.emplace_back("Cedar",  Tree::Species::Cedar  ); 
    trees.emplace_back("Oak",    Tree::Species::Oak    ); 
    std::cout<<"\nTrees planted...\n\n";

    for(const auto& tree: trees)
    {
        tree.wind();
    }
    std::cout<<"\nPlanting forest A...\n\n";

    Forest forest_a;
    for(const auto& tree: trees)
    {
        forest_a.growUp(tree);
    }
    std::cout<<"\n";
    forest_a.windAll();

    std::cout<<"\nPlanting forest B...\n\n";

    Forest forest_b;
    for(const auto& tree: trees)
    {
        forest_b.growUp(tree);
    }
    std::cout<<"\n";
    forest_b.windAll();

    std::cout<<"\nPlanting forest C...\n\n";

    Forest forest_c = forest_a + forest_b;
    std::cout<<"\n";
    forest_c.windAll();

    std::cout<<"\nTrees in the forest: "<<forest_c.getTreesNumber()<<"\n\n";
    forest_a.cutAll();
    forest_b.cutAll();

    return 0;
}

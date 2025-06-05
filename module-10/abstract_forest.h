
#pragma once
#include <cstddef>
#include <iostream>
#include <string>
#include <cstdint>
#include <bitset>
#include <format>
#include <list>


class Tree
{
    public:
        enum class TreeType { Deciduous, Coniferous };
        const uint32_t getID() const { return _uid; };
        const TreeType getType() const { return treeType; }
        const std::string getName() const { return _name; };
    virtual void wind() const = 0;
        Tree(const std::string&, const TreeType&);
        Tree(const Tree&);
        virtual ~Tree() = default;

    protected:
        const TreeType treeType;
        const std::string _name;
        const uint32_t _uid; 
        static int _counter;
};


class Pine: public Tree
{
    private:
        static int _counter;
        const int _position;

    public:
        void wind() const override { std::cout<<"Coniferous: "<<_name<<"\t#"<<_position<<"\n"; }
        Pine(): Tree("Pine", TreeType::Coniferous), _position(++_counter) {};
};

class Maple: public Tree
{
    private:
        static int _counter;
        const int _position;

    public:
        void wind() const override { std::cout<<"Deciduous : "<<_name<<"\t#"<<_position<<"\n"; }
        Maple(): Tree("Maple", TreeType::Deciduous), _position(++_counter) {};
};

class Forest 
{
    public:
        virtual void growUp(Tree*) = 0;
        void wind() const { for(const auto o: grove) o->wind(); };
        void cutAll();
        const size_t getTreesNumber() const;
        Forest() = default;
        virtual ~Forest() = default;

    protected:
        std::list<Tree*> grove;
};

class ConiferousForest: public Forest
{
    public:
        void growUp(Tree* tree) override { if(tree->getType() == Tree::TreeType::Coniferous)  grove.emplace_back(tree); }
        ConiferousForest() {};
       ~ConiferousForest() override {};

};

class DeciduousForest: public Forest
{
    public:
        void growUp(Tree* tree) override { if(tree->getType() == Tree::TreeType::Deciduous)  grove.emplace_back(tree); }
        DeciduousForest() {};
       ~DeciduousForest() override {};

};


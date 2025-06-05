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
        enum class Species { Ash, Oak, Cherry, Cedar, Pine };
        const uint32_t getID() const { return _uid; };
        const std::string getName() const { return _name; };
        void wind() const;
        Tree(const std::string&, const Species&);
        Tree(const Tree&);
        ~Tree();

    private:
        const Species _species;
        const std::string _name;
        const uint32_t _uid; 
        static int _counter;
};

class Forest 
{
    public:
        void growUp(const Tree&);
        void growUp(Tree&&);
        void windAll() const;
        void cutAll();
        const size_t getTreesNumber() const;
        Forest operator+(const Forest&) const;        
        Forest();
        ~Forest();
        
    private:
        static int _counter;
        const int id;
        std::list<Tree> grove;
};

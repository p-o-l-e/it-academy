#pragma once    
#include <iostream>
#include <chrono>
#include <map>
#include <random>
#include <thread>
#include <string>

class Order 
{
    public:
        enum State { New, Processing, Shipped };
        void printInfo() const;
        State getState() const  { return state; }
        void setState(State s)  { state = s; }
        double getPrice() const { return price; }
        unsigned getUID() const { return orderUID; }
        int msElapsed() const;
        Order(double p);
        Order(const Order&);
        Order(Order&&);
        Order& operator=(Order&&);
        ~Order();
    
    private:
        State state;
        static unsigned counter;
        unsigned orderUID;
        double price;
        std::chrono::steady_clock::time_point orderDate;
        
        
};



class Shop 
{
    public:
        void addOrder(double);
        void addToQueue();
        void findWithPriceOver(double threshold) const;
        std::vector<Order> shipOrders();
        void printAll() const;
        Shop() { orders.reserve(10); };
    private:
        static const int msThreshold = 5000;
        std::vector<Order> orders;
};

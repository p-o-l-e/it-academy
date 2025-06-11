#include "servicestation.h"

Car::Car(const std::string& name): name(name) 
{
    std::cout<<"Car constructor\n";
}
        
Car::~Car()
{
    std::cout<<"Car destructor\n";
}
        
void Car::Repair() 
{
    isRepaired = true;
}

void CargoCar::print(std::ostream& os) const
{
    os<<std::format("CargoCar: {:<10} - Repaired: {}\n", name, (isRepaired? "True" : "False"));
}

void PassengerCar::print(std::ostream& os) const
{
    os<<std::format("PassengerCar: {:<10} - Repaired: {}\n", name, (isRepaired? "True" : "False"));
}


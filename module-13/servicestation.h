#include <cstddef>
#include <string>
#include <iostream>
#include <vector>
#include <format>

class Car 
{
    public:
        Car(const std::string&);
        virtual ~Car();
        void Repair();
        friend std::ostream& operator<<(std::ostream& os, const Car& car) { car.print(os); return os; } ;
    
    protected:
        const std::string name;
        bool isRepaired = false;
        virtual void print(std::ostream&) const = 0;  
};

class CargoCar: public Car
{
    public:
        CargoCar(const std::string& name): Car(name) {} 
        ~CargoCar() = default;

    private:
        void print(std::ostream&) const override;
};

class PassengerCar: public Car
{
    public:
        PassengerCar(const std::string& name): Car(name) {} 
        ~PassengerCar() = default;

    private:
        void print(std::ostream& os) const override;
};

template <typename T>
class Garage 
{
    public:
        void addCar(T* car) { cars.emplace_back(car); };
        void displayAll() const { for(const auto& o: cars) std::cout<<*o; };
        Garage() {};
        ~Garage() {};
        std::vector<T*> cars; 
    
};

template <typename T>
class ServiceStation
{
    public:
        void addCar(T* car) { if(serviceGarage.cars.size() < _limit) serviceGarage.addCar(car); };
        void repairAll() 
        { 
            for(const auto& o: serviceGarage.cars) 
            { 
                o->Repair(); 
                storageGarage.addCar(o);
            }
            serviceGarage.cars.clear();
        }
        void printQueue() const { serviceGarage.displayAll(); }
        void printRepaired() const { storageGarage.displayAll(); }
        ServiceStation(const size_t limit): _limit(limit) 
        {
            serviceGarage.cars.reserve(_limit);
        };
        ~ServiceStation() = default;

    private:
        const size_t _limit;
        Garage<T> serviceGarage;
        Garage<T> storageGarage;
};

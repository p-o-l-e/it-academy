#include "servicestation.h"

int main()
{
    std::vector<CargoCar*> cCar 
    {  
        new CargoCar("Iveco"), 
        new CargoCar("Scania"), 
        new CargoCar("Mercedes"),
        new CargoCar("Volvo"), 
        new CargoCar("Mack"), 
        new CargoCar("MAZ") 
    };

    std::vector<PassengerCar*> pCar 
    {  
        new PassengerCar("VW"), 
        new PassengerCar("BMW"), 
        new PassengerCar("Mercedes"),
        new PassengerCar("Volvo"), 
        new PassengerCar("Renault"), 
        new PassengerCar("Mazda") 
    };

    ServiceStation<CargoCar> ssCargo(5);
    ServiceStation<PassengerCar> ssPassenger(5);

    for(auto& o: cCar)
    {
        ssCargo.addCar(o);
    }

    for(auto& o: pCar)
    {
        ssPassenger.addCar(o);
    }

    std::cout<<"\nCargo Cars - before repair:\n";
    ssCargo.printQueue();
    ssCargo.printRepaired();

    std::cout<<"\nCargo Cars - after repair:\n";

    ssCargo.repairAll();
    ssCargo.printQueue();
    ssCargo.printRepaired();

    std::cout<<"\nPassenger Cars - before repair:\n";
    ssPassenger.printQueue();
    ssPassenger.printRepaired();

    std::cout<<"\nPassenger Cars - after repair:\n";

    ssPassenger.repairAll();
    ssPassenger.printQueue();
    ssPassenger.printRepaired();

    std::cout<<"\n";
    for(auto& o: cCar)
    {
        delete o;
    }

    for(auto& o: pCar)
    {
        delete o;
    }
    return 0;
}

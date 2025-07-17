#include "shop.h"

int main()
{
    Shop shop;
    shop.addOrder(1000.0);
    shop.addOrder(5500.0);
    shop.addOrder(300.0);
    shop.addOrder(7200.0);

    std::this_thread::sleep_for(std::chrono::seconds(6));

    shop.addToQueue();
    shop.findWithPriceOver(5000.0);

    auto processed = shop.shipOrders();

    std::cout << "\nProcessed orders: \n\n";
    for (const auto& o : processed) o.printInfo();

}

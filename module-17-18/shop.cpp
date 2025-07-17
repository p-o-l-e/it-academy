#include "shop.h"

unsigned Order::counter = 0;

        void Order::printInfo() const
        {
            std::cout<<"UID  : "<<orderUID<<"\n";
            std::cout<<"Price: "<<price<<"\n";
            
            auto now = std::chrono::steady_clock::now();
            auto elapsed = now - orderDate;

            std::cout<<"Time : "<<std::chrono::duration_cast<std::chrono::milliseconds>(elapsed).count()<<"ms\n";
            std::cout<<"State: ";

            switch(state) 
            {
                case New: std::cout<<"New\n"; break;
                case Processing: std::cout<<"Processing\n"; break;
                case Shipped: std::cout<<"Shipped\n"; break;
                default: break;
            }
            std::cout<<"\n";
        }

        int Order::msElapsed() const 
        {
            return std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now() - orderDate).count();
        }

        Order::Order(double p = 0.0): orderUID(++counter), price(p), orderDate(std::chrono::steady_clock::now()), state(New) 
        {
            std::cout<<"Default constructor - UID: "<<orderUID<<"\n";
        }

        Order::Order(const Order& other): orderUID(other.orderUID), price(other.price), orderDate(other.orderDate), state(other.state) 
        {
            std::cout<<"Copy constructor    - UID: "<<orderUID<<"\n";
        }

        Order::Order(Order&& other): orderUID(other.orderUID), price(other.price), orderDate(other.orderDate), state(other.state) 
        {
            std::cout<<"Moved to UID: "<<other.orderUID<<"\n";
            other.price = 0.0;
            other.state = New;
        }

        Order& Order::operator=(Order&& other)
        {
            std::cout<<"Assigning UID "<<other.orderUID<<" via move\n";
            orderUID = other.orderUID;
            price = other.price;
            orderDate = other.orderDate;
            state = other.state;

            other.orderUID = 0;
            other.price = 0.0;
            other.state = New;
            return *this;
        }

        Order::~Order() {};


        void Shop::addOrder(double price) 
        {
            orders.emplace_back(price);
        }

        void Shop::addToQueue() 
        {
            std::transform
            (   
                orders.begin(), orders.end(), orders.begin(),
                [msThreshold](Order& o) 
                {
                    if (o.getState() == Order::New && (o.msElapsed() > msThreshold)) 
                    {
                        o.setState(Order::Processing);
                    }
                    return std::move(o);
                });
        }

        void Shop::findWithPriceOver(double threshold) const 
        {
            auto it = std::find_if
            (
                orders.begin(), orders.end(),
                [threshold](const Order& o) 
                {
                    return o.getState() == Order::Processing && o.getPrice() > threshold;
                }
            );

            if(it != orders.end()) 
            {
                std::cout<<"Price > "<<threshold<<" UID: "<<it->getUID()<<" - actual price: "<<it->getPrice()<<"\n";
            }
        }

        std::vector<Order> Shop::shipOrders() 
        {
            auto pivot = std::partition(orders.begin(), orders.end(), [](const Order& o) { return o.getState() == Order::Processing; });

            std::vector<Order> shipped;
            shipped.reserve(orders.size());

            std::move(orders.begin(), pivot, std::back_inserter(shipped));

            for(auto& o: shipped) 
            {
                o.setState(Order::Shipped);
            }

            for(auto& o: orders) 
            {
                if(o.getState() == Order::Processing) 
                {
                    o = Order();
                }
            }
            return shipped;
        }

        void Shop::printAll() const 
        {
            for(const auto& o: orders) o.printInfo();
        }


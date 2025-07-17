#include <algorithm>
#include <numeric>
#include <thread>
#include <random>
#include <vector>
#include <iostream>
#include <execution>

int randomInRange(int min, int max) 
{
    static std::random_device rd;
    static std::mt19937 gen(rd());
    std::uniform_int_distribution<> distrib(min, max);
    return distrib(gen);
}

class MTArray
{
    public:
        MTArray(int size = 100): data(refill(size))       
        {
            threads[0] = std::thread(&MTArray::findMin, this);
            threads[1] = std::thread(&MTArray::findMax, this);
            threads[2] = std::thread(&MTArray::sumElements, this);
            for(auto& t : threads) if(t.joinable()) t.join();
        };
        ~MTArray() {}; 
        
        void sumElements() 
        { 
            auto sum = std::reduce(std::execution::par, data.begin(), data.end(), 0); 
            std::lock_guard<std::mutex> lock(_mutex);
            _sum = sum;
        }
        void findMin() 
        { 
            auto min = *std::min_element(std::execution::par, data.begin(), data.end()); 
            std::lock_guard<std::mutex> lock(_mutex);
            _min = min;

        }
        void findMax() 
        { 
            auto max = *std::max_element(std::execution::par, data.begin(), data.end()); 
            std::lock_guard<std::mutex> lock(_mutex);
            _max = max;

        }

        void print() 
        { 
            std::cout<<"\n";
            for(const auto& i: data) std::cout<<i<<" "; 
            std::cout<<"\n\nMin : "<<_min;
            std::cout<<"\nMax : "<<_max;
            std::cout<<"\nSum : "<<_sum<<"\n\n";
        }
    private:
        std::vector<int> refill(int size) 
        {
            std::vector<int> r(size);
            std::generate(r.begin(), r.end(), []() { return randomInRange(0, 100); });
            return r;
        }
        std::mutex _mutex;
        std::thread threads[3];
        std::vector<int> data;
        int _min;
        int _max;
        int _sum;
};

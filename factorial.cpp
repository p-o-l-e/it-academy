#include "factorial.h"

#ifdef F_BIG_INTEGER

const std::string factorial(const int& n)
{
    return n? string_multiply(std::to_string(n), factorial(n - 1)) : "1";
}

// Fürer's big numbers multiplication algorithm: 
// https://en.wikipedia.org/wiki/Multiplication_algorithm#Further_improvements.

const std::string string_multiply(const std::string& a, const std::string& b)
{
        if((a == "0")||(b == "0")) { return "0"; }
        std::string hi = (a.size() > b.size()) ? a : b; 
        std::string lo = (a.size() > b.size()) ? b : a; 
        long long cvm[lo.size()][hi.size()];
        
        size_t x = 0, y = 0;
        for(auto m = lo.rbegin(); m!= lo.rend(); m++, y++)
        {
            for(auto i= hi.rbegin(); i!= hi.rend(); i++, x++)
            {
                cvm[y][x]=(*i - '0') * (*m - '0');
            }
            x = 0;
        }

        std::vector<int> cvn (hi.size(), 0);
        for(y = 0; y < lo.size(); y++)
        {
            for(x = 0; x < hi.size(); x++)
            {
                cvn[x + y] += cvm[y][x];
            }
            cvn.push_back(0);
        }

        std::string product = ""; 
        int car = 0;
        for(auto i: cvn) 
        { 
            car += i; 
            product += car % 10 + '0'; 
            car /= 10; 
        }

        while(product.back() == '0') { product.pop_back(); }
        std::reverse(product.begin(), product.end());

        return product;
} 


#elif defined F_FLOAT
const double factorial(const double& n)
{
    return n? n * (n - 1.0f) * std::tgamma(n - 1.0f) : 1.0f;
}

#else 

const long factorial(const int& n)
{
    return n? n * factorial(n - 1) : 1; 
}

#endif


int main(void)
{

    while(true) 
    { 
        auto value = F_INIT;
        std::cout<<"Enter value : ";
        std::cin>>value;
        std::cout<<"\n";

        if(!value || std::isnan(value) || value > 20000) 
        {
            std::cout<<"Not a value! Valid value range [ 0..20000 ]\n";
            break;
        }
        std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();
        std::cout<<factorial(value)<<"\n\n";
        std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
        std::cout << "Time elapsed : " << std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count() << "[ms]" << std::endl;
    
    }
    return 0;
}

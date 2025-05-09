#include "sysinfo.h"
#include "factorial.h"

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

    SysInfo s_info;
    std::cout<<s_info.GetSystemInfo();

    return 0;
}


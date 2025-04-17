#include <iostream>
#include <sstream>
#include <fstream>
#include <cstring>
#include "sysinfo.h"
#ifdef __linux__
    #include <cpuid.h>
#endif


const std::string SysInfo::getCompilerVersion()
{
    std::string result { "Unknown Compiler" };
    #if defined(__GNUC__)
        #if defined(__clang__)
            result = "Clang: ";
        #else
            result = "GNUC: ";
        #endif

        result += __VERSION__;

    #elif defined(_MSC_VER)
        result = "MSVC: ";
        result += _MSC_FULL_VER;
    #endif

    return result;
}

const std::string SysInfo::getCppVersion()
{
    std::string result { "Pre-standard C++" };
    auto v = cppversion.find(__cplusplus);
    if(v == cppversion.end()) return result;
    return v->second;
}

const std::string SysInfo::getOsName()
{
    #ifdef _WIN32
    return "Windows 32-bit";
    #elif _WIN64
    return "Windows 64-bit";
    #elif __linux__
    return "Linux";
    #endif
    
    return "Other";
}    

#ifdef __linux__

    void SysInfo::trim(std::string& line, const std::string& separator)
    {
        line.erase(line.begin(), line.begin() + line.find_first_of(separator) + 1);
        const char* space = " \t\v\r\n";
        std::size_t start = line.find_first_not_of(space);
        std::size_t end = line.find_last_not_of(space);
        line = line.substr(start, end - start + 1);
    }

    const std::string SysInfo::parse(const std::string& path, const std::string& data, const std::string& separator)
    {
        std::ifstream file(path);
        std::string line {};

        while (std::getline(file, line)) 
        {
            if (line.find(data) != std::string::npos) 
            {
                trim(line, separator);
                file.close();
                return line;
            }
        }
        file.close();
        return line;
    }

#endif


const std::string SysInfo::getCpuType()
{
    #ifdef __linux__
        char CPUBrandString[0x40];
        unsigned int CPUInfo[4] = {0,0,0,0};
        
        __cpuid(0x80000000, CPUInfo[0], CPUInfo[1], CPUInfo[2], CPUInfo[3]);
        unsigned int nExIds = CPUInfo[0];
        
        std::memset(CPUBrandString, 0, sizeof(CPUBrandString));
        
        for (unsigned i = 0x80000000; i <= nExIds; ++i)
        {
            __cpuid(i, CPUInfo[0], CPUInfo[1], CPUInfo[2], CPUInfo[3]);
        
            if (i == 0x80000002)
                memcpy(CPUBrandString, CPUInfo, sizeof(CPUInfo));
            else if (i == 0x80000003)
                memcpy(CPUBrandString + 16, CPUInfo, sizeof(CPUInfo));
            else if (i == 0x80000004)
                memcpy(CPUBrandString + 32, CPUInfo, sizeof(CPUInfo));
        }
        // std::cout<<"CPU Model  : "<<CPUBrandString<<std::endl;
        return std::string(CPUBrandString);
    #elif _WIN32
        char CPUBrandString[0x40];
        unsigned int CPUInfo[4] = {0,0,0,0};

        __cpuid(CPUInfo, 0x80000000);
        unsigned nExIds = CPUInfo[0];

        for (unsigned i=0x80000000; i <= nExIds; ++i)
        {
            __cpuid(CPUInfo, i);

            if  (i == 0x80000002)
                memcpy(CPUBrandString, CPUInfo, sizeof(CPUInfo));
            else if  (i == 0x80000003)
                memcpy(CPUBrandString + 16, CPUInfo, sizeof(CPUInfo));
            else if  (i == 0x80000004)
                memcpy(CPUBrandString + 32, CPUInfo, sizeof(CPUInfo));
        }
        std::cout<<"CPU Model  : "<<CPUBrandString<<std::endl;
        return std::string(CPUBrandString);
    #endif
        return std::string {};
}


const std::string SysInfo::GetSystemInfo() 
{
    std::stringstream log;
    #ifdef __linux__
        log<<"CPU Vendor : "<<parse("/proc/cpuinfo", "vendor_id",   ":")<<"\n"
           <<"CPU Model  : "<<getCpuType()<<"\n"
           <<"RAM Total  : "<<parse("/proc/meminfo", "MemTotal",    ":")<<"\n"
           <<"RAM Free   : "<<parse("/proc/meminfo", "MemFree",     ":")<<"\n";
    #elif _WIN32
        log<<"CPU Model  : "<<getCpuType()<<"\n";
    #endif

    log<<"OS  Core   : "<<getOsName()<<"\n"
       <<"Built with : "<<getCompilerVersion()<<" "<<getCppVersion()<<"\n";
    
    return log.str();
}


SysInfo::SysInfo() {};
SysInfo::~SysInfo() {};
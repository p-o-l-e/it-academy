#pragma once
#include <unordered_map>
#include <string>

class SysInfo 
{
    private:
        inline static const std::unordered_map<long, std::string> cppversion 
        {
            { 202302L, "C++23" },
            { 202002L, "C++20" },
            { 201703L, "C++17" },
            { 201402L, "C++14" },
            { 201103L, "C++11" },
            { 199711L, "C++98" }
        };
        void trim(std::string&, const std::string&);
        const std::string parse(const std::string&, const std::string&, const std::string&);
        const std::string getCompilerVersion();
        const std::string getCppVersion();
        const std::string getCpuType();
        const std::string getOsName();

    public:
        const std::string GetSystemInfo();
        SysInfo();
       ~SysInfo();
};

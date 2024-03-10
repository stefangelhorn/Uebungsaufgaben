// Dies ist eine eigene Bibliothek, die nützliche, selbstgeschriebene Funktionen bereit hält
#include <iostream>
#include <limits> 
#include <sstream>
#include <string>

bool isNumber(const std::string& s)
{
    for(const auto c : s)
    {
        if(!(c >= '0' && c <= '9'))
        {
            return false;
        }
    }
    return true;
}

int safeIntInput(const std::string& text, int min = std::numeric_limits<int>::min(), int max = std::numeric_limits<int>::max())
{
    std::string input;

    do
    {
        std::cout << text;
        std::cin >> input;
    } while (isNumber(input) == false || std::stoi(input) < min || std::stoi(input) > max);
    
    return std::stoi(input);
}
#include <string>
#include <iostream>

int vvodbin()
{   std::string s;
    int size;
    do
    {
        std::getline(std::cin, s);
      
    } while (s.find_first_not_of("10") != std::string::npos);
    size=std::stoi(s);    
    return size;
}

int vvodunsignedint(int m)
{
    std::string s;
    do
    {
        if (m==1) std::cout << "Введите количество спортсменов:\n";
        if (m==2) std::cout << "Введите количество спортсменов, которых хотите добавить:\n";
        
        std::getline(std::cin, s);
    } while (s.find_first_not_of("0123456789") != std::string::npos);
    int x = std::stoi(s);
    return x;
}

float vvodfloat() {
    std::string s;
     do
    {
        std::getline(std::cin, s);
    } while (s.find_first_not_of("0123456789.") != std::string::npos);
    float x = std::stof(s);
    return x;
}



// #include <stdio.h>
// #include <stdlib.h>

//#include <unistd.h>


//#include "LR8.h"
#include "functionstask1.h"

//void input_data(Human *human);
//void print_data(Human *human, int &sportik_count);
//void allinone(Human *human);
// template <typename T>
// int prervan(T *human, int i, T *sportsmans);
// void dobavochka(Human *&sportsmans, int &sportik_count);
// bool compareage(Human &a, Human &b);
// template <typename RandomAccessIterator, typename Compare>
// void shellsortubyv(RandomAccessIterator first, RandomAccessIterator last, Compare comp);
// void morethantwenty(Human *sportsmans, int sportik_count);
// void deleteonestructure(Human *&sportsmans, int &sportik_count);
// void zamenadata(Human *&human, int &sportik_count);
// bool zagryzka(Human *&sportsmans, int &sportik_count);

int main()
{
    Human *sportsmans = nullptr;
    int sportik_count = 0;
    if (!zagryzka(sportsmans, sportik_count))
    {
        sportik_count = vvodunsignedint(1);
        sportsmans = (Human *)malloc(sizeof(Human) * sportik_count);
        for (int i = 0; i < sportik_count; ++i)
        {
            input_data(&sportsmans[i]);
            allinone(&sportsmans[i]);
        }
    }
    bool exit = false;
    menu(1);

    while (!exit)
    {
        int x;
        std::string s;

        do
        {
            std::cout << "Введите номер желаемой операции: ";
            std::getline(std::cin, s);
            x = std::atoi(s.c_str());
        } while (s.find_first_not_of("123456789") != std::string::npos || x < 1 || x > 9);

        switch (x)
        {
        case 1:
        {
            std::fstream clean("task1.bin", std::ios::out);
            clean.close();
            sportik_count = vvodunsignedint(1);
            free(sportsmans);
            sportsmans = (Human *)malloc(sizeof(Human) * sportik_count);
            int i = 0;
            while (i < sportik_count)
            {
                input_data(&sportsmans[i]);
                if (prervan(&sportsmans[i], i, sportsmans) && i < sportik_count)
                {
                    continue;
                }
                else
                {
                    // allinone(&sportsmans[i]);
                    ++i;
                }
            }
            break;
        }

        case 2:
            dobavochka(sportsmans, sportik_count);
            break;

        case 3:
            morethantwenty(sportsmans, sportik_count);
            break;

        case 4:
        {
            sort(sportsmans, sportik_count);
            break;
        }
        case 5:
            deleteonestructure(sportsmans, sportik_count);
            break;

        case 6:
            zamenadata(sportsmans, sportik_count);
            break;
        case 7:
            // for (int i = 0; i < sportik_count; ++i)
            // {
                print_data(sportsmans, sportik_count);
          //  }
            break;
        case 8:
            menu(1);
            break;
        case 9:
            exit = true;
            break;
        }
    }

    free(sportsmans);
    return 0;
}

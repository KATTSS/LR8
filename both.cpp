#include <string.h>
#include <iostream>
#include "sportsmans.h"

template <typename T>
int prervan(T *human, int i, T *sportsmans)
{
    for (int j = 0; j < i; ++j)
    {
        if (strcmp(sportsmans[j].name, sportsmans[i].name) == 0)
        {
            return 1;
        }
    }
    return 0;
}

void menu(int m)
{
    if (m==1)printf("Выберите желаемое действие:\n1-(пере)создать список спортсменов;\n2-добавить спортсменов;\n3-поиск ребят 20+;\n4-сортировка по убыванию возраста;\n5-удаление спортсмена;\n6-замена бойца;\n7-вывод на экран;\n8-меню;\n9 -выход.\n");
    else if (m==2) printf("Выберите желаемое действие:\n1-(пере)создать список;\n2-добавить в список;\n3-удаление со списка;\n4-замена бойца;\5-вывод на экран;\n6-меню;\n7 -выход.\n");
}

bool compareage(Human &a, Human &b)
{
    return a.age > b.age;
}

template <typename RandomAccessIterator, typename Compare>
void shellsortubyv(RandomAccessIterator first, RandomAccessIterator last, Compare comp)
{
    for (auto d = (last - first) / 2; d != 0; d /= 2)
        for (auto i = first + d; i != last; ++i)
            for (auto j = i; j - first >= d && comp(*j, *(j - d)); j -= d)
                std::swap(*j, *(j - d));
}

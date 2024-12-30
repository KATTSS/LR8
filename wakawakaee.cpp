#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <fstream>
#include <unistd.h>
#include "../LR7/headLr7.h"
#include "../LR7/input.cpp"
#include "LR8.h"
#include "both.cpp"

#include "sportsmans.h"

void input_data(Human *human);
void print_data(Human *human, int &sportik_count);
void allinone(Human *human);
template <typename T>
int prervan(T *human, int i, T *sportsmans);
void dobavochka(Human *&sportsmans, int &sportik_count);
bool compareage(Human &a, Human &b);
template <typename RandomAccessIterator, typename Compare>
void shellsortubyv(RandomAccessIterator first, RandomAccessIterator last, Compare comp);
void morethantwenty(Human *sportsmans, int sportik_count);
void deleteonestructure(Human *&sportsmans, int &sportik_count);
void zamenadata(Human *&human, int &sportik_count);
bool zagryzka(Human *&sportsmans, int &sportik_count);

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
            // x = std::stol(s.c_str(), nullptr, 10);
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
            shellsortubyv(sportsmans, sportsmans + sportik_count, compareage);
            std::cout << "Спортики по возрасту:\n";
            std::fstream file("task1.bin", std::ios::out | std::ios::binary);
            file.close();
            std::fstream filek("task1.bin", std::ios::app | std::ios::binary);
            for (int i = 0; i < sportik_count; ++i)
            {
                filek.write((char *)&sportsmans[i], sizeof(Human));
            }
            filek.close();
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

void print_data(Human *human, int &sportik_count)
{
    for (int i = 0; i < sportik_count; ++i)
    {
        printf("\nФИО: %s\n", human[i].name);
        printf("Страна происхождения: %s\n", human[i].country);

        if (human->yes_no == 1)
        {
            printf("Команда: %s\n", human[i].team.team);
            printf("Номер в команде: %d\n", human[i].nomerok.nomerok);
        }
        else
        {
            printf("Команда: %c\n", human[i].team.noteam);
            printf("Номер в команде: %c\n", human[i].nomerok.nonomerok);
        }

        printf("Возраст: %u\n", human[i].age);
        printf("Рост: %.2f\n", human[i].height);
        printf("Вес: %.2f\n", human[i].weight);
        printf("\nПолное описание: %s\n ", human[i].all);
    }
}

void dobavochka(Human *&sportsmans, int &sportik_count)
{
    int addamout = vvodunsignedint(2);
    Human *moresportsmans = (Human *)realloc(sportsmans, (sportik_count + addamout) * sizeof(Human));
    for (int i = sportik_count; i < sportik_count + addamout;)
    {
        input_data(&moresportsmans[i]);
        if (prervan(&moresportsmans[i], i, moresportsmans) && i < sportik_count)
        {
            continue;
        }
        else
        {
            allinone(&sportsmans[i]);
            ++i;
        }
    }
    sportik_count += addamout;
    sportsmans = moresportsmans;
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

void morethantwenty(Human *sportsmans, int sportik_count)
{
    printf("\n20+ :\n");
    for (int i = 0; i < sportik_count;)
    {
        sportsmans[i].age >= 20 ? print_data(&sportsmans[i], sportik_count), ++i : ++i;
    }
}

void deleteonestructure(Human *&sportsmans, int &sportik_count)
{
    char nametodelete[MAX_SIZE];
    printf("Введите имя кика: ");
    scanf("%99s", nametodelete);
    int c;
    while ((c = getchar()) != '\n' && c != EOF)
    {
    }
    int index = -1;
    int i = 0;
    while (i < sportik_count)
    {
        if (strcmp(sportsmans[i].name, nametodelete) == 0)
        {
            index = i;
            break;
        }
        ++i;
    }
    if (index == -1)
    {
        printf("Жертва кика не найдена...Вы уверены, что правильно её вписали?\n");
        return;
    }
    for (int j = index; j < sportik_count - 1; j++)
    {
        sportsmans[j] = sportsmans[j + 1];
    }
    Human *new_sportsmans = (Human *)realloc(sportsmans, (sportik_count - 1) * sizeof(Human));
    sportsmans = new_sportsmans;
    --sportik_count;
    // delete in bin(po syti perenos dannyx)
    std::fstream file("task1.bin", std::ios::in | std::ios::out | std::ios::binary);
    std::streampos pos_to_remove = index * static_cast<std::streampos>(sizeof(Human));
    file.seekg(0, std::ios::end);
    std::streampos file_size = file.tellg();
    if (pos_to_remove >= file_size)
    {
        std::cerr << "Некорректный индекс(быть такого не может!)" << std::endl;
        file.close();
        return;
    }
    std::streampos write_pos = pos_to_remove;
    std::streampos read_pos = pos_to_remove + static_cast<std::streampos>(sizeof(Human));
    const size_t buffer_size = sizeof(Human);
    char buffer[buffer_size];
    while (true)
    {
        file.seekg(read_pos);
        file.read(buffer, buffer_size);
        std::streamsize bytes_read = file.gcount();
        if (bytes_read == 0)
            break;
        file.seekp(write_pos);
        file.write(buffer, bytes_read);
        write_pos += bytes_read;
        read_pos += bytes_read;
    }
    file.close();
    truncate("task1.bin", write_pos);
}

void zamenadata(Human *&human, int &sportik_count)
{
    char nametochange[MAX_SIZE];
    printf("Введите имя кика: ");
    scanf("%99s", nametochange);
    int c;
    while ((c = getchar()) != '\n' && c != EOF)
    {
    }
    int i = 0;
    bool flag = false;
    while (i < sportik_count)
    {

        if (strcmp(human[i].name, nametochange) == 0)
        {
            printf("\nФИО: ");
            fgets(human->name, MAX_SIZE, stdin);
            human->name[strcspn(human->name, "\n")] = '\0';

            printf("Страна происхождения: ");
            fgets(human->country, MAX_SIZE, stdin);
            human->country[strcspn(human->country, "\n")] = '\0';

            printf("Спортсмен - член команды? (1-да; 0-нет): ");
            human->yes_no = vvodbin();

            if (human->yes_no == 1)
            {
                printf("Команда: ");
                fgets(human->team.team, MAX_SIZE, stdin);
                human->team.team[strcspn(human->team.team, "\n")] = '\0';

                printf("Номер в команде: ");
                human->nomerok.nomerok = vvodunsignedint(3);
            }
            else
            {
                human->team.noteam = '-';
                human->nomerok.nonomerok = '-';
            }

            printf("Возраст: ");
            human->age = vvodunsignedint(3);

            printf("Рост: ");
            human->height = vvodfloat();

            printf("Вес: ");
            human->weight = vvodfloat();

            allinone(human);

            std::fstream file("task1.bin", std::ios::in | std::ios::out | std::ios::binary);
            if (!file.is_open())
            {
                std::cerr << "Ошибка открытия файла" << std::endl;
                return;
            }
            std::streampos pos_to_update = i * static_cast<std::streampos>(sizeof(Human));

            file.seekg(0, std::ios::end);
            std::streampos file_size = file.tellg();
            if (pos_to_update >= file_size)
            {
                std::cerr << "Некорректный индекс (быть такого не может!)" << std::endl;
                file.close();
                return;
            }
            file.seekp(pos_to_update);
            file.write((char *)(&human[i]), sizeof(Human));
            file.close();

            ++i;
            flag = true;
        }
        else
            ++i;
    }
    if (!flag)
    {
        std::cout << "мимо, такого спортсмена нет, если забыли имена проверьте список ещё раз(7 пункт меню вам в помощь))\n";
        return;
    }
}

bool zagryzka(Human *&sportsmans, int &sportik_count)
{

    std::ifstream zagryzkaizbin("task1.bin", std::ios::binary | std::ios::ate);
    if (zagryzkaizbin.is_open())
    {
        std::streamsize size = zagryzkaizbin.tellg();
        zagryzkaizbin.seekg(0, std::ios::beg);
        sportik_count = size / sizeof(Human);
        sportsmans = (Human *)malloc(sizeof(Human) * sportik_count);
        if (sportsmans == nullptr)
        {
            std::cerr << "Ошибка выделения памяти" << std::endl;
        }

        zagryzkaizbin.read((char *)(sportsmans), size);
        if (!zagryzkaizbin)
        {
            std::cerr << "Ошибка чтения данных из файла." << std::endl;
            free(sportsmans);
        }
        zagryzkaizbin.close();
        return 1;
    }
    else
    {
        std::cout << "не считало файл\n";
        return 0;
    }
}
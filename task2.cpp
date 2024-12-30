
#include <iostream>
#include <fstream>
#include <stdio.h>

#include "../LR7/headLr7.h"
#include "../LR7/input.cpp"
// #include "wakawakaee.cpp"
#include "LR8.h"
#include "both.cpp"
#define MAX_SIZE 100

typedef struct rab
{
    short day;
    short month;
    int year;
    int otdel;
    char post[MAX_SIZE];
    char name[MAX_SIZE];
    char begdata[MAX_SIZE];
} Rab;

void dataofbeg(Rab *rab);
void input_data_2(Rab *rab);
void zapis(Rab *&rab, int &rab_count);
void print_data(const Rab *rab);
void dobavochka(Rab *&rab, int &rab_count);

int main()
{
    // read
    /* std::ofstream fout;
     fout.open("task2.txt", std::ofstream::app);

     if(!fout.is_open()) std::cout<< "\nне удалось открыть txt\n";
     else fout<< "\nданные\n";

     fout.close();
     */
    //
    int rab_count = 0;
    Rab* rab=nullptr;
    long structplase = 0;
    std::ifstream fin;
    fin.open("task2.txt");

    if (!fin.is_open())
        std::cout << "\nне удалось открыть txt\n";
    fin.seekg(0, std::ios::end);
        if (fin.tellg() == 0)
        {
            std::cerr << "Файл пуст.\n";
            fin.close();
            zapis(rab, rab_count);
        }
        else{
        std::cout << "\nданные\n";
        

        // while(fin.get(ch) ) {
        //     std::cout<<ch;
        // }
        std::string s = "";
        fin >> s;
        rab_count = std::stoi(s);
        std::cout << rab_count;
        structplase = fin.tellg();
    }
    rab = (Rab *)malloc(sizeof(Rab) * rab_count);
    fin.seekg(structplase);
    for (int i = 0; i < rab_count; ++i)
    {
        fin >> rab[i].day >> rab[i].month >> rab[i].year >> rab[i].otdel >> rab[i].post >> rab[i].name;
        dataofbeg(&rab[i]);
    }

    fin.close();

    menu(2);
    bool exit = false;

    while (!exit)
    {
        int x;
        std::string s;

        do
        {
            std::cout << "Введите номер желаемой операции: ";
            std::getline(std::cin, s);
            x = std::stol(s.c_str(), nullptr, 10);
        } while (s.find_first_not_of("1234567") != std::string::npos || x < 1 || x > 7);

        switch (x)
        {
        case 1:
            zapis(rab, rab_count);
            break;
        case 2:
            dobavochka(rab, rab_count);
            break;
        case 3:

            break;
        case 4:
            break;
        case 5:
            print_data(rab);
            break;
        case 6:
            menu(2);
            break;
        case 7:
            exit = true;
            break;
        }
    }

    return 0;
}

void dataofbeg(Rab *rab)
{
    snprintf(rab->begdata, sizeof(rab->begdata), "Первый день работы: %d.%d.%dг.",
             rab->day, rab->month, rab->year);
}

void zapis(Rab *&rab, int &rab_count)
{
    std::fstream clean("task2.txt", std::ios::out);
    rab_count = vvodunsignedint(1);
    clean << rab_count << '\n';

    free(rab);
    rab = (Rab *)malloc(sizeof(Rab) * rab_count);
    int i = 0;
    while (i < rab_count)
    {
        input_data_2(&rab[i]);
        if (prervan(&rab[i], i, rab) && i < rab_count)
        {
            continue;
        }
        else
        {
            dataofbeg(&rab[i]);
            ++i;
        }
    }
    for (int i = 0; i < rab_count; ++i)
    {
        clean << rab[i].day << '\n'
              << rab[i].month << '\n'
              << rab[i].year << '\n'
              << rab[i].otdel << '\n'
              << rab[i].post << '\n'
              << rab[i].name << '\n'
              << rab[i].begdata << '\n';
    }
    clean.close();
}

void input_data_2(Rab *rab)
{
    printf("\nФИО: ");
    fgets(rab->name, MAX_SIZE, stdin);
    rab->name[strcspn(rab->name, "\n")] = '\0';

    printf("Должность: ");
    fgets(rab->post, MAX_SIZE, stdin);
    rab->post[strcspn(rab->post, "\n")] = '\0';

    printf("Номер отдела: ");
    rab->otdel = vvodunsignedint(3);

    printf("День: ");
    rab->day = (short)vvodunsignedint(3);

    printf("Месяц: ");
    rab->month = (short)vvodunsignedint(3);

    printf("Год: ");
    rab->year = vvodunsignedint(3);
}

void print_data(const Rab *rab)
{
    printf("\nФИО: %s\n", rab->name);
    printf("Должность: %s\n", rab->post);
    printf("Номер отдела: %d\n", rab->otdel);
    printf("\nНачало работы: %s\n ", rab->begdata);
}

void dobavochka(Rab *&rab, int &rab_count)
{
    int addamout = vvodunsignedint(2);
    Rab *moresportsmans = (Rab*)realloc(rab, (rab_count + addamout) * sizeof(Rab));
    for (int i = rab_count; i < rab_count + addamout; ++i)
    {
        input_data_2(&moresportsmans[i]);
        if (prervan(&moresportsmans[i], i, moresportsmans) && i < rab_count)
        {
            continue;
        }
        else
        {
            dataofbeg(&rab[i]);
            ++i;
        }
        std::ofstream ofs("task1.bin", std::ios::app );
       for (int i = rab_count; i < rab_count+addamout; ++i)
    {
        ofs << rab[i].day << '\n'
              << rab[i].month << '\n'
              << rab[i].year << '\n'
              << rab[i].otdel << '\n'
              << rab[i].post << '\n'
              << rab[i].name << '\n'
              << rab[i].begdata << '\n';
    }
        ofs.close();
    }
    rab_count += addamout;
    rab = moresportsmans;
}

void deletion (Rab *&rab, int & rab_count) {
    char nametodelete[MAX_SIZE];
    printf("Введите имя кика: ");
    scanf("%99s", nametodelete);
    int index = -1;
    int i = 0;
    while (i < rab_count)
    {
        if (strcmp(rab[i].name, nametodelete) == 0)
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
    for (int j = index; j < rab_count - 1; j++)
    {
        rab[j] = rab[j + 1];
    }
    Rab *new_sportsmans = (Rab *)realloc(rab, (rab_count - 1) * sizeof(Rab));
    rab = new_sportsmans;
    --rab_count;
    
}


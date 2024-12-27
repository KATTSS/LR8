#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include "../LR7/headLr7.h"
#include "../LR7/input.cpp"

#define MAX_SIZE 100

typedef union
{
    char team[MAX_SIZE];
    char noteam;
} Team;

typedef union
{
    int nomerok;
    char nonomerok;
} Nomerok;

typedef struct
{
    char name[MAX_SIZE];
    char country[MAX_SIZE];
    int yes_no;
    Team team;
    Nomerok nomerok;
    unsigned age;
    float height;
    float weight;
    char all[MAX_SIZE * 3];
} Human;

void input_data(Human *human);
void print_data(const Human *human);
void allinone(Human *human);
int prervan(Human *human, int i, Human *sportsmans);
void dobavochka(Human *&sportsmans, int &sportik_count);
bool compareage(Human &a, Human &b);
template <typename RandomAccessIterator, typename Compare>
void shell_sort(RandomAccessIterator first, RandomAccessIterator last, Compare comp);
void morethantwenty(Human *sportsmans, int sportik_count);
void deleteonestructure(Human *&sportsmans, int &sportik_count);
template <typename T>
void update_field(const std::string &prompt, T &field);
void zamenka_na_borty(Human *sportsmans, int sportik_count);

int main()
{

    int sportik_count = vvodunsignedint(1);

    Human *sportsmans = (Human *)malloc(sizeof(Human) * sportik_count);
    int i = 0;
    while (i < sportik_count)
    {
        input_data(&sportsmans[i]);
        if (prervan(&sportsmans[i], i, sportsmans) && i < sportik_count)
        {
            continue;
        }
        else
            ++i;
    }
    // dobavochka(sportsmans, sportik_count);
    //  allinone(&sportsmans[0]);
    //  for (int i = 0; i < sportik_count; ++i)
    //  {
    //      print_data(&sportsmans[i]);
    //  }
    // shell_sort(sportsmans, sportsmans + sportik_count, compareage);
    deleteonestructure(sportsmans, sportik_count);
    for (int i = 0; i < sportik_count; ++i)
    {
        print_data(&sportsmans[i]);
    }
    // morethantwenty(sportsmans, sportik_count);
    zamenka_na_borty(sportsmans, sportik_count);
    for (int i = 0; i < sportik_count; ++i)
    {
        print_data(&sportsmans[i]);
    }
    free(sportsmans);
    return 0;
}

void input_data(Human *human)
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
        scanf("%d", &human->nomerok.nomerok);
        getchar();
    }
    else
    {
        human->team.noteam = '-';
        human->nomerok.nonomerok = '-';
    }

    printf("Возраст: ");
    scanf("%u", &human->age);
    getchar();

    printf("Рост: ");
    scanf("%f", &human->height);
    getchar();

    printf("Вес: ");
    scanf("%f", &human->weight);
    getchar();
}

void allinone(Human *human)
{
    snprintf(human->all, sizeof(human->all), "Name: %s, Country: %s, Age: %u, Height: %.2f, Weight: %.2f",
             human->name, human->country, human->age, human->height, human->weight);
}

void print_data(const Human *human)
{
    printf("\nФИО: %s\n", human->name);
    printf("Страна происхождения: %s\n", human->country);

    if (human->yes_no == 1)
    {
        printf("Команда: %s\n", human->team.team);
        printf("Номер в команде: %d\n", human->nomerok.nomerok);
    }
    else
    {
        printf("Команда: %c\n", human->team.noteam);
        printf("Номер в команде: %c\n", human->nomerok.nonomerok);
    }

    printf("Возраст: %u\n", human->age);
    printf("Рост: %.2f\n", human->height);
    printf("Вес: %.2f\n", human->weight);
    printf("\nПолное описание: %s\n: ", human->all);
}

int prervan(Human *human, int i, Human *sportsmans)
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

void dobavochka(Human *&sportsmans, int &sportik_count)
{
    int addamout = vvodunsignedint(2);
    Human *moresportsmans = (Human *)realloc(sportsmans, (sportik_count + addamout) * sizeof(Human));
    for (int i = sportik_count; i < sportik_count + addamout; ++i)
    {
        input_data(&moresportsmans[i]);
    }
    sportik_count += addamout;
    sportsmans = moresportsmans;
}

bool compareage(Human &a, Human &b)
{
    return a.age > b.age;
}

template <typename RandomAccessIterator, typename Compare>
void shell_sort(RandomAccessIterator first, RandomAccessIterator last, Compare comp)
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
        sportsmans[i].age >= 20 ? print_data(&sportsmans[i]), ++i : ++i;
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
}
// отредачить функцию замены и идти дальше
void zamenka_na_borty(Human *sportsmans, int sportik_count)
{
    printf("Введите имя спортсмена, инфу по которому желаете изменить: ");
    char name[MAX_SIZE];
    scanf("%99s", name);
    int c;
    while ((c = getchar()) != '\n' && c != EOF)
    {
    }
    name[MAX_SIZE - 1] = '\0';
    for (int i = 0; i < sportik_count; ++i)
    {
        if (strcmp(sportsmans[i].name, name) == 0)
        {
            update_field("ФИО: ", sportsmans[i].name);
            update_field("Страна: ", sportsmans[i].country);
            update_field("Член команды?: ", sportsmans[i].yes_no);
            if (sportsmans[i].yes_no == 1)
            {
                update_field("Команда", sportsmans[i].team.team);
                update_field("Номер в команде", sportsmans[i].nomerok.nomerok);
            }
            update_field("Возраст: ", sportsmans[i].age);
            update_field("Рост: ", sportsmans[i].height);
            update_field("Вес: ", sportsmans[i].weight);
            allinone(&sportsmans[i]);
            return;
        }
    }
    printf("Cпортик с таким именем %s не найден.\n", name);
}

template <typename T>
void update_field(const std::string &prompt, T &field)
{
    std::string input;
    std::cout << prompt << " (" << field << "): ";
    std::getline(std::cin, input);
    if (!input.empty())
    {
        if constexpr (std::is_same_v<T, std::string>)
        {
            strncpy(field, input.c_str(), MAX_SIZE - 1);
            field[MAX_SIZE - 1] = '\0';
        }
        else if constexpr (std::is_same_v<T, int> || std::is_same_v<T, unsigned int>)
        {
            field = std::stoi(input);
        }
        else if constexpr (std::is_same_v<T, float>)
        {
            field = std::stof(input);
        }
    }
}

void menu()
{
    printf("Выберите желаемое действие:\n1-создать список спортсменов;\n2-добавить спортсменов;\n3-поиск ребят 20+;\n4-сортировка по убыванию возраста;\n5-удаление спортсмена;\n6-вывести список на экран;\n7-меню;8-выход\n");
}
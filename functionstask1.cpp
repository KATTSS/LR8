#include "input.h"
#include "sportsmans.h"

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
    std::ofstream ofs("task1.bin", std::ios::app | std::ios::binary);
    ofs.write((char *)human, sizeof(*human));
    ofs.close();
}

void allinone(Human *human)
{
    snprintf(human->all, sizeof(human->all), "ФИО: %s, Страна: %s, Возраст: %u, Рост: %.2f, Вес: %.2f",
             human->name, human->country, human->age, human->height, human->weight);
}

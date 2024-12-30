#define MAX_SIZE 100

typedef union
{
    char noteam;
    char team[MAX_SIZE];
} Team;

typedef union
{
    char nonomerok;
    int nomerok;
} Nomerok;

typedef struct
{

    int yes_no;
    float height;
    float weight;
    Nomerok nomerok;
    unsigned age;
    Team team;
    char name[MAX_SIZE];
    char country[MAX_SIZE];
    char all[MAX_SIZE * 3];
} Human;
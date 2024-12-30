#include "input.h"
#include "sportsmans.h"
#include "LR8.h"
#include <fstream>
#include <unistd.h>

void input_data(Human *human);
void print_data(Human *human, int &sportik_count);
void allinone(Human *human);
void morethantwenty(Human *sportsmans, int sportik_count);
void dobavochka(Human *&sportsmans, int &sportik_count);
void deleteonestructure(Human *&sportsmans, int &sportik_count);
void zamenadata(Human *&human, int &sportik_count);
bool zagryzka(Human *&sportsmans, int &sportik_count);
void sort (Human*&sportsmans, int &sportik_count);

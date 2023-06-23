#include "main.h"

void random_food(point_t *food)
{
	food->y = (rand() % ((ROWS - 2) - (1 + 1)) + 1);
	food->x = (rand() % ((COLUMNS - 2) - (1 + 1)) + 1);
}

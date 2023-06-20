#include "main.h"

int init_playground(playground_t *playground)
{
	if (init_snake(&(playground->snake)))
		return (1);

	return (0);
}

void refresh_playground(playground_t *playground)
{
	pointnode_t *head;
	int row, column;;

	for (row = 0; row < ROWS; row++)
	{
		if (row == 0 || row == ROWS - 1)
		{
			for (column = 0; column < COLUMNS; column++)
				(playground->grid)[row][column] = BLOCK;

			continue;
		}

		(playground->grid)[row][0] = BLOCK;

		for (column = 1; column < COLUMNS - 1; column++)
			(playground->grid)[row][column] = '\0';

		(playground->grid)[row][COLUMNS - 1] = BLOCK;
	}

	head = playground->snake.head;

	while (head)
	{
		point_t *point = &(head->point);

		if (head->prev)
			(playground->grid)[point->y][point->x] = SNAKE_BODY;
		else
		{
			switch ((playground->grid)[point->y][point->x])
			{
				case BLOCK:
					game_over = true;
					return;
				default:
					(playground->grid)[point->y][point->x] = SNAKE_HEAD;
			}
		}

		head = head->next;
	}
}

void render_playground(playground_t *playground)
{
	int row, column;


	refresh_playground(playground);

	if (game_over)
		return;

	system("clear");

	for (row = 0; row < ROWS; row++)
	{
		for (column = 0; column < COLUMNS; column++)
		{

			switch ((playground->grid)[row][column])
			{
				case SNAKE_HEAD:
					printf(BOX_LIGHT_3);
					break;
				case SNAKE_BODY:
					printf(BOX_LIGHT_2);
					break;
				case BLOCK:
					printf(BOX);
					break;
				default:
					printf(BOX_LIGHT_1);
			}
		}

		printf("\n");
	}
}

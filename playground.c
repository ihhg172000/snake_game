#include "main.h"

playground_t *init_playground()
{
	playground_t *playground;

	playground = malloc(sizeof(playground_t));

	if (!playground)
		return (NULL);

	playground->grid = init_grid(ROWS, COLUMNS);

	if (!playground->grid)
	{
		free(playground);
		return (NULL);
	}

	playground->snake = init_snake();

	if (!playground->snake)
	{
		free_grid(playground->grid);
		free(playground);
		return (NULL);
	}

	return (playground);
}

void refresh_playground(playground_t *playground)
{
	grid_t *grid;
	pointnode_t *head;
	int row, column;

	grid = playground->grid;

	for (row = 0; row < grid->rows; row++)
	{
		if (row == 0 || row == grid->rows - 1)
		{
			for (column = 0; column < grid->columns; column++)
				(grid->p)[row][column] = BLOCK;

			continue;
		}

		(grid->p)[row][0] = BLOCK;

		for (column = 1; column < grid->columns - 1; column++)
			(grid->p)[row][column] = '\0';

		(grid->p)[row][grid->columns - 1] = BLOCK;
	}

	head = playground->snake->head;

	while (head)
	{
		point_t *point = head->point;

		if (head->prev)
			(grid->p)[point->y][point->x] = SNAKE_BODY;
		else
			(grid->p)[point->y][point->x] = SNAKE_HEAD;

		head = head->next;
	}

}

void render_playground(playground_t *playground)
{
	int row, column;

	system("clear");
	refresh_playground(playground);

	for (row = 0; row < playground->grid->rows; row++)
	{
		for (column = 0; column < playground->grid->columns; column++)
		{

			switch ((playground->grid->p)[row][column])
			{
				case SNAKE_HEAD:
					printf(CYN BOX_LIGHT_3 RESET);
					break;
				case SNAKE_BODY:
					printf(CYN BOX RESET);
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

void free_playground(playground_t *playground)
{
	free_grid(playground->grid);
	free_snake(playground->snake);
	free(playground);
}

#include "main.h"

grid_t *init_grid(int rows, int columns)
{
	grid_t *grid;
	int row;

	grid = malloc(sizeof(grid_t));

	if (!grid)
		return (NULL);

	grid->p = malloc(rows * sizeof(char *));

	if (!(grid->p))
	{
		free(grid);
		return (NULL);
	}

	grid->rows = rows;
	grid->columns = columns; 

	for (row = 0; row < grid->rows; row++)
	{
		(grid->p)[row] = malloc(grid->columns * sizeof(char));

		if (!(grid->p[row]))
		{
			free_grid(grid);
			return (NULL);
		}
	}

	return (grid);
}

void free_grid(grid_t *grid)
{
	int row;

	for (row = 0; row < grid->rows; row++)
		free((grid->p)[row]);

	free(grid->p);
	free(grid);
}

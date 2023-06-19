#include "main.h"

int main(void)
{
	playground_t *playground;

	playground = init_playground();

	if (!playground)
		exit(EXIT_FAILURE);

	/* test snake movement */

	for (int i = 0; i < 20; i++)
	{
		render_playground(playground);

		if (i == 5)
		{
			change_snake_direction(playground->snake, DOWN);
			change_snake_direction(playground->snake, UP);
			increase_snake(playground->snake);
		}


		if (i == 10)
		{
			change_snake_direction(playground->snake, RIGHT);
			increase_snake(playground->snake);
		}

		move_snake_forword(playground->snake);

		usleep(100000);
	}

	/* ____________________ */

	free_playground(playground);

	return (EXIT_SUCCESS);
}

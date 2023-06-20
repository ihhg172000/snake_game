#include "main.h"

void *keys_handler(void *playground)
{
	playground_t *pg;

	pg = (playground_t *) playground;

	while (true)
	{
		int ch;

		ch = getchar();

		switch (ch)
		{
			case 'q':
				return (NULL);
			case 'w':
				change_snake_direction(&(pg->snake), UP);
				break;
			case 's':
				change_snake_direction(&(pg->snake), DOWN);
				break;
			case 'a':
				change_snake_direction(&(pg->snake), LEFT);
				break;
			case 'd':
				change_snake_direction(&(pg->snake), RIGHT);
		}
	}

	return (NULL);
}

void *render_handler(void *playground)
{
	playground_t *pg = (playground_t *) playground;
	while (!game_over)
	{
		render_playground(pg);
		move_snake_forword(&(pg->snake));
		usleep(100000);
	}

	return (NULL); 
}

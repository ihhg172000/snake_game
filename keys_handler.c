#include "main.h"


int keys(playground_t *playground, char ch);
int arrow_keys(playground_t *playground, char ch);

void *keys_handler(void *playground)
{
	playground_t *pg = (playground_t *) playground;

	while (true)
	{
		char ch = getchar();

		if (keys(pg, ch))
		{
			status.game_over = true;
			return (NULL);
		}
	}
}

int keys(playground_t *playground, char ch)
{
	switch (ch)
	{
		case 'q':
			return (1);
		case 'w':
			change_snake_direction(&(playground->snake), UP);
			break;
		case 's':
			change_snake_direction(&(playground->snake), DOWN);
			break;
		case 'd':
			change_snake_direction(&(playground->snake), RIGHT);
			break;
		case 'a':
			change_snake_direction(&(playground->snake), LEFT);
			break;
		case 27:
			ch = getchar();

			if (arrow_keys(playground, ch))
			{
				return (keys(playground, ch));
			}
	}

	return (0);
}

int arrow_keys(playground_t *playground, char ch)
{
	if (ch == '[')
	{
		ch = getchar();

		switch (ch)
		{
			case 'A':
				change_snake_direction(&(playground->snake), UP);
				break;
			case 'B':
				change_snake_direction(&(playground->snake), DOWN);
				break;
			case 'C':
				change_snake_direction(&(playground->snake), RIGHT);
				break;
			case 'D':
				change_snake_direction(&(playground->snake), LEFT);
		}
	}
	else
	{
		return (1);
	}

	return (0);
}

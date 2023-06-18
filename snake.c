#include "main.h"

snake_t *init_snake()
{
	snake_t *snake = NULL;
	int i;

	for (i = 1; i <= INIT_SNAKE_POS_X; i++)
	{
		if (!grow_snake(&snake))
		{
			free_snake(snake);
			return (NULL);
		}
	}

	return (snake);
}

snake_t *grow_snake(snake_t **snake)
{
	snake_t *curr, *new;

	new = malloc(sizeof(snake_t));

	if (!new)
		return (NULL);

	new->point = malloc(sizeof(point_t));

	if (!(new->point))
	{
		free(new);
		return (NULL);
	}

	new->point->x = INIT_SNAKE_POS_X;
	new->point->y = INIT_SNAKE_POS_Y;
	new->next_direction = RIGHT;
	new->prev_direction = RIGHT;
	new->next = NULL;
	new->prev = NULL;

	if (!(*snake))
	{
		*snake = new;
		return (new);
	}

	curr = *snake;

	while (curr->next)
		curr = curr->next;

	switch (curr->next_direction)
	{
		case RIGHT:
			new->point->x = (curr->point)->x - 1;
			new->point->y = curr->point->y;
			break;
		case LEFT:
			new->point->x = curr->point->x + 1;
			new->point->y = curr->point->y;
			break;
		case UP:
			new->point->x = curr->point->x;
			new->point->y = curr->point->y + 1;
			break;
		case DOWN:
			new->point->x = curr->point->x;
			new->point->y = curr->point->y - 1;
			break;
		default:
	}

	new->next_direction = curr->next_direction;
	new->prev_direction = curr->next_direction;
	
	curr->next = new;
	new->prev = curr;

	return (new);
}

void move_snake_forword(snake_t *snake)
{
	while (snake)
	{
		switch (snake->next_direction)
		{
			case RIGHT:
				snake->point->x++;
				break;
			case LEFT:
				snake->point->x--;
				break;
			case UP:
				snake->point->y--;
				break;
			case DOWN:
				snake->point->y++;
				break;
			default:
		}

		snake->prev_direction = snake->next_direction;

		if (snake->prev && snake->prev_direction != snake->prev->prev_direction)
		{
			snake->next_direction = snake->prev->prev_direction;
		}

		snake = snake->next;
	}
}

void change_snake_direction(snake_t *snake, char direction)
{
	switch (direction)
	{
		case RIGHT:
		case LEFT:
			if (snake->next_direction == UP || snake->next_direction == DOWN)
				snake->next_direction = direction;
			break;
		case UP:
		case DOWN:
			if (snake->next_direction == RIGHT || snake->next_direction == LEFT)
				snake->next_direction = direction;
			break;
		default:
	}
}

void free_snake(snake_t *snake)
{
	snake_t *next;

	while (snake)
	{
		next = snake->next;
		free(snake->point);
		free(snake);
		snake = next;
	}
}

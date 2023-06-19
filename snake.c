#include "main.h"

snake_t *init_snake()
{
	snake_t *snake;
	int i;

	snake = malloc(sizeof(snake_t));

	if (!snake)
		return (NULL);

	snake->head = NULL;
	snake->direction = RIGHT;

	for (i = 0; i < 5; i++)
	{
		if (!increase_snake(snake))
		{
			free_snake(snake);
			return (NULL);
		}
	}

	return (snake);
}

pointnode_t *increase_snake(snake_t *snake)
{
	pointnode_t *new;

	new = malloc(sizeof(pointnode_t));

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
	new->next = NULL;
	new->prev = NULL;

	if (!(snake->head))
	{
		snake->head = new;
		return (new);
	}

	switch (snake->direction)
	{
		case RIGHT:
			new->point->x = snake->head->point->x + 1;
			new->point->y = snake->head->point->y;
			break;
		case LEFT:
			new->point->x = snake->head->point->x - 1;
			new->point->y = snake->head->point->y;
			break;
		case UP:
			new->point->x = snake->head->point->x;
			new->point->y = snake->head->point->y - 1;
			break;
		case DOWN:
			new->point->x = snake->head->point->x;
			new->point->y = snake->head->point->y + 1;
			break;
		default:
	}

	new->next = snake->head;
	snake->head->prev = new;

	snake->head = new;

	return (new);
}

void move_snake_forword(snake_t *snake)
{
	pointnode_t *curr;
	point_t target_position, current_position;

	target_position.x = snake->head->point->x;
	target_position.y = snake->head->point->y;

	switch (snake->direction)
	{
		case RIGHT:
			snake->head->point->x++;
			break;
		case LEFT:
			snake->head->point->x--;
			break;
		case UP:
			snake->head->point->y--;
			break;
		case DOWN:
			snake->head->point->y++;
			break;
		default:
	}

	curr = snake->head->next;

	while (curr)
	{
		current_position.x = curr->point->x;
		current_position.y = curr->point->y;

		curr->point->x = target_position.x;
		curr->point->y = target_position.y;

		target_position = current_position;

		curr = curr->next;
	}
}

void change_snake_direction(snake_t *snake, char direction)
{
	switch (direction)
	{
		case RIGHT:
		case LEFT:
			if (snake->direction == UP || snake->direction == DOWN)
				snake->direction = direction;
			break;
		case UP:
		case DOWN:
			if (snake->direction == RIGHT || snake->direction == LEFT)
				snake->direction = direction;
			break;
		default:
	}
}

void free_snake(snake_t *snake)
{
	pointnode_t *next;

	while (snake->head)
	{
		next = snake->head->next;
		free(snake->head->point);
		free(snake->head);

		snake->head = next;
	}

	free(snake);
}

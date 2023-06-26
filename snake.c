#include "main.h"

int init_snake(snake_t *snake)
{
	snake->head = NULL;
	snake->requested_direction = RIGHT;
	snake->direction = RIGHT;

	for (int i = 0; i < 5; i++)
	{
		if (increase_snake(snake))
		{
			free_points(snake->head);
			return (1);
		}

		move_snake(snake);
	}

	return (0);
}

int increase_snake(snake_t *snake)
{
	pointnode_t *new;

	new = new_point(INIT_SNAKE_POS_Y, INIT_SNAKE_POS_X);

	if (!new)
		return (1);

	if (!(snake->head))
	{
		snake->head = new;
		snake->tail = new;
		return (0);
	}

	switch (snake->direction)
	{
		case RIGHT:
			new->point.x = snake->tail->point.x - 1;
			new->point.y = snake->tail->point.y;
			break;
		case LEFT:
			new->point.x = snake->tail->point.x + 1;
			new->point.y = snake->tail->point.y;
			break;
		case UP:
			new->point.x = snake->tail->point.x;
			new->point.y = snake->tail->point.y + 1;
			break;
		case DOWN:
			new->point.x = snake->tail->point.x;
			new->point.y = snake->tail->point.y - 1;
			break;
	}

	snake->tail->next = new;
	new->prev = snake->tail;

	snake->tail = new;

	return (0);
}

void move_snake(snake_t *snake)
{
	pointnode_t *curr;
	point_t target_position, current_position;

	target_position.x = snake->head->point.x;
	target_position.y = snake->head->point.y;

	switch (snake->requested_direction)
	{
		case RIGHT:
			snake->head->point.x++;
			break;
		case LEFT:
			snake->head->point.x--;
			break;
		case UP:
			snake->head->point.y--;
			break;
		case DOWN:
			snake->head->point.y++;
			break;
	}

	snake->direction = snake->requested_direction;

	curr = snake->head->next;

	while (curr)
	{
		current_position.x = curr->point.x;
		current_position.y = curr->point.y;

		curr->point.x = target_position.x;
		curr->point.y = target_position.y;

		target_position = current_position;

		curr = curr->next;
	}
}

void change_snake_direction(snake_t *snake, direction_t direction)
{
	switch (direction)
	{
		case RIGHT:
		case LEFT:
			if (snake->direction == UP || snake->direction == DOWN)
				snake->requested_direction = direction;
			break;
		case UP:
		case DOWN:
			if (snake->direction == RIGHT || snake->direction == LEFT)
				snake->requested_direction = direction;
	}
}

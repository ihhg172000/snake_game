#include "main.h"

pointnode_t *new_point(int y, int x)
{
	pointnode_t *new;

	new = malloc(sizeof(pointnode_t));

	if (!new)
		return (NULL);

	new->point.y = y;
	new->point.x = x;

	new->next = NULL;
	new->prev = NULL;

	return (new);
}

void free_points(pointnode_t *head)
{
	pointnode_t *next;

	while (head)
	{
		next = head->next;
		free(head);
		head = next;
	}
}

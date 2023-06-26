#include "main.h"

void *render_handler(void *playground)
{
	playground_t *pg = (playground_t *) playground;
	while (!status.game_over)
	{
		render_playground(pg);
		move_snake(&(pg->snake));
		usleep(100000);
	}

	return (NULL); 
}

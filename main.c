#include "main.h"

bool game_over = false;

int main(void)
{
	playground_t playground;
	pthread_t keys_thread;

	if (init_playground(&playground))
		exit(EXIT_FAILURE);

	terminal_row_mode();

	if (pthread_create(&keys_thread, NULL, &keys_handler, (void *) &playground) != 0)
		exit(EXIT_FAILURE);

	render_handler(&playground);	

	if (pthread_join(keys_thread, NULL) != 0)
		exit(EXIT_FAILURE);

	terminal_normal_mode();

	free_pointlist(playground.snake.head);

	system("clear");

	return (EXIT_SUCCESS);
}

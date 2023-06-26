#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#include <termios.h>
#include <pthread.h>
#include <time.h>
#include "art.h"


/* graphics  */

#define RED   "\x1B[31m"
#define GRN   "\x1B[32m"
#define YEL   "\x1B[33m"
#define BLU   "\x1B[34m"
#define MAG   "\x1B[35m"
#define CYN   "\x1B[36m"
#define WHT   "\x1B[37m"
#define RESET "\x1B[0m"

#define BOX "\u2588\u2588"
#define BOX_LIGHT_3 "\u2593\u2593"
#define BOX_LIGHT_2 "\u2592\u2592"
#define BOX_LIGHT_1 "\u2591\u2591"


/* playground dimensions */

#define ROWS 20
#define COLUMNS 41


/* init snake position & size */

#define INIT_SNAKE_POS_Y 1
#define INIT_SNAKE_POS_X 1
#define INIT_SNAKE_SIZE 5

/* symbols */

#define SNAKE_HEAD '*'
#define SNAKE_BODY '.'
#define BLOCK '#'
#define FOOD '$'


/* status */

typedef struct status_s
{
	unsigned int score;
	bool game_over;
} status_t;

extern status_t status;


/* points */

typedef struct point
{
	int x;
	int y;
} point_t;

typedef struct pointnode_s
{
	point_t point;

	struct pointnode_s *prev;
	struct pointnode_s *next;
} pointnode_t;

pointnode_t *new_point(int y, int x);
void free_points(pointnode_t *head);


/* snake */

typedef enum
{
	RIGHT,
	LEFT,
	UP,
	DOWN
} direction_t;

typedef struct snake_s
{
	pointnode_t *head;
	pointnode_t *tail;
	direction_t requested_direction;
	direction_t direction;
} snake_t;

int init_snake();
int increase_snake(snake_t *snake);
void move_snake(snake_t *snake);
void change_snake_direction(snake_t *snake, direction_t direction);


/* food */

void random_food(point_t *food);


/* playground */

typedef struct playground_s
{
	char grid[ROWS][COLUMNS];
	snake_t snake;
	point_t food;
} playground_t;

int init_playground(playground_t *playground);
void clear_playground(playground_t *playground);
void refresh_playground(playground_t *playground);
void render_playground(playground_t *playground);


/* terminal mode */

void terminal_row_mode();
void terminal_normal_mode();


/* handlers */

void *keys_handler(void *playground);
void *render_handler(void *playground);

#endif /* MAIN_H */

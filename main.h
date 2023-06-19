#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

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

#define ROWS 16
#define COLUMNS 32

/* init snake position */

#define INIT_SNAKE_POS_X 1
#define INIT_SNAKE_POS_Y 1

/* symbols */

#define SNAKE_HEAD '*'
#define SNAKE_BODY '.'
#define BLOCK '#'

/* direction */

#define RIGHT 'r'
#define LEFT 'l'
#define UP 'u'
#define DOWN 'd'

typedef struct point
{
	int x;
	int y;
} point_t;

typedef struct pointnode
{
	point_t *point;

	struct pointnode *prev;
	struct pointnode *next;
} pointnode_t;

typedef struct snake
{
	pointnode_t *head;
	char direction;
} snake_t;

snake_t *init_snake();
pointnode_t *increase_snake(snake_t *snake);
void move_snake_forword(snake_t *snake);
void change_snake_direction(snake_t *snake, char direction);
void free_snake(snake_t *snake);

typedef struct grid
{
	char **p;
	int rows;
	int columns;
} grid_t;

grid_t *init_grid(int rows, int columns);
void free_grid(grid_t *grid);

typedef struct playground
{
	grid_t *grid;
	snake_t *snake;
} playground_t;

playground_t *init_playground();
void refresh_playground(playground_t *playground);
void render_playground(playground_t *playground);
void free_playground(playground_t *playground);

#endif

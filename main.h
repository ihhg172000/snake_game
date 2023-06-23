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

/* init snake position */

#define INIT_SNAKE_POS_X 1
#define INIT_SNAKE_POS_Y 1

/* symbols */

#define SNAKE_HEAD '*'
#define SNAKE_BODY '.'
#define BLOCK '#'
#define FOOD '$'

/* direction */

#define RIGHT 'r'
#define LEFT 'l'
#define UP 'u'
#define DOWN 'd'

extern unsigned int score;
extern bool game_over;

void terminal_row_mode();
void terminal_normal_mode();

typedef struct point
{
	int x;
	int y;
} point_t;

typedef struct pointnode
{
	point_t point;

	struct pointnode *prev;
	struct pointnode *next;
} pointnode_t;

void free_pointlist(pointnode_t *head);

typedef struct snake
{
	pointnode_t *head;
	char direction;
} snake_t;

int init_snake();
int increase_snake(snake_t *snake);
void move_snake_forword(snake_t *snake);
void change_snake_direction(snake_t *snake, char direction);

typedef struct playground
{
	char grid[ROWS][COLUMNS];
	snake_t snake;
	point_t food;
} playground_t;

int init_playground(playground_t *playground);
void refresh_playground(playground_t *playground);
void render_playground(playground_t *playground);

void random_food(point_t *food);

void *keys_handler(void *playground);
void *render_handler(void *playground);

#endif

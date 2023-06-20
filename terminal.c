#include "main.h"

struct termios normal_tio, row_tio;

void terminal_row_mode()
{
	tcgetattr(STDIN_FILENO, &normal_tio);
  	row_tio = normal_tio;
  	row_tio.c_lflag &= ~(ICANON | ECHO);
  	tcsetattr(STDIN_FILENO, TCSANOW, &row_tio);
}

void terminal_normal_mode()
{
  	tcsetattr(STDIN_FILENO, TCSANOW, &normal_tio);
}

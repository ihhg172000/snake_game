#include "main.h"
#include "art.h"

const char numbers[10][5][3] = {
{{ZERO_0}, {ZERO_1}, {ZERO_2}, {ZERO_3}, {ZERO_4}},
{{ONE_0}, {ONE_1}, {ONE_2}, {ONE_3}, {ONE_4}},
{{TWO_0}, {TWO_1}, {TWO_2}, {TWO_3}, {TWO_4}},
{{THREE_0}, {THREE_1}, {THREE_2}, {THREE_3}, {THREE_4}},
{{FOUR_0}, {FOUR_1}, {FOUR_2}, {FOUR_3}, {FOUR_4}, },
{{FIVE_0}, {FIVE_1}, {FIVE_2}, {FIVE_3}, {FIVE_4}},
{{SIX_0}, {SIX_1}, {SIX_2}, {SIX_3}, {SIX_4}},
{{SEVEN_0}, {SEVEN_1}, {SEVEN_2}, {SEVEN_3}, {SEVEN_4}},
{{EIGHT_0}, {EIGHT_1}, {EIGHT_2}, {EIGHT_3}, {EIGHT_4}},
{{NINE_0}, {NINE_1}, {NINE_2}, {NINE_3}, {NINE_4}}
};

void print_number(unsigned int number)
{
	for (int i = 0; i < COLUMNS; i++)
	{
		printf(BOX_LIGHT_1);
	}

	printf("\n");

	for (int row = 0; row < ART_ROWS; row++)
	{
		print_row(number, row);
		printf("\n");
	}

	for (int i = 0; i < COLUMNS; i++)
	{
		printf(BOX_LIGHT_1);
	}

	printf("\n");
}

void print_row(unsigned int number, unsigned int row)
{
	unsigned int digits = digits_count(number);

	if (number == 0)
	{
		printf(BOX_LIGHT_1);

		for (int column = 0; column < ART_COLUMNS; column++)
		{
			if (numbers[number % 10][row][column] == '+')
			{
				printf(BOX);
			}
			else
			{
				printf(BOX_LIGHT_1);
			}
		}

		digits++;
	}
	else
	{
		_print_row(number, row);
	}

	for (int i = 0; i < (COLUMNS - (digits * 4)); i++)
	{
		printf(BOX_LIGHT_1);
	}
}

void _print_row(unsigned int number, unsigned int row)
{
	if (number != 0)
	{	
		_print_row(number / 10, row);

		printf(BOX_LIGHT_1);

		for (int column = 0; column < ART_COLUMNS; column++)
		{
			if (numbers[number % 10][row][column] == '+')
			{
				printf(BOX);
			}
			else
			{
				printf(BOX_LIGHT_1);
			}
		}		
	}
}

unsigned int digits_count(unsigned int number)
{
	if (number == 0)
		return (0);

	return (1 + digits_count(number / 10));
}

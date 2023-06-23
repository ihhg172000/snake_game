#ifndef ART_H
#define ART_H

#include <stdio.h>
#include <stdlib.h>

#define ART_ROWS 5
#define ART_COLUMNS 3

#define ZERO_0 "+++"
#define ZERO_1 "+-+"
#define ZERO_2 "+-+"
#define ZERO_3 "+-+"
#define ZERO_4 "+++"

#define ONE_0 "++-"
#define ONE_1 "-+-"
#define ONE_2 "-+-"
#define ONE_3 "-+-"
#define ONE_4 "+++"

#define TWO_0 "+++"
#define TWO_1 "--+"
#define TWO_2 "+++"
#define TWO_3 "+--"
#define TWO_4 "+++"

#define THREE_0 "+++"
#define THREE_1 "--+"
#define THREE_2 "+++"
#define THREE_3 "--+"
#define THREE_4 "+++"

#define FOUR_0 "+-+"
#define FOUR_1 "+-+"
#define FOUR_2 "+++"
#define FOUR_3 "--+"
#define FOUR_4 "--+"

#define FIVE_0 "+++"
#define FIVE_1 "+--"
#define FIVE_2 "+++"
#define FIVE_3 "--+"
#define FIVE_4 "+++"

#define SIX_0 "+++"
#define SIX_1 "+--"
#define SIX_2 "+++"
#define SIX_3 "+-+"
#define SIX_4 "+++"

#define SEVEN_0 "+++"
#define SEVEN_1 "--+"
#define SEVEN_2 "--+"
#define SEVEN_3 "--+"
#define SEVEN_4 "--+"

#define EIGHT_0 "+++"
#define EIGHT_1 "+-+"
#define EIGHT_2 "+++"
#define EIGHT_3 "+-+"
#define EIGHT_4 "+++"

#define NINE_0 "+++"
#define NINE_1 "+-+"
#define NINE_2 "+++"
#define NINE_3 "--+"
#define NINE_4 "+++"

void print_number(unsigned int number);
void print_row(unsigned int number, unsigned int row);
void _print_row(unsigned int number, unsigned int row);
unsigned int digits_count(unsigned int number);

#endif

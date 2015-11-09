#include <stdio.h>
#include "exchange_change.h"

void exchange_out(int number)
{
    printf("пятирублёвых монет : %i , двухрублёвых монет : %i , рублёвых монет : %i\n",
           change_by_fives(number), change_by_twos(number), change_by_ones(number));
}

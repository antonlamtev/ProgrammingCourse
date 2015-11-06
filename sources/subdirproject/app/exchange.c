#include <stdio.h>
#include "change.h"

void exchange(void)
{
    int number;

    do
    {
        puts("Сколько рублей нужно разменять?");
        scanf("%i", &number);
    }
    while (number >= 100);

    /*Мы используем меньшее число монет в том случае, когда
      пятирублёвых будет больше, чем двухрублёвых, а двухрублёвых - больше,
      чем рублёвых, насколько это возможно*/

    printf("пятирублёвых монет : %i , двухрублёвых монет : %i , рублёвых монет : %i\n",
           change_by_fives(number), change_by_twos(number), change_by_ones(number));
}

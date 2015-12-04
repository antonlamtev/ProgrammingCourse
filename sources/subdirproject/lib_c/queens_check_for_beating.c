#include <stdlib.h>

#include "queens.h"

int check_for_beating(struct queen q1, struct queen q2)
{
    return (q1.x == q2.x || q1.y == q2.y) || (abs(q1.x-q2.x) == abs(q1.y-q2.y));
}

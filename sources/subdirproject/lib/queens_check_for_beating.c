#include <stdlib.h>

int check_for_beating(int x1, int y1, int x2, int y2)
{
    return (x1 == x2 || y1 == y2) || (abs(x1-x2) == abs(y1-y2));

}


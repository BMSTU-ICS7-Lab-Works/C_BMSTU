#include <stdio.h>
#include <math.h>
int
square (int x1, int x2, int x3, int y1, int y2, int y3)
{

int (s);

s = abs ((x2 - x1) * (y3 - y1) - (x3 - x1) * (y2 - y1)) / 2;

return s;

}



int
main ()
{

int x1, x2, x3, y1, y2, y3;

float s;

if ((scanf ("%d %d %d %d %d %d", &x1, &y1, &x2, &y2, &x3, &y3) != 6)
       ||((x1 == x2) && (y1 == y2)) || ((x1 == x3) && (y1 == y3))
       ||((x3 == x2) && (y3 == y2)) || ((x1 == x2) && (x1 == x3)
                    && (x3 == x2)) || ((y1 == y2)
                               && (y1 == y3)
                               && (y3 == y2)))

    {

printf ("incorrect data");

return -1;

}


s = square (x1, x2, x3, y1, y2, y3);

printf ("%f", s);

return 0;

}


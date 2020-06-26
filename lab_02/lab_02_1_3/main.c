#include <stdio.h>
#include <math.h>
#define PI 3.1415926535
float
s (float eps, float x)
{

int sch, con;

float sx, a;

a = x;

sx = a;

sch = -1;

con = 1;

while (fabs (a) > eps)

    {

a *= sch * (pow (x, 2) / (con * (con + 1) * (con + 2)));

con += 2;

sx += a;

}

return sx;

}



float
f (float x)
{

float fx;

fx = sin (x * PI / 180);

return fx;

}



int
main ()
{

float x, eps, sx, fx, absolt, otnos;

if (scanf ("%f%f", &x, &eps) != 2)

    {

printf ("incorrect data");

return -1;

}

sx = s (eps, x);

printf ("%f\n", sx);

fx = f (x);

printf ("%f\n", fx);

absolt = fabs (fx - sx);

otnos = fabs (absolt / fx);

printf ("absolt = %f\notnos = %f", absolt, otnos);

return 0;

}

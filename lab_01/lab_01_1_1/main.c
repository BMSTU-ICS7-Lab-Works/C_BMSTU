#define PI 3.1415926535

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{ 
    double a, b, alpha;
    double s;
    scanf("%lf %lf %lf", &a, &b, &alpha);

    s = (b > a ? b - a : a - b) * (b + a) * tan(alpha / 180 * PI) / 4;

    printf("%lf", s);

    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include "main.h"

double maxfinder(double *mas, double *eptr)
{
    double max = *mas;
    for (double *i = mas; i < eptr; i++)
    {
        if (max < *i)
            max = *i;
    }
    return max;
}

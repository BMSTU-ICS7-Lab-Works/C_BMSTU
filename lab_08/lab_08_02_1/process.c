#include <stdio.h>
#include <stdlib.h>
#include "main.h"

int resize(double **mas, int *n)
{
    double *buf = (double*)realloc(*mas, *n * sizeof(double));
    if (buf)
    {
        *mas = buf;
        buf = NULL;
        free(buf);
        return OK;
    }
    printf("ERR no memory was given");
    return ERR_NO_MEM;
}

int insertmas(double **mas, double *eptr, int *n, int inspos)
{
    double max = maxfinder(*mas, eptr);
    *n = *n + 3;
    if (resize(mas, n) != 0)
    {
        free(mas);
        eptr = NULL;
        return ERR_NO_MEM;
    }
    eptr = *mas + *n - 3;
    //printf("\neptr is %lf\n", *(eptr));
    for (double *k = eptr; k > *mas + inspos; k--)
    {
        *k = *(k - 1);
    }
    *(*mas + inspos) = max;
    //masout(*mas, eptr);
    *(*mas + *n - 2) = max;
    //masout(*mas, eptr);
    eptr = *mas + *n - 1;
    for (double *i = eptr; i > *mas; i--)
    {
        *i = *(i - 1);
    }
    **mas = max;
    //masout(*mas, eptr);
    return OK;
}

#include <stdio.h>
#include <stdlib.h>
#include "main.h"

int mascreate(int n, double**mas)
{
    *mas = (double*)malloc(n * sizeof(double));
    if (mas)
        return OK;
    else
    {
        printf("ERR no memory was given");
        return ERR_NO_MEM;
    }
}

int masinp(double *mas, double *eptr, double *srarifm)
{
    double currnum = 0;
    for (double *i = mas; i < eptr; i++)
    {
        printf("Enter mas elem: ");
        if (!scanf("%lf", &currnum))
        {
            printf("Wrong mas element");
            return ERR_WRONG_ELEM;
        }
        *i = currnum;
        *srarifm += currnum;
    }
    *srarifm /= (eptr - mas);
    return OK;
}

int masout(double *mas, double *eptr)
{
    printf("\nMas is: ");
    for (double *i = mas; i < eptr; i++)
    {
        printf("%lf ", *i);
    }
    printf("\n");
    return OK;
}

int masremove(int *n, double **mas, double srarifm, double *eptr)
{
    int k = *n;
    int sch = 0;
    for (int i = 0; i < k; i++)
    {
        if ((*((*mas) + i)) > srarifm)
        {
            for (int j = i; j < k - 1; j++)
                *((*mas) + j) = *((*mas) + (j + 1));
            k--;
            i--;
            sch++;
        }
    }
    *n -= sch;   
    if (resize(mas, n) != 0)
        return ERR_NO_MEM;
    return OK;
}

#include <stdio.h>
#include <stdlib.h>
#include "main.h"

#define OK 0
#define ERR_N_INP -1
#define ERR_N_FLOAT -2
#define ERR_WRONG_ELEM -3
#define FUNC_ERR -4
#define ERR_NO_MEM -5

int main()
{
    int n;
    double srarifm = 0;
    double *mas;
    float n1;
    double *eptr = NULL;
    int inspos;
    float inspos1;
    printf("Input n: ");
    if (!scanf("%f", &n1) || n1 <= 0)
    {
        printf("Wrong n");
        return ERR_N_INP;
    }
    n = n1;
    if (n != n1)
    {
        printf("n is float");
        return ERR_N_FLOAT;
    }
    if (mascreate(n, &mas) == 0)
    {
        eptr = mas + n;
        if (masinp(mas, eptr, &srarifm) == 0)
        {
            if (masremove(&n, &mas, srarifm, eptr) != 0)
            {
                eptr = NULL;
                free(mas);
                return ERR_NO_MEM;
            }
            //printf("%dmain n\n\n", n);
            eptr = mas + n;
            printf("Input p: ");
            if (!scanf("%f", &inspos1) || inspos1 < 0 || inspos1 >= n)
            {
                printf("Wrong insert position");
                eptr = NULL;
                free(mas);
                return ERR_N_INP;
            }
            inspos = inspos1;
            if (inspos != inspos1)
            {
                printf("insert position is float");
                eptr = NULL;
                free(mas);
                return ERR_N_FLOAT;
            }
            if (insertmas(&mas, eptr, &n, inspos) != 0)
            {
                eptr = NULL;
                free(mas);
                return ERR_NO_MEM;
            }
            eptr = mas + n;
            masout(mas, eptr);
            eptr = NULL;
            free(mas);
            return OK;
        }
        else
        {
            eptr = NULL;
            free(mas);
            return FUNC_ERR;
        }
    }
    free(mas);
    return FUNC_ERR;
}

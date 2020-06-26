#include <stdlib.h>
#include <stdio.h>
#include "main.h"

int freematr(long long int **matr, long long int rows)
{
    for (int i = 0; i < rows; i++)
        if (matr[i])
            free(matr[i]);
    free(matr);
    return CORR_END;
}

long long int **create(long long int m, long long int n)
{
    long long int **data = (long long int**)calloc(m, sizeof(long long int*));
    if (data)
    {
        for (long long int i = 0; i < m; i++)
        {
            data[i] = (long long int*)calloc(n, sizeof(long long int));
            if (!data[i])
            {
                printf("ERR no memory was given");
                freematr(data, m);
                return NULL;
            }
        }
        return data;
    }
    else
    {
        free(data);
        printf("ERR no memory was given");
        return NULL;
    }
}

int freerow(long long int rows, long long int cols, long long int ***matr)
{
    long long int **data = (long long int**)realloc(*matr, rows * sizeof(long long int*));
    if (data)
    {
        *matr = data;
        data = NULL;
        for (long long int i = 0; i < rows; i++)
        {
            long long int *datas = (long long int*)realloc(*(*matr + i), cols * sizeof(long long int));
            if (!datas)
            {
                printf("ERR no memory was given");
                return ERR_NO_MEM;
            }
            *(*matr + i) = datas;
            datas = NULL;
        }  
        return CORR_END;
    }
    else
    {
        printf("ERR no memory was given");
        return ERR_NO_MEM;
    }
}

int createrow(long long int rows, long long int cols, long long int ***matr)
{
    long long int **data = (long long int**)realloc(*matr, rows * sizeof(long long int*));
    long long int *datas = NULL;
    if (data)
    {
        *matr = data;
        data = NULL;
        //maybe free source matr in functions alike??
        for (long long int i = 0; i < rows; i++)
        {
            if (i == rows - 1)
                datas = (long long int*)calloc(cols, sizeof(long long int));
            else
                datas = (long long int*)realloc(*(*matr + i), cols * sizeof(long long int));
            if (!datas)
            {
                printf("ERR no memory was given");
                datas = NULL;
                return ERR_NO_MEM;
            }
            *(*matr + i) = datas;
            datas = NULL;
        }
        return CORR_END;
    }
    else
    {
        printf("ERR no memory was given");
        return ERR_NO_MEM;
    }
}

int input(long long int rows, long long int cols, long long int **matr)
{
    long long int currnum;
    float currnum1;
    // Ввод элементов массива
    for (long long int i = 0; i < rows; i++)
    {
        printf("Enter matr row: ");
        for (long long int j = 0; j < cols; j++)
        {
            if (!scanf("%f", &currnum1))
            {
                printf("Wrong matr elem");
                return ERR_NUM_INP;
            }
            currnum = currnum1;
            if (currnum != currnum1)
            {
                printf("matr elem is float");
                return ERR_FLOAT_INP;
            }
            matr[i][j] = currnum;
        }
    }
    return CORR_END;
}

int output(long long int rows, long long int cols, long long int **matr)
{
    // Вывод элементов массива
    printf("\nRESULT IS:\n");
    for (long long int i = 0; i < rows; i++)
    {
        for (long long int j = 0; j < cols; j++)
            printf("%lld ", matr[i][j]);
        printf("\n"); // перевод на новую строку
    }
    return CORR_END;
}

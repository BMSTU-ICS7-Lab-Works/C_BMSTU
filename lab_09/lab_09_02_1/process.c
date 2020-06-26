#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "main.h"

long long int maxfinder(long long int rows, long long int cols, long long int **matra, int iorj)
{
    long long int max, maxi;
    max = matra[0][0];
    maxi = 0;
    for (long long int i = 0;i < rows; i++)
        for (long long int j = 0; j < cols; j++)
            if (matra[i][j] >= max)
            {
                max = matra[i][j];
                if (iorj == 1)
                    maxi = i;
                else
                    maxi = j;
            }
    //printf("max is and maxi %lli %lli\n\n", max, maxi);
    return maxi;
}

long long int **transpose(long long int *rows, long long int *cols, long long int ***matra)
{
    long long int tmp;
    long long int **altmatr = create(*cols, *rows);
    for (long long int i = 0; i < *rows; i++)
        for (long long int j = 0; j < *cols; j++)
            altmatr[j][i] = *(*(*matra + i) + j);
    freematr(*matra, *rows);
    tmp = *rows;
    *rows = *cols;
    *cols = tmp;
    return altmatr;
}

int del_rows(long long int *rows, long long int cols, long long int ***matr, long long int maxi)
{
    (*rows)--;
    for (long long int i = maxi; i < *rows; i++)
        for (long long int j = 0; j < cols; j++)
            *(*(*matr + i) + j) = *(*(*matr + i + 1) + j);
    free(*(*matr + *rows));
    *(*matr + *rows) = NULL;
    freerow(*rows, cols, matr);   
    return CORR_END;
}

long long int srarifmcol(long long int **matr, long long int rows, long long int cols)
{
    long long int count = rows;
    double srarifm = 0;
    for (long long int i = 0; i < rows; i++)
        srarifm += matr[i][cols];
    srarifm /= count;
    return (long long int)(floor(srarifm));
}

long long int minfinder(long long int rows, long long int cols, long long int **matr)
{ 
    long long int min = matr[rows][0];
    for (long long int j = 1; j < cols; j++)
        if (matr[rows][j] < min)
            min = matr[rows][j];
    return min;
}

int add_row(long long int *rows, long long int cols, long long int ***matr, int maxorsr, long long int *masmax)
{
    (*rows)++;
    createrow(*rows, cols, matr);
    if (maxorsr == 0)
    {
        for (long long int j = 0; j < cols; j++)
            *(*(*matr + *rows - 1) + j) = srarifmcol(*matr, *rows - 1, j);
    }
    else
    {  
        for (long long int j = 0; j < cols; j++)
            *(*(*matr + *rows - 1) + j) = masmax[j];
    }
    return CORR_END;
}

long long int **matrpow(long long int rows, long long int cols, long long int ***matr, long long int **altmatr)
{
    long long int **data = create(rows, cols);
    for (long long int i = 0; i < rows; i++)
        for (long long int j = 0; j < cols; j++)
        {
            data[i][j] = 0;
            for (long long int k = 0; k < cols; k++)
                data[i][j] += *(*(*matr + i) + k) * altmatr[k][j];
        }
    freematr(*matr, rows);
    return data;
}

long long int **matrones(long long int rows, long long int cols, long long int **matr)
{
    long long int **data = create(rows, cols);
    for (long long int i = 0; i < rows; i++)
        for (long long int j = 0; j < cols; j++)
        {
            data[i][j] = 0;
            if (i == j)
                data[i][j] = 1;
        }
    freematr(matr, rows);
    return data;
}

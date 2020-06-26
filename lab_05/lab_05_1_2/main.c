#include <stdio.h>

int matrinp(int matr[][10], int w, int h)
{
    float f;
    for (int i = 0; i < h; i++)
        for (int j = 0; j < w; j++)
        {
            printf("input matr[%d][%d]= ", i, j);
            if (scanf("%f", &f) != 1)
                return -1;
            int n = f;
            if (f - n != 0)
                return -1;
            matr[i][j] = n;
        }
    return 0;
}

int matrout(int matr[][10], int w, int h, int *arr)
{
    int k = 0;
    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
        {
            matr[i][j] = arr[k];
            k++;
            printf("%d ", matr[i][j]);
        }
        puts("");
    }
    return 0;
}

int matrarr(int matr[][10], int w, int h, int *arr)
{
    int k = 0;
    for (int i = 0; i < h - 1; i++)
    {
        for (int j = 0; j < w - 1; j++)
        {
            arr[k] = matr[i][j];
            k++;
        }
    }
    return 0;
}

int preobr(int matr[][10], int w, int h, int *deli, int *delj)
{
    for (int i = 0; i < h - 1 ; i++)
    {
        if (i < *deli)
        {
            for (int j = 0; j < w - 1; j++)
                if (j >= *delj)
                    matr[i][j] = matr[i][j + 1];
        }
        else
        {
            for (int j = 0; j < w; j++)
            {
                if (j < *delj)
                    matr[i][j] = matr[i + 1][j];
                if (j > *delj)
                    matr[i][j - 1] = matr[i + 1][j];
            }
        }
    }
    return 0;
}

int numsum(int melem)
{
    int sum, curr;
    sum = 0;
    if (melem < 0)
        curr = -melem;
    else
        curr = melem;
    while (curr > 0)
    {
        sum += curr % 10;
        curr /= 10;
    }
    return sum;
}

void minfinder(int h, int w, int matr[][10], int *deli, int *delj)
{
    int min = -1, flag = 0, summ;
    for (int i = 0; i < h; i++)
        for (int j = 0; j < w; j++)
        {
            summ = numsum(matr[i][j]);
            if (flag == 0)
            {
                flag = 1;
                min = summ;
                *deli = i;
                *delj = j;
            }
            else if (summ < min)
            {
                min = summ;
                *deli = i;
                *delj = j;
            }
        }
}

int main()
{
    float w1, h1;
    int deli, delj;
    puts("input matr width");
    if (scanf("%f", &w1) != 1 || w1 >= 11 || w1 <= 1)
    {
        puts("Incorrect width");
        return -1;
    }
    int h = w1;
    if (w1 - h != 0)
    {
        printf("Incorrect width");
        return -1;
    }
    puts("input matr height");
    if (scanf("%f", &h1) != 1 || h1 >= 11 || h1 <= 1)
    {
        puts("Incorrect height");
        return -1;
    }
    int w = h1;
    if (h1 - w != 0)
    {
        printf("Incorrect heigth");
        return -1;
    }
    int matr[10][10];
    int arr[10 * 10];
    if (matrinp(matr, w, h) == -1)
    {
        puts("incorrect matr elem");
        return -1;
    }
    minfinder(h, w, matr, &deli, &delj);
    preobr(matr, w, h, &deli, &delj);
    matrarr(matr, w, h, arr);
    matrout(matr, w - 1, h - 1, arr);
    return 0;
}

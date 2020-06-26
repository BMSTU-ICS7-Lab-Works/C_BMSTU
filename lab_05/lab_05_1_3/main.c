#include <stdio.h>
#include <math.h>
#define MAXMATR 10
typedef int matrix[MAXMATR][MAXMATR];

int matrinp(matrix matr, int w, int h)
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

int matrout(matrix matr, int w, int h)
{
    for (int i = 0; i < h ; i++)
    {
        for (int j = 0; j < w; j++)
            printf("%d ", matr[i][j]);
        puts("");
    }
    return 0;
}

int melem(matrix matr, int row, int rowl)
{
    int max;
    max = matr[row][0];
    for (int i = 1;i < rowl; i++)
    {
        if (matr[row][i] > max)
            max = matr[row][i];
    }
    return max;
}

void sort(int h, int w, matrix matr)
{
    int currmax, max, prmax, hel, indm;
    for (int i = 0; i < h - 1; i++)
    {
        currmax = melem(matr, i, w);
        indm = i + 1;
        prmax = melem(matr, i + 1, w);
        for (int j = i + 1; j < h; j++)
        {
            max = melem(matr, j, w);
            if (prmax < max)
            {
                indm = j;
                prmax = max;
            }
        }
        if (currmax < prmax)
            for (int z = 0; z < w; z++)
            {
                hel = matr[i][z];
                matr[i][z] = matr[indm][z];
                matr[indm][z] = hel;
            }
    }
}

int main()
{
    float w1, h1;
    puts("input matr width");
    if (scanf("%f", &w1) != 1 || w1 >= 11 || w1 <= 0)
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
    if (scanf("%f", &h1) != 1 || h1 >= 11 || h1 <= 0)
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
    matrix matr;
    if (matrinp(matr, w, h) == -1)
    {
        puts("incorrect matr elem");
        return -1;
    }
    sort(h, w, matr);
    matrout(matr, w, h);
    return 0;
}

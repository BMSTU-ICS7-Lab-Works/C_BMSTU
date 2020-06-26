#include <stdio.h>
#define MAXMATR 10
typedef int matrix[MAXMATR][MAXMATR];
typedef int array[MAXMATR];

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

int checker(int w, array arr)
{
    int flag = 1;
    for (int i = 0; i < w / 2; i++)
    {
        if (arr[i] != arr[w - 1 - i])
        {
            flag = 0;
            break;
        }
    }
    return flag;
}

void arrout(array arr, int w, int h, matrix matr)
{
    int res;
    for (int i = 0; i < h; i++)
    {
        res = checker(w, matr[i]);
        arr[i] = res;
        printf("%d ", arr[i]);
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
    array arr;
    if (matrinp(matr, w, h) == -1)
    {
        puts("incorrect matr elem");
        return -1;
    }
    arrout(arr, w, h, matr);
    return 0;
}

#include <stdio.h>
#include <math.h>
#define MAX_SIZE 20

int masinp(int *mas, int n)
{
    float f;
    for (int i = 0;i < n; i++)
    {
        printf("inp mas elem ");
        if (scanf("%f", &f) != 1)
            return -1;
        int n = f;
        if (f - n != 0)
            return -1;
        mas[i] = f;
    }
    return 0;
}

void masout(int *mas, int newn)
{
    for (int j = 0;j < newn; j++)
        printf("%d ", mas[j]);
}

int fib(int i)
{
    if (i == 0)
        return 0;
    if (i == 1)
        return 1;
    return fib(i - 1) + fib(i - 2);
}

int narr(int *mas, int *n)
{
    int k = 0, b;
    for (int i = 0; i < *n; i++)
        if (mas[i] % 3 == 0 && mas[i] != 0)
        {
            *n = *n + 1;
            b = fib(k);
            for (int z = *n; z > i + 1; z--)
                mas[z] = mas[z - 1];
            mas[i + 1] = b;
            k++;
            i++;
        }
    return k;
}

int main()
{
    int mas[MAX_SIZE];
    float n1;
    printf("input mas len ");
    if (scanf("%f", &n1) != 1 || n1 >= 11 || n1 <= 0)
    {
        printf("incorrect input");
        return -1;
    }
    int n = n1;
    if (n1 - n != 0)
    {
        printf("Incorrect input");
        return -1;
    }
    int p = masinp(mas, n);
    if (p == -1)
    {
        printf("at least 1 of elems is wrong");
        return -1;
    }
    narr(mas, &n);
    masout(mas, n);
    return 0;
}

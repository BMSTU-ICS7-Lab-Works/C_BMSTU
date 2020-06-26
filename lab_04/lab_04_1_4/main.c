#include <stdio.h>
#include <math.h>
#define MAX_SIZE 10

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

void narr(int *mas, int n)
{
    int new, loc;
    for (int i = 1; i < n; i++)
    {
        new = mas[i];
        loc = i - 1;
        while ((loc >= 0) && (mas[loc] > new))
        {
            mas[loc + 1] = mas[loc];
            loc = loc - 1;
        }
        mas[loc + 1] = new;
    }
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
    narr(mas, n);
    masout(mas, n);
    return 0;
}

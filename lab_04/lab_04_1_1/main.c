#include <stdio.h>
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

int multiply(int *mas, int chn)
{
    int res = 0;
    for (int i = 0; i < chn; i++)
    {
        if ((mas[i] % 2 != 0) && (res == 0))
        {
            res = mas[i];
        }
        else if (mas[i] % 2 != 0)
            res *= mas[i];
    }
    return res;
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
    int hel = masinp(mas, n);
    if (hel == -1)
    {
        printf("1 or more elems isn't int");
        return -1;
    }
    hel = multiply(mas, n);
    if (hel != 0)
    {
        printf("%d", hel);
        return 0;
    }
    else
    {
        printf("no odds");
        return -1;
    }
}

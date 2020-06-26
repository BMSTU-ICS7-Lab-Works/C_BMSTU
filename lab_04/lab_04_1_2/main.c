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

int prime(int *mas, int *nmas, int n)
{
    int flag, counter, curr;
    counter = 0;
    for (int i = 0; i < n; i++)
    {
        flag = 0;
        curr = ceil(sqrt(mas[i]));
        for (int j = 2; j <= curr; j++)
            if ((mas[i] % j) == 0)
            {
                flag = 1;
                break;
            }
        if (((flag == 0) && (mas[i] > 1)) || (mas[i] == 2))
        {
            nmas[counter] = mas[i];
            counter += 1;
        }
    }
    return counter;
}

int main()
{
    int mas[MAX_SIZE], nmas[MAX_SIZE], res;
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
    res = prime(mas, nmas, n);
    if (res == 0)
    {
        printf("No primes");
        return -1;
    }
    else
    {
        masout(nmas, res);
        return 0;
    }
}

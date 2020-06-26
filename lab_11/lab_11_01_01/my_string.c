#include "func.h"

int my_strcmp(const char *a, const char *b)
{
    while (*a && *b && *a == *b)
        ++a, ++b;
    return *a - *b;
}

void my_itoa(long int value, char *sp)
{
    char tmp[22];
    int pos1 = 0, pos2 = 0;
    int flag = 0;
    long int i;
    if (value < 0)
    {
        sp[pos2] = '-';
        pos2++;
        if (value == LONG_MIN)
        {
            flag++;
            value += 1;
        }
        value *= -1;
    }
    if (flag)
    {
        tmp[pos1] = '8';
        pos1++;
    }
    while (value)
    {
        i = value % 10;
        value /= 10;
        if (flag)
        {
            flag = 0;
            continue;
        }
        tmp[pos1] = i + '0';
        pos1++;
    }
    for (int j = pos1 - 1; j > -1; j--, pos2++)
        sp[pos2] = tmp[j];
    sp[pos2] = '\0';
}

int my_strlen(const char *str)
{
    int count = 0;
    while (str[count] != '\0')
    {
        count++;
    }
    return count;
}

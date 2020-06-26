#include <stdio.h>

#define ERR_NO_NUM -1
#define ERR_REAL_NUM -2
#define ERR_NOT_ENOUGH_NUM -3

int process(FILE *f, int *res)
{
    float n1, n2, n3;
    int ni1, ni2, ni3;
    if (fscanf(f, "%f", &n1) != 1)
        return ERR_NO_NUM;
    ni1 = n1;
    if ((n1 - ni1) != 0)
        return ERR_REAL_NUM;
    if (fscanf(f, "%f", &n2) != 1)
        return ERR_NOT_ENOUGH_NUM;
    ni2 = n2;
    if ((n2 - ni2) != 0)
        return ERR_REAL_NUM;
    if (fscanf(f, "%f", &n3) != 1)
        return ERR_NOT_ENOUGH_NUM;
    ni3 = n3;
    if ((n3 - ni3) != 0)
        return ERR_REAL_NUM;
    if ((ni1 < ni2) && (ni2 > ni3))
        (*res)++;
    while (1)
    {
        ni1 = ni2;
        ni2 = ni3;
        if (fscanf(f, "%f", &n3) != 1)
        {
            fclose(f);
            break;           
        }
        ni3 = n3;
        if ((ni3 - n3) != 0)
            return ERR_REAL_NUM;
        if ((ni1 < ni2) && (ni2 > ni3))
            (*res)++;
    }
    return 0;
}

int main()
{
    FILE *f = stdin;
    printf("at the end of the file, enter the letter\n");
    int res = 0;
    int check = process(f, &res);
    if (check == ERR_NO_NUM)
    {
        printf("no numbers");
        return ERR_NO_NUM;
    }
    if (check == ERR_REAL_NUM)
    {
        printf("1 or more numbers is real");
        return ERR_REAL_NUM;
    }
    if (check == ERR_NOT_ENOUGH_NUM)
    {
        printf("not enough numbers");
        return ERR_NOT_ENOUGH_NUM;
    }
    printf("%d", res);
    return 0;
}

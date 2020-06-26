#include <stdio.h>
#include <string.h>
/*
char *my_strpbrk(char *str, char *sym)
{
    for (int i = 0; str[i] != '\0'; i++)
    {
        for (int j = 0; sym[j] != '\0'; j++)
            if (str[i] == sym[j])
                return &str[i];
    }
    return "";
}

unsigned long long int my_strspn(char *str, char *sym)
{
    unsigned long long int maxl = 0, flag;
    for (int i = 0; str[i] != '\0'; i++)
    {
        flag = 0;
        for (int j = 0; sym[j] != '\0'; j++)
            if (str[i] == sym[j])
                flag = 1;
        if (flag == 1)
            maxl += 1;
        else
            break;
    }
    return maxl;
}


unsigned long long int my_strcspn(char *str, char *sym)
{
    int flag = 0;
    unsigned long long int res = 0;
    for (int i = 0; str[i] != '\0'; i++)
    {
        flag = 0;
        for (int j = 0; sym[j] != '\0'; j++)
            if (str[i] == sym[j])
                flag = 1;
        if (flag != 1)
            res += 1;
        else
            break;
    }
    return res;
}


char *my_strchr(char *str, char *sym)
{
    for (int i = 0; str[i] != '\0'; i++)
    {
        if (str[i] == sym[0])
            return &str[i];
    }
    return "";
}
*/
char *my_strrchr(char *str, int sym)
{
    char *res;
    int flag = 0;
    for (int i = 0; str[i] != '\0'; i++)
    {
        int alt = str[i];
        if (alt == sym)
        {
            res = &str[i];
            flag = 1;
        }
    }
    if (flag == 1)
        return res;
    else
        return NULL;
}


int main()
{
    char *integr, *mine;
    integr = strrchr("0163456769", '6');
    mine = my_strrchr("0163456769", '6');
    printf("my_strrchr result: ");
    printf(mine);
    printf(" strrchr result: ");
    printf(integr);
    if (mine == integr)
        printf(" OK \n");
    else
        printf(" FAIL \n");
    integr = strrchr("ba a ba", ' ');
    mine = my_strrchr("ba a ba", ' ');
    printf("my_strrchr result: ");
    printf(mine);
    printf(" strrchr result: ");
    printf(integr);
    if (integr == mine)
        printf(" OK \n");
    else
        printf(" FAIL \n");
    integr = strrchr("54566", 'd');
    printf("strrchr result: ");
    printf(integr);
    mine = my_strrchr("54566", 'd');
    printf(" my_strrchr result: ");
    printf(mine);
    if (mine == integr)
        printf("OK \n");
    else
        printf("FAIL \n");
    /*
    fsym = strpbrk(str, sym);
    printf(fsym);
    puts("");
    fsym = my_strpbrk(str, sym);
    printf(fsym);
    puts("");
    printf("%I64u", strspn(str, sym));
    puts("");
    printf("%I64u", my_strspn(str, sym));
    puts("");
    printf("%I64u", strcspn(str, sym));
    puts("");
    printf("%I64u", my_strcspn(str, sym));
    puts("");
    fsym = strchr(str, sym[0]);
    printf(fsym);
    puts("");
    fsym = my_strchr(str, sym);
    printf(fsym);
    puts("");
    */
    return 0;
}

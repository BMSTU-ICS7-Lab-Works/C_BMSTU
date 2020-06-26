#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "app.h"


int check_date(char *date, int param)
{
    int visok = 0;
    int day = 0, month = 0, year = 0;
    int monthmas[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 } ;
    if (strlen(date) != 10)
        return WRONG_DATE;
    date = strtok(date, ".");
    if (strlen(date) != 4)
        return WRONG_DATE;
    year = atoi(date);
    date = strtok(NULL, ".");
    if (strlen(date) != 2)
        return WRONG_DATE;
    month = atoi(date);
    date = strtok(NULL, ".");
    if (strlen(date) != 2)
        return WRONG_DATE;
    day = atoi(date);
    //printf("D:M:Y %d %d %d\n", day, month, year);
    if (param == 0)
    {
        if (year >= 0 && year <= 2019)
        {
            if ((year % 4 == 0) && (year % 100 != 0 || year % 400 == 0))
                visok = 1;
            if (month <= 12 && month >= 1)
            {
                if ((day >= 1 && monthmas[month - 1] >= day) || (month == 2 && visok == 1 && day == 29))
                {
                    return CORR_END;
                }
                else
                {
                    return WRONG_DATE;
                }
            }
            else
            {
                return WRONG_DATE;
            }
        }
        else
        {
            return WRONG_DATE;
        }
    }
    else
    {
        if (year == 2002)
        {
            if (month == 11)
            {
                if (day > 1)
                {
                    return WRONG_AGE;
                }
                else
                    return CORR_END;
            }
            else if (month < 11)
            {
                return CORR_END;
            }
            else
                return WRONG_AGE;
        }
        else if (year < 2002)
        {
            return CORR_END;
        }
        else
            return WRONG_AGE;
    }
}

int delete_girls(schooler_t *schoolers, int *countlist)
{
    for (int i = 0; i < *countlist; i++)
    {
        if (strcmp((schoolers + i)->sex, "female") == 0)
        {
            char copy_date[256] = "";
            strcpy(copy_date, (schoolers + i)->date);
            if (check_date(copy_date, 1) == 0)
            {
                delete_field(schoolers, i, countlist);
                i--;
            }
        }
    }
    return CORR_END;
}

int add_marks(schooler_t *schoolers, int countlist)
{
    int lastpos = 0;
    for (int i = 0; i < countlist; i++)
    {
        lastpos = (schoolers + i)->marks[0] + 1;
        (schoolers + i)->marks[0] += 1;
        int *buf = (int*)realloc((schoolers + i)->marks, (lastpos + 1) * sizeof(int));
        if (buf)
        {
            (schoolers + i)->marks = buf;
            buf = NULL;
        }
        else
            return ERR_NO_MEM;
        (schoolers + i)->marks[lastpos] = 3;
    }
    return CORR_END;
}

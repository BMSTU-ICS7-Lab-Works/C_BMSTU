#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "app.h"

void freetable(schooler_t *schoolers, int countlist)
{
    for (int i = 0; i < countlist; i++)
    {
        free((schoolers + i)->surname);
        free((schoolers + i)->sex);
        free((schoolers + i)->date);
        free((schoolers + i)->marks);
    }
    free(schoolers);
    schoolers = NULL;
}

int show_table(schooler_t *schooler, int countlist)
{
    for (int i = 0; i < countlist; i++)
    {
        printf("\nSurname: %s\nSex: %s\nDate of birth: %s (YYYY.MM.DD)\n", (schooler + i)->surname, (schooler + i)->sex, (schooler + i)->date);
        printf("Number of marks and marks themselves: ");
        printf("%d ", (schooler + i)->marks[0]);
        for (int j = 1; j <= (schooler + i)->marks[0]; j++)
            printf("%d ", (schooler + i)->marks[j]);
        puts("\n");
    }
    return CORR_END;
}

int input_field(schooler_t *schooler)
{
    int rc, allnums;
    float rc1, allnums1;
    printf("Enter surname of a schooler: ");
    if (!(schooler->surname = (char*)malloc(256)))
        return ERR_NO_MEM;
    scanf("%s", schooler->surname);
    for (int i = 0; i < strlen(schooler->surname); i++)
        if ((schooler->surname[i] > 'z' || schooler->surname[i] < 'a') && (schooler->surname[i] > 'Z' || schooler->surname[i] < 'A'))
        {
            printf("WRONG NAME");
            free(schooler->surname);
            return WRONG_FIELD;
        }
    if (strcmp(schooler->surname, "nobody") == 0)
    {
        return CORR_FILL;
    }
    printf("Enter sex of a schooler: ");
    if (!(schooler->sex = (char*)malloc(256)))
    {
        free(schooler->surname);
        return ERR_NO_MEM;
    }
    scanf("%s", schooler->sex);
    for (int i = 0; i < strlen(schooler->sex); i++)
    {
        if (schooler->sex[i] <= 'Z' && schooler->sex[i] >= 'A')
            schooler->sex[i] += 32;
    }
    if (!(strcmp(schooler->sex, "male") == 0 || strcmp(schooler->sex, "female") == 0))
    {
        printf("Incorrect sex\n");
        free(schooler->surname);
        free(schooler->sex);
        return WRONG_FIELD;
    }
    printf("Enter date of birth: ");
    if (!(schooler->date = (char*)malloc(256)))
    {
        free(schooler->surname);
        free(schooler->sex);
        return ERR_NO_MEM;
    }
    scanf("%s", schooler->date);
    char copy_date[256] = "";
    strcpy(copy_date, schooler->date);
    if (check_date(copy_date, 0) != 0)
    {
        printf("Incorrect date of birth");
        free(schooler->surname);
        free(schooler->sex);
        free(schooler->date);
        return WRONG_FIELD;
    }
    printf("Enter number of marks and marks themselves: ");
    if (!scanf("%f", &allnums1))
    {
        printf("Number of marks should be integer!");
        free(schooler->surname);
        free(schooler->sex);
        free(schooler->date);
        return WRONG_FIELD;
    }
    allnums = allnums1;
    if (allnums - allnums1 != 0 || allnums <= 0)
    {
        printf("Number of marks is float or less and equal to 0!");
        free(schooler->surname);
        free(schooler->sex);
        free(schooler->date);
        return WRONG_FIELD;
    }
    schooler->marks = (int*)malloc((allnums + 1) * sizeof(int));
    schooler->marks[0] = allnums;
    for (int j = 1; j < allnums + 1; j++)
    {
        if (!scanf("%f", &rc1))
        {
            printf("Mark should be integer!");
            free(schooler->surname);
            free(schooler->sex);
            free(schooler->date);
            free(schooler->marks);
            return WRONG_FIELD;
        }
        rc = rc1;
        if (rc - rc1 != 0 || rc < 0)
        {
            printf("Mark is float or less than 0!");
            free(schooler->surname);
            free(schooler->sex);
            free(schooler->date);
            free(schooler->marks);
            return WRONG_FIELD;
        }
        schooler->marks[j] = rc;
    }
    return CORR_END;
}

int delete_field(schooler_t *schoolers, int curi, int *countlist)
{
    (*countlist)--;
    schooler_t tmp;
    for (int i = curi; i < *countlist; i++)
    {
        tmp = *(schoolers + i);
        *(schoolers + i) = *(schoolers + i + 1);
        *(schoolers + i + 1) = tmp;
    }
    return CORR_END;
}

schooler_t *create()
{
    schooler_t *buf = NULL;
    if (!(buf = (schooler_t*)malloc(sizeof(schooler_t))))
            return NULL;
    return buf;
}

int resize(schooler_t **schooler, int newsize)
{
    schooler_t *buf = (schooler_t*)realloc(*schooler, newsize * sizeof(schooler_t));
    if (buf)
    {
        (*schooler) = buf;
        buf = NULL;
        return CORR_END;
    }
    return ERR_NO_MEM;
}

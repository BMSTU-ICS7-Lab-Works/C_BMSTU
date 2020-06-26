#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "app.h"

float srarifm(schooler_t schooler)
{
    float sum = 0;
    int last = schooler.marks[0];
    for (int i = 1; i <= last; i++)
    {
        sum += schooler.marks[i];
    }
    sum /= last;
    return sum;
}

int surcomp(schooler_t *prev, schooler_t *next)
{
    return strcmp(prev->surname, next->surname);
}

int sexcomp(schooler_t *prev, schooler_t *next)
{
    return strcmp(prev->sex, next->sex);
}

int datecomp(schooler_t *prev, schooler_t *next)
{
    return strcmp(prev->date, next->date);
}

int markscomp(schooler_t *prev, schooler_t *next)
{
    float srprev = srarifm(*prev);
    float srnext = srarifm(*next);
    if (srprev > srnext)
        return 1;
    else
        return 0;
}

void swap(schooler_t *prev, schooler_t *next)
{
    schooler_t buf = *prev;
    *prev = *next;
    *next = buf;
}

void sort(schooler_t *schoolers, int countlist, int (*compare)(schooler_t*, schooler_t*))
{
    for (int i = 0; i < countlist - 1; i++)
        for (int j = 0; j < countlist - i - 1; j++)
            if ((*compare)((schoolers + j), (schoolers + j + 1)) > 0)
                swap((schoolers + j), (schoolers + j + 1));
}

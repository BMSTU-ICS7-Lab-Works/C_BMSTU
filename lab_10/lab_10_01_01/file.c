#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "app.h"

int out_file(schooler_t *schooler, int countlist)
{
    FILE *f;
    if ((f = fopen("kids.txt", "w")) == NULL)
    {
        return ERR_OPEN;
    }
    else
    {
        for (int i = 0; i < countlist; i++)
        {
            fprintf(f, "%s\n%s\n%s\n", (schooler + i)->surname, (schooler + i)->sex, (schooler + i)->date);
            fprintf(f, "%d ", (schooler + i)->marks[0]);
            for (int j = 1; j <= (schooler + i)->marks[0]; j++)
                fprintf(f, "%d ", (schooler + i)->marks[j]);
            fprintf(f, "\n");
        }
    }
    fclose(f);
    return CORR_END;
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "app.h"

int main()
{
    int countlist = 0;
    schooler_t *schoolers;
    schoolers = create();
    int is_list = 1;
    for (int i = 0; ; i++)
    {
        is_list = input_field(schoolers + i);
        if (is_list == 1)
        {
            free((schoolers + i)->surname);
            if (i == 0)
            {
                free(schoolers);
                schoolers = NULL;
            }
            break;
        }
        else if (is_list != 0)
        {
            freetable(schoolers, countlist);
            return WRONG_FILL;
        }
        countlist++;
        resize(&schoolers, countlist + 1);
    }
    int countlist_mem = countlist;
    delete_girls(schoolers, &countlist);
    if (countlist == 0)
    {
        printf("No fields left");
        freetable(schoolers, countlist_mem);
        return ERR_EMPTY;
    }
    if (add_marks(schoolers, countlist) != 0)
    {
        freetable(schoolers, countlist_mem);
        return ERR_NO_MEM;
    }
    char key[256] = "";
    printf("Enter key: ");
    scanf("%s", key);
    if (strcmp(key, "SURNAME") == 0)
    {
        sort(schoolers, countlist, surcomp);
    }
    else if (strcmp(key, "SEX") == 0)
    {
        sort(schoolers, countlist, sexcomp);
    }
    else if (strcmp(key, "BIRTHDATE") == 0)
    {
        sort(schoolers, countlist, datecomp);
    }
    else if (strcmp(key, "GRADE") == 0)
    {
        sort(schoolers, countlist, markscomp);
    }
    else
    {
        printf("WRONG KEY!");
        freetable(schoolers, countlist_mem);
        return ERR_INPUT;
    }
    show_table(schoolers, countlist);
    if (out_file(schoolers, countlist) != 0)
    {
        printf("ERR OPENING FILE");
        freetable(schoolers, countlist_mem);
        return ERR_OPEN;
    }
    freetable(schoolers, countlist_mem);
    return CORR_END;
}

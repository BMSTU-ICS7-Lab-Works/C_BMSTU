/*
 * description:
 * integer type: int
 * sort: bubble sort
 * direction: up
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int alln(FILE *f)
{
    int all = 0;
    int num;
    while (1)
    {
        if (fread(&num, sizeof(int), 1, f) == 0)
            break;
        all++;
    }
    return all;
}

int get_number_by_pos(FILE *f, int pos)
{
    int num;
    fseek(f, pos * sizeof(int), SEEK_SET);
    fread(&num, sizeof(int), 1, f);
    return num;
}

void put_number_by_pos(FILE *f, int pos, int num)
{
    fseek(f, pos * sizeof(int), SEEK_SET);
    fwrite(&num, sizeof(int), 1, f);
}

int create_file(char *s)
{
    FILE *f;
    f = fopen(s, "wb");
    if (!f)
        return -1;
    int size = rand() % 100 + 1;
    int num;
    for (int i = 0; i < size; i++)
    {
        num = -100 + rand() % 201;
        fwrite(&num, sizeof(int), 1, f);
    }
    fclose(f);
    return 0;
}

int sort_file(char *s)
{
    FILE *f;
    f = fopen(s, "rb+");
    if (!f)
        return -1;
    int num;
    int el1, el2;
    if (fread(&num, sizeof(int), 1, f) == 0)
    {
        fclose(f);
        return -1;
    }
    rewind(f);
    int all = alln(f);
    if (all == 0)
    {
        fclose(f);
        return -1;
    }
    rewind(f);
    for (int i = 0; i < all; i++)
    {
        for (int j = 0; j < all; j++)
        {
            el1 = get_number_by_pos(f, j);
            el2 = get_number_by_pos(f, j + 1);
            if (el1 > el2)
            {
                put_number_by_pos(f, j, el2);
                put_number_by_pos(f, j + 1, el1);
            }
        }
    }
    fclose(f);
    return 0;
}

int print_file(char *s)
{
    FILE *f;
    f = fopen(s, "rb");
    int num;
    if (!f)
        return -1;
    if (fread(&num, sizeof(int), 1, f) == 0)
        return -1;
    rewind(f);
    while (1)
    {
        if (fread(&num, sizeof(int), 1, f) == 0)
            break;
        printf("%d ", num);
    }
    fclose(f);
    return 0;
}

int main(int argc, char **argv)
{
    //printf("%d argc \n", argc);
    //printf("%s argv1 \n", argv[1]);
    //printf("%s argv3 \n", argv[3]);
    srand(time(NULL));
    char comp = *argv[1];
    int check;
    if (argc == 3)
    {
        if (comp == 'c')
            check = create_file(argv[2]);
        if (comp == 's')
            check = sort_file(argv[2]);
        if (comp == 'p')
            check = print_file(argv[2]);
    }
    else
    {
        printf("not enough args");
        return -1;
    }
    if (check != 0)
    {
        printf("Incorrect data");
        return -1;
    }
    return 0;
}

#include <stdio.h>
#include <string.h>

#define CONS_ERR 53
#define CORR 0
#define OPEN_ERR -1
#define EMPTY_ERR -2
#define SIZE_ERR -3
#define LESS_ERR -4
#define READ_ERR -5

#define SURNAME_LENGTH 25
#define NAME_LENGTH 10
#define MARKS_LENGTH

typedef char surname_t[SURNAME_LENGTH + 1];
typedef char name_t[NAME_LENGTH + 1];
typedef long unsigned int marks_t[4];

typedef struct
{
    surname_t surname;
    name_t name;
    marks_t marks;
} student_t;

void output_student(student_t student)
{
    printf("Surname: %s\n", student.surname);
    printf("Name: %s\n", student.name);
    puts("Marks: ");
    for (int i = 0; i < 4; i++)
        printf("%lu ", student.marks[i]);
    printf("\n");
}

void get_item_by_pos(FILE* f, student_t *student, size_t pos)
{
    fseek(f, sizeof(student_t) * pos, SEEK_SET);
    fread(student, sizeof(student_t), 1, f);
}

void put_item_by_pos(FILE* f, student_t student, size_t pos)
{
    fseek(f, sizeof(student_t) * pos, SEEK_SET);
    fwrite(&student, sizeof(student_t), 1, f);
}

void swap_students(student_t *student1, student_t *student2)
{
    student_t temp_student;
    temp_student = *student1;
    *student1 = *student2;
    *student2 = temp_student;
}

int input_students(char *filename)
{
    size_t length;
    surname_t surbuff;
    name_t nambuff;
    int rc;
    student_t temp_student;
    FILE* f = fopen(filename, "wb");

    puts("Enter the number of students:");

    rc = scanf("%I64u", &length);

    if (!rc)
        return SIZE_ERR;

    for (size_t i = 0; i < length; i++)
    {
        rc = 0;
        fflush(stdin);
        printf("Enter the surname:\n");
        rc += scanf("%s", surbuff);
        strcpy(temp_student.surname, surbuff);
        printf("Enter the name:\n");
        rc += scanf("%s", nambuff);
        strcpy(temp_student.name, nambuff);
        printf("Enter the marks:\n");
        for (int j = 0; j < 4; j++)
            rc += scanf("%lu", &temp_student.marks[j]);
        if (rc != 6)
            return LESS_ERR;
        put_item_by_pos(f, temp_student, i);
    }

    fclose(f);
    return CORR;
}

int output_students(char *filename)
{
    int rc;
    student_t temp_student;
    FILE* f;

    f = fopen(filename, "rb");

    if (f == NULL)
        return OPEN_ERR;

    fseek(f, 0, SEEK_END);
    if (!ftell(f))
        return EMPTY_ERR;
    rewind(f);

    while (1)
    {
        rc = fread(&temp_student, sizeof(student_t), 1, f);
        //break???
        if (rc != 1)
            return READ_ERR;
        output_student(temp_student);
    }

    return CORR;
}

int starts_with_substr(char *str, char *substr)
{
    size_t delta = strlen(str) - strlen(substr);
    int check = 1;

    if (delta < 0)
        return 0;
    for (size_t i = 0; i < strlen(substr) && check; i++)
        if (substr[i] != str[i])
            check = 0;

    return check;
}

int output_by_substr(char *filename, char *filename_out, char *substr)
{
    int rc;
    student_t temp_student;
    FILE *f = fopen(filename, "rb");
    FILE *f_out = fopen(filename_out, "wb+");
    if (f == NULL)
        return OPEN_ERR;

    fseek(f, 0, SEEK_END);
    if (!ftell(f))
        return EMPTY_ERR;
    rewind(f);

    while (1)
    {
        rc = fread(&temp_student, sizeof(student_t), 1, f);
        if (rc != 1)
        {
            fclose(f);
            fclose(f_out);
            return READ_ERR;//also break
        }
        if (starts_with_substr(temp_student.surname, substr))
        {
            output_student(temp_student);
            fwrite(&temp_student, sizeof(student_t), 1, f_out);
        }
    }
    return CORR;
}

int sort_by_surname(char *filename_in)
{
    int rc;
    int check;
    student_t temp_student;
    student_t first_student, second_student;
    size_t length = 0;
    puts("3");
    FILE *f_in;

    f_in = fopen(filename_in, "r+b");

    if (f_in == NULL)
        return OPEN_ERR;

    fseek(f_in, 0, SEEK_END);
    if (!ftell(f_in))
        return EMPTY_ERR;
    rewind(f_in);

    while (1)
    {
        rc = fread(&temp_student, sizeof(student_t), 1, f_in);
        if (rc != 1)
            break;
        length++;
    }

    for (size_t i = 0; i < length && check; i++)
    {
        check = 0;
        for (size_t j = 0; j < length - i - 1; j++)
        {
            get_item_by_pos(f_in, &first_student, j);
            get_item_by_pos(f_in, &second_student, j + 1);
            if (strcmp(first_student.surname, second_student.surname) > 0)
            {
                swap_students(&first_student, &second_student);
                put_item_by_pos(f_in, first_student, j);
                put_item_by_pos(f_in, second_student, j + 1);
                check = 1;
            }
            else if (strcmp(first_student.surname, second_student.surname) == 0 && strcmp(first_student.name, second_student.name) > 0)
            {
                swap_students(&first_student, &second_student);
                put_item_by_pos(f_in, first_student, j);
                put_item_by_pos(f_in, second_student, j + 1);
                check = 1;
            }
        }
        if (!check)
            break;
    }

    fclose(f_in);

    return CORR;
}

int main(int argc, char **argv)
{
    int rc;
    //printf("%s \n", argv[2]);
    //printf("%s\n", argv[3]);
    //printf("%s\n", argv[4]);
    if (argc != 4 && argc != 6)
    {
        fprintf(stderr, "Wrong number of parameters.\n");
        return CONS_ERR;
    }
    //input_students(argv[]);
    if (strcmp(argv[2], "sb") == 0)
    {
        rc = sort_by_surname(argv[3]);
        rc = output_students(argv[3]);
    }
    else if (strcmp(argv[2], "fb") == 0)
        rc = output_by_substr(argv[3], argv[4], argv[5]);
    else
    {
        fprintf(stderr, "Unknown key.\n");
        rc = CONS_ERR;
    }

    switch (rc)
    {
        case CONS_ERR:
            fprintf(stderr, "Console error.");
            return CONS_ERR;
        case CORR:
            return rc;
    }
}

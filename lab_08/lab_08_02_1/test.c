#include <stdio.h>
#include <stdlib.h>
#include "main.h"

void test_maxfinder()
{
    double *mas;
    mas = (double*)malloc(3 * sizeof(double));
    double *eptr = mas + 3;
    int err_cnt = 0;
    *(mas) = 0, *(mas + 1) = 1, *(mas + 2) = 2;
    if (maxfinder(mas, eptr) != 2)
        err_cnt++;
    *(mas) = 4, *(mas + 1) = 1, *(mas + 2) = 0;
    eptr = mas + 3;
    if (maxfinder(mas, eptr) != 4)
        err_cnt++;
    *(mas) = 2, *(mas + 1) = 6, *(mas + 2) = 1;
    eptr = mas + 3;
    if (maxfinder(mas, eptr) != 6)
        err_cnt++;
    if (err_cnt == 0)
        printf("test_maxfinder OK\n");
    else
        printf("test_maxfinder ERROR\n");
    free(mas);
}

void test_insertmas()
{
    double *mas;
    int no_err_cnt = 0;
    int n = 3;
    mas = (double*)malloc(n * sizeof(double));
    double *eptr = mas + n;
    *(mas) = 0, *(mas + 1) = 1, *(mas + 2) = 2;
    int inspos = 1;
    insertmas(&mas, eptr, &n, inspos);
    if ((int)*(mas) == 2 && (int)*(mas + 1) == 0 && (int)*(mas + 2) == 2 && (int)*(mas + 3) == 1 && (int)*(mas + 4) == 2 && (int)*(mas + 5) == 2)
        no_err_cnt++;
    inspos = 2;
    n = 3;
    eptr = mas + n;
    *(mas) = 0, *(mas + 1) = 1, *(mas + 2) = 1;
    insertmas(&mas, eptr, &n, inspos);
    if ((int)*(mas) == 1 && (int)*(mas + 1) == 0 && (int)*(mas + 2) == 1 && (int)*(mas + 3) == 1 && (int)*(mas + 4) == 1 && (int)*(mas + 5) == 1)
        no_err_cnt++;
    if (no_err_cnt == 2)
        printf("test_insertmas OK\n");
    else
        printf("test_insertmas ERROR\n");
    free(mas);
}

void test_masremove()
{
    double *mas;
    int err_cnt = 0;
    int n = 4;
    mas = (double*)malloc(n * sizeof(double));
    double *eptr = mas + n;
    int srarifm = 1.5;
    *(mas) = 0, *(mas + 1) = 1, *(mas + 2) = 2, *(mas + 3) = 3;
    masremove(&n, &mas, srarifm, eptr);
    if (*mas != 0 || *(mas + 1) != 1 || eptr != mas + 2)
        err_cnt++;
    *(mas) = 5, *(mas + 1) = 3;
    srarifm = 6;
    if (*mas != 5 || *(mas + 1) != 6 || eptr != mas + 2)
        err_cnt++;
    if (err_cnt != 0)
        printf("test_masremove OK\n");
    else
        printf("test_masremove ERROR\n");
    free(mas);
}

int main()
{
    test_maxfinder();
    test_insertmas();
    test_masremove();
    return OK;
}

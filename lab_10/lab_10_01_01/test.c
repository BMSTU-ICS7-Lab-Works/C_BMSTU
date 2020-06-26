#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "app.h"

void test_check_date()
{
    int err_cnt = 0;
    char date[256];
    int param = 0;
    strcpy(date, "2002.02.02");
    if (check_date(date, param) != 0)
        err_cnt++;
    strcpy(date, "2000.02.29");
    if (check_date(date, param) != 0)
        err_cnt++;
    strcpy(date, "2015.02.29");
    if (check_date(date, param) == 0)
        err_cnt++;
    strcpy(date, "-6.02.02");
    if (check_date(date, param) == 0)
        err_cnt++;
    strcpy(date, "2002.2.02");
    if (check_date(date, param) == 0)
        err_cnt++;
    strcpy(date, "2002.2.a");
    if (check_date(date, param) == 0)
        err_cnt++;
    strcpy(date, "2002.13.02");
    if (check_date(date, param) == 0)
        err_cnt++;
    strcpy(date, "2002.00.02");
    if (check_date(date, param) == 0)
        err_cnt++;
    strcpy(date, "2002.02.00");
    if (check_date(date, param) == 0)
        err_cnt++;
    strcpy(date, "2002.11.31");
    if (check_date(date, param) == 0)
        err_cnt++;
    param = 1;
    strcpy(date, "2002.11.02");
    if (check_date(date, param) == 0)
        err_cnt++;
    strcpy(date, "2002.11.01");
    if (check_date(date, param) != 0)
        err_cnt++;
    if (err_cnt == 0)
    {
        printf("test_check_date: OK\n");
    }
    else
        printf("test_check_date: ERRORS FOUND\n");
}

void test_delete_girls()
{
    int err_cnt = 0;
    int countlist = 3;
    schooler_t *schooler;
    schooler = create();
    resize(&schooler, 3);
    schooler->sex = (char*)malloc(256);
    schooler->date = (char*)malloc(256);
    schooler->surname = (char*)malloc(256);
    schooler->marks = (int*)malloc((4) * sizeof(int));
    (schooler + 1)->sex = (char*)malloc(256);
    (schooler + 1)->date = (char*)malloc(256);
    (schooler + 1)->surname = (char*)malloc(256);
    (schooler + 1)->marks = (int*)malloc((4) * sizeof(int));
    (schooler + 2)->sex = (char*)malloc(256);
    (schooler + 2)->date = (char*)malloc(256);
    (schooler + 2)->surname = (char*)malloc(256);
    (schooler + 2)->marks = (int*)malloc((4) * sizeof(int));
    strcpy(schooler->sex, "female");
    strcpy(schooler->date, "2000.02.02");
    strcpy((schooler + 1)->sex, "female");
    strcpy((schooler + 1)->date, "2012.02.02");
    strcpy((schooler + 2)->sex, "male");
    strcpy((schooler + 2)->date, "2000.02.02");
    int countlist_mem = countlist;
    delete_girls(schooler, &countlist);
    if (countlist != 2)
        err_cnt++;
    freetable(schooler, countlist_mem);
    if (err_cnt == 0)
    {
        printf("test_delete_girls: OK\n");
    }
    else
        printf("test_delete_girls: ERRORS FOUND\n");
}

void test_add_marks()
{
    int err_cnt = 0;
    schooler_t *schooler;
    schooler = create();
    schooler->marks = (int*)malloc((4) * sizeof(int));
    schooler->marks[0] = 3;
    schooler->marks[1] = 2;
    schooler->marks[2] = 3;
    schooler->marks[3] = 4;
    add_marks(schooler, 1);
    if (schooler->marks[0] != 4 || schooler->marks[1] != 2 || schooler->marks[2] != 3 || schooler->marks[3] != 4 || schooler->marks[4] != 3)
        err_cnt++;
    schooler->marks[0] = 1;
    schooler->marks[1] = 1;
    add_marks(schooler, 1);
    if (schooler->marks[0] != 2 || schooler->marks[1] != 1 || schooler->marks[2] != 3)
        err_cnt++;
    free(schooler->marks);
    free(schooler);
    if (err_cnt == 0)
    {
        printf("test_add_marks: OK\n");
    }
    else
        printf("test_add_marks: ERRORS FOUND\n");
}

void test_srarifm()
{
    int err_cnt = 0;
    schooler_t *schooler;
    schooler = create();
    schooler->marks = (int*)malloc((4) * sizeof(int));
    schooler->marks[0] = 3;
    schooler->marks[1] = 2;
    schooler->marks[2] = 3;
    schooler->marks[3] = 4;
    if (srarifm(*schooler) != 3.000000)
        err_cnt++;
    schooler->marks[1] = 1;
    schooler->marks[2] = 1;
    schooler->marks[3] = 1;
    if (srarifm(*schooler) != 1.000000)
        err_cnt++;
    free(schooler->marks);
    free(schooler);
    if (err_cnt == 0)
    {
        printf("test_srarifm: OK\n");
    }
    else
        printf("test_srarifm: ERRORS FOUND\n");
}

void test_sort()
{
    int err_cnt = 0;
    schooler_t *schooler;
    schooler = create();
    resize(&schooler, 3);
    schooler->surname = (char*)malloc(256);
    strcpy((schooler)->surname, "Kyro");
    (schooler + 1)->surname = (char*)malloc(256);
    strcpy((schooler + 1)->surname, "Aaron");
    (schooler + 2)->surname = (char*)malloc(256);
    strcpy((schooler + 2)->surname, "Aban");
    sort(schooler, 3, surcomp);
    if (strcmp((schooler)->surname, "Aaron") != 0 || strcmp((schooler + 1)->surname, "Aban") != 0 || strcmp((schooler + 2)->surname, "Kyro") != 0)
        err_cnt++;
    strcpy((schooler)->surname, "Aaron");
    strcpy((schooler + 1)->surname, "Aban");
    strcpy((schooler + 2)->surname, "Kaban");
    sort(schooler, 3, surcomp);
    if (strcmp((schooler)->surname, "Aaron") != 0 || strcmp((schooler + 1)->surname, "Aban") != 0 || strcmp((schooler + 2)->surname, "Kaban") != 0)
        err_cnt++;
    (schooler)->sex = (char*)malloc(256);
    strcpy((schooler)->sex, "female");
    (schooler + 1)->sex = (char*)malloc(256);
    strcpy((schooler + 1)->sex, "male");
    (schooler + 2)->sex = (char*)malloc(256);
    strcpy((schooler + 2)->sex, "male");
    sort(schooler, 3, sexcomp);
    if (strcmp((schooler)->sex, "female") != 0 || strcmp((schooler + 1)->sex, "male") != 0 || strcmp((schooler + 2)->sex, "male") != 0)
        err_cnt++;
    strcpy((schooler)->sex, "male");
    strcpy((schooler + 1)->sex, "female");
    strcpy((schooler + 2)->sex, "female");
    sort(schooler, 3, sexcomp);
    if (strcmp((schooler)->sex, "female") != 0 || strcmp((schooler + 1)->sex, "female") != 0 || strcmp((schooler + 2)->sex, "male") != 0)
        err_cnt++;
    (schooler)->date = (char*)malloc(256);
    strcpy((schooler)->date, "2002.02.02");
    (schooler + 1)->date = (char*)malloc(256);
    strcpy((schooler + 1)->date, "2002.02.03");
    (schooler + 2)->date = (char*)malloc(256);
    strcpy((schooler + 2)->date, "2003.03.03");
    sort(schooler, 3, datecomp);
    if (strcmp((schooler)->date, "2002.02.02") != 0 || strcmp((schooler + 1)->date, "2002.02.03") != 0
        || strcmp((schooler + 2)->date, "2003.03.03") != 0)
        err_cnt++;
    strcpy((schooler)->date, "2001.03.03");
    strcpy((schooler + 1)->date, "1235.02.02");
    strcpy((schooler + 2)->date, "1555.01.02");
    sort(schooler, 3, datecomp);
    if (strcmp((schooler)->date, "1235.02.02") != 0 || strcmp((schooler + 1)->date, "1555.01.02") != 0
        || strcmp((schooler + 2)->date, "2001.03.03") != 0)
        err_cnt++;
    schooler->marks = (int*)malloc((4) * sizeof(int));
    schooler->marks[0] = 3;
    schooler->marks[1] = 2;
    schooler->marks[2] = 3;
    schooler->marks[3] = 4;
    //3
    (schooler + 1)->marks = (int*)malloc((3) * sizeof(int));
    (schooler + 1)->marks[0] = 2;
    (schooler + 1)->marks[1] = 1;
    (schooler + 1)->marks[2] = 1;
    //1
    (schooler + 2)->marks = (int*)malloc((5) * sizeof(int));
    (schooler + 2)->marks[0] = 4;
    (schooler + 2)->marks[1] = 2;
    (schooler + 2)->marks[2] = 2;
    (schooler + 2)->marks[3] = 2;
    (schooler + 2)->marks[4] = 2;
    //2
    sort(schooler, 3, markscomp);
    if (schooler->marks[0] != 2 || (schooler + 1)->marks[0] != 4 || (schooler + 2)->marks[0] != 3)
        err_cnt++;
    freetable(schooler, 3);
    if (err_cnt == 0)
    {
        printf("test_sort: OK\n");
    }
    else
        printf("test_sort: ERRORS FOUND\n");
}

int main()
{
    test_check_date();
    test_delete_girls();
    test_add_marks();
    test_srarifm();
    test_sort();
    return CORR_END;
}

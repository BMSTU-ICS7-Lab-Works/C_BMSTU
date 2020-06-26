#include <stdio.h>
#include "functions.h"

void test_my_snprintf_s()
{
    int err_cnt = 0;
    char my_buffer[100] = "";
    char buffer[100] = "";
    int a = snprintf(buffer, 0, "I live in %s sleep in %s", "Russia", "Alaska");
    int my_a = my_snprintf(my_buffer, 0, "I live in %s sleep in %s", "Russia", "Alaska");
    if (a != my_a)
        err_cnt++;
    a = snprintf(buffer, 20, "I live in %s sleep in %s", "Russia", "Alaska");
    my_a = my_snprintf(my_buffer, 20, "I live in %s sleep in %s", "Russia", "Alaska");
    if (a != my_a || my_strcmp(buffer, my_buffer) != 0)
        err_cnt++;
    a = snprintf(buffer, 100, "I live in %s sleep in %s", "Russia", "Alaska");
    my_a = my_snprintf(my_buffer, 100, "I live in %s sleep in %s", "Russia", "Alaska");
    if (a != my_a || my_strcmp(buffer, my_buffer) != 0)
        err_cnt++;
    if (err_cnt == 0)
    {
        printf("my_snprintf_s: OK\n");
    }
    else
    {
        printf("my_snprintf_s: ERROR\n");
    }
    //printf("\nErr_cnt %d\n", err_cnt);
}

void test_my_snprintf_o()
{
    int err_cnt = 0;
    char my_buffer[100] = "";
    char buffer[100] = "";
    int a = snprintf(buffer, 0, "SIXTY IN EIGTH IS %ld DIVIDED BY TWO %ld", 60, 60/2);
    int my_a = my_snprintf(my_buffer, 0, "SIXTY IN EIGTH IS %ld DIVIDED BY TWO %ld", 60, 60/2);
    if (a != my_a)
        err_cnt++;
    a = snprintf(buffer, 20, "SIXTY IN EIGTH IS %ld DIVIDED BY TWO %ld", 60, 60/2);
    my_a = my_snprintf(my_buffer, 20, "SIXTY IN EIGTH IS %ld DIVIDED BY TWO %ld", 60, 60/2);
    //printf("\na %d my_a %d\nbuffer %s \nmy_buffer %s\n", a, my_a, buffer, my_buffer);
    if (a != my_a || my_strcmp(buffer, my_buffer) != 0)
        err_cnt++;
    a = snprintf(buffer, 100, "SIXTY IN EIGTH IS %ld DIVIDED BY TWO %ld", 60, 60/2);
    my_a = my_snprintf(my_buffer, 100, "SIXTY IN EIGTH IS %ld DIVIDED BY TWO %ld", 60, 60/2);
    //printf("\na %d my_a %d\nbuffer %s \nmy_buffer %s\n", a, my_a, buffer, my_buffer);
    if (a != my_a || my_strcmp(buffer, my_buffer) != 0)
        err_cnt++;
    if (err_cnt == 0)
    {
        printf("my_snprintf_o: OK\n");
    }
    else
    {
        printf("my_snprintf_o: ERROR\n");
    }
    //printf("\nErr_cnt %d\n", err_cnt);
}

void test_my_snprintf_all()
{
    int err_cnt = 0;
    char my_buffer[100] = "";
    char buffer[100] = "";
    int a = snprintf(buffer, 0, "My name is %s i am DKOOl and my age is %ld", "KOOL", 2);
    int my_a = my_snprintf(my_buffer, 0, "My name is %s i am DKOOl and my age is %ld", "KOOL", 2);
    if (a != my_a)
        err_cnt++;
    a = snprintf(buffer, 20, "My name is %s i am DKOOl and my age is %ld", "KOOL", 2);
    my_a = my_snprintf(my_buffer, 20, "My name is %s i am DKOOl and my age is %ld", "KOOL", 2);
    //printf("\na %d my_a %d\nbuffer %s \nmy_buffer %s\n", a, my_a, buffer, my_buffer);
    if (a != my_a || my_strcmp(buffer, my_buffer) != 0)
        err_cnt++;
    a = snprintf(buffer, 100, "My name is %s i am DKOOl and my age is %ld", "KOOL", 2);
    my_a = my_snprintf(my_buffer, 100, "My name is %s i am DKOOl and my age is %ld", "KOOL", 2);
    //printf("\na %d my_a %d\nbuffer %s \nmy_buffer %s\n", a, my_a, buffer, my_buffer);
    if (a != my_a || my_strcmp(buffer, my_buffer) != 0)
        err_cnt++;
    if (err_cnt == 0)
    {
        printf("my_snprintf_all: OK\n");
    }
    else
    {
        printf("my_snprintf_all: ERROR\n");
    }
    //printf("\nErr_cnt %d\n", err_cnt);
}

int main()
{
    test_my_snprintf_s();
    test_my_snprintf_o();
    test_my_snprintf_all();
    return CORR_END;
}


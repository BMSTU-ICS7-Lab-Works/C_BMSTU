#include <stdio.h>
#include <stdlib.h>
#include "main.h"

int main()
{
    list_t *list1;
    list_t *list2;
    int coef, power;
    float coef1, power1;
    int flag = 0;
    while (1)
    {
        printf("Input letter to stop\n");
        printf("Input coefficient and power: ");
        if (!scanf("%f", &coef1))
            break;
        coef = coef1;
        if (coef1 - coef != 0)
        {
            printf("\nInput number is float!");
            if (flag == 1)
                deleteall(list1);
            return ERR_FLOAT;
        }
        if (!scanf("%f", &power1))
            break;
        power = power1;
        if (power1 - power != 0 || power < 0)
        {
            printf("\nInput number is float or less than zero!");
            if (flag == 1)
                deleteall(list1);
            return ERR_FLOAT;
        }
        if (flag == 0)
        {
            list1 = init(coef, power);
            flag = 1;
        }
        else
        {
            if (addelem(list1, coef, power) == NULL)
            {
                deleteall(list1);
                return ERR_POLYNOME;
            }
        }
    }
    fflush(stdin);
    if (flag == 0)
    {
        printf("No polynome was written!");
        return ERR_POLYNOME;
    }
    flag = 0;
    int x;
    float x1;
    printf("Enter x for task a: ");
    if (!scanf("%f", &x1))
    {
        printf("\nX should be integer!");
        deleteall(list1);
        return ERR_LETTER;
    }
    x = x1;
    if (x1 - x != 0)
    {
        printf("\nX should be integer!");
        deleteall(list1);
        return ERR_FLOAT;
    }
    int result1 = task_a(list1, x);
    //int result2 = task_a(list2, x);
    printf("\nTask A result: %d\n", result1);
    list_t *list_proizv;
    list_proizv = task_b(list1);
    if (list_proizv == NULL)
    {
        printf("\nDerivative for this polynome is 0\n");
    }
    else
    {
        puts("\nTask B result list: ");
        listprint(list_proizv);
        deleteall(list_proizv);
    }
    //task_b(list2);
   // listprint(list2);
    list_t *list_sum;
    while (1)
    {
        printf("Input letter to stop\n");
        printf("Input coefficient and power: ");
        if (!scanf("%f", &coef1))
            break;
        coef = coef1;
        if (coef1 - coef != 0)
        {
            printf("\nInput number is float!");
            deleteall(list1);
            if (flag == 1)
                deleteall(list2);
            return ERR_FLOAT;
        }
        if (!scanf("%f", &power1))
            break;
        power = power1;
        if (power1 - power != 0 || power < 0)
        {
            printf("\nInput number is float or less than zero!");
            deleteall(list1);
            if (flag == 1)
                deleteall(list2);
            return ERR_FLOAT;
        }
        if (flag == 0)
        {
            list2 = init(coef, power);
            flag = 1;
        }
        else
        {
            if (addelem(list2, coef, power) == NULL)
            {
                deleteall(list1);
                deleteall(list2);
                return ERR_POLYNOME;
            }
        }
    }
    if (flag == 0)
    {
        printf("No polynome was written!");
        return ERR_POLYNOME;
    }
    list_sum = task_c(list1, list2);
    puts("\nTask C result list: ");
    listprint(list_sum);
    deleteall(list_sum);
    list_t *list_odd = task_d_odd(list1);
    list_t *list_even = task_d_even(list1);
    if (list_odd)
    {
        printf("\nList odd:");
        listprint(list_odd);
        deleteall(list_odd);
    }
    else
    {
        printf("\nThere is no odd numbers in polynome");
    }
    if (list_even)
    {
        printf("\nList even:");
        listprint(list_even);
        deleteall(list_even);
    }
    else
    {
        printf("\nThere is no even numbers in polynome");
    }
    deleteall(list1);
    deleteall(list2);
    return CORR_END;
}

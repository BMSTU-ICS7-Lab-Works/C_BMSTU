#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "main.h"

int task_a(list_t *list, int a)
{
    int result = 0;
    list_t *p;
    p = list;
    do
    {
        result += (int) p->coef * pow(a, p->power);
        p = p->ptr; // переход к следующему узлу
    } while (p != NULL);
    return result;
}

list_t *task_b(list_t *list)
{
    int flag = 0;
    list_t *list_res;
    do
    {
        if (flag == 0)
        {

            if (list->power != 0)
            {
                list_res = init(list->coef * list->power, list->power - 1);
                flag = 1;
            }
        }
        else
        {
            if (list->power != 0)
                addelem(list_res, list->coef * list->power, list->power - 1);
        }
        list = list->ptr; // переход к следующему узлу
    } while (list != NULL);
    if (flag == 0)
        return NULL;
    return list_res;
}

list_t *task_c(list_t *list1, list_t *list2)
{
    int flag = 0;
    int breaked = 0;
    list_t *list_res;
    list_t *temp = list2;
    do
    {
        while (temp != NULL)
        {
            if (temp->power == list1->power)
            {
                if (flag == 0)
                {
                    flag = 1;
                    list_res = init(temp->coef + list1->coef, temp->power);
                }
                else
                {
                    addelem(list_res, temp->coef + list1->coef, temp->power);
                }
                temp = temp->ptr;
                break;
            }
            else if (temp->power > list1->power)
            {
                if (flag == 0)
                {
                    flag = 1;
                    list_res = init(temp->coef, temp->power);
                }
                else
                    addelem(list_res, temp->coef, temp->power);
            }
            else
            {
                if (flag == 0)
                {
                    flag = 1;
                    list_res = init(list1->coef, list1->power);
                }
                else
                    addelem(list_res, list1->coef, list1->power);
                break;
            }
            temp = temp->ptr;
        }
        if (temp == NULL && breaked == 1)
        {
            if (flag == 0)
            {
                flag = 1;
                list_res = init(list1->coef, list1->power);
            }
            else
                addelem(list_res, list1->coef, list1->power);
        }
        if (temp == NULL)
            breaked = 1;
        list1 = list1->ptr;
    } while (list1 != NULL);
    while (temp != NULL)
    {
        if (flag == 0)
        {
            flag = 1;
            list_res = init(temp->coef, temp->power);
        }
        else
            addelem(list_res, temp->coef, temp->power);
        temp = temp->ptr;
    }
    return list_res;
}

list_t *task_d_even(list_t *list)
{
    list_t *list_res;
    int flag = 0;
    do
    {
        if (list->power % 2 == 0)
        {
            //puts("AYAY");
            if (flag == 0)
            {
                //puts("AYAY\n\n");
                flag = 1;
                list_res = init(list->coef, list->power);
            }
            else
                addelem(list_res, list->coef, list->power);
        }
        list = list->ptr; // переход к следующему узлу
    } while (list != NULL);
    //listprint(list_res);
    if (flag ==1)
        return list_res;
    else
        return NULL;
}

list_t *task_d_odd(list_t *list)
{
    list_t *list_res;
    int flag = 0;
    do
    {
        if (list->power % 2 != 0)
        {
            if (flag == 0)
            {
                flag = 1;
                list_res = init(list->coef, list->power);
            }
            else
                addelem(list_res, list->coef, list->power);
        }
        list = list->ptr; // переход к следующему узлу
    } while (list != NULL);
    if (flag ==1)
        return list_res;
    else
        return NULL;
}

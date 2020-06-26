#include <stdio.h>
#include <stdlib.h>
#include "main.h"

list_t *init(int coef, int power)
{
    list_t *list;
    list = (list_t*)malloc(sizeof(list_t));
    list->coef = coef;
    list->power = power;
    list->ptr = NULL;
    return list;
}

list_t *addelem(list_t *list, int coef, int power)
{
    if (list->power <= power)
    {
        printf("\nPolynoms should be decreasing");
        return NULL;
    }
    list_t *temp, *p;
    temp = (list_t*)malloc(sizeof(list_t));
    while (list->ptr != NULL)
        list = list->ptr;
    p = list->ptr;
    list->ptr = temp;
    temp->coef = coef;
    temp->power = power;
    temp->ptr = p;
    return temp;
}

list_t *deleteall(list_t *list)
{
    list_t *next, *temp;
    temp = list;
    next = list;
    do
    {
        temp = next;
        next = temp->ptr;
        free(temp);
    } while (next != NULL);
    return temp;
}

void listprint(list_t *list)
{
    list_t *p;
    p = list;
    do
    {
        if (p->coef != 0)
        {
            printf("%d %d  ", p->coef, p->power); // вывод значения элемента p
        }
        p = p->ptr; // переход к следующему узлу
    } while (p != NULL);
    puts("");
}

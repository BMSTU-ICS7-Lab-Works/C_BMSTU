#ifndef MAIN_H
#define MAIN_H

#define CORR_END 0;
#define ERR_FLOAT -1;
#define ERR_LETTER -2;
#define ERR_POLYNOME -3;

typedef struct list
{
    int coef;
    int power;
    struct list *ptr;
}list_t;

list_t *init(int coef, int power);
list_t *addelem(list_t *list, int coef, int power);
list_t *deleteall(list_t *list);
void listprint(list_t *list);
int task_a(list_t *list, int a);
list_t *task_b(list_t *list);
list_t *task_c(list_t *list1, list_t *list2);
list_t *task_d_even(list_t *list);
list_t *task_d_odd(list_t *list);

#endif // MAIN_H

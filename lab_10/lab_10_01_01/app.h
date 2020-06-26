#ifndef APP_H
#define APP_H

#define ERR_EMPTY -8
#define ERR_NO_MEM -7
#define ERR_INPUT -6
#define WRONG_AGE -5
#define ERR_OPEN -4
#define WRONG_FILL -3
#define WRONG_FIELD -2
#define WRONG_DATE -1
#define CORR_END 0
#define CORR_FILL 1

typedef struct schooler
{
    char *surname;
    char *sex;
    char *date;
    int *marks;
} schooler_t;

float srarifm(schooler_t schooler);
int surcomp(schooler_t *prev, schooler_t *next);
int sexcomp(schooler_t *prev, schooler_t *next);
int datecomp(schooler_t *prev, schooler_t *next);
int markscomp(schooler_t *prev, schooler_t *next);
void swap(schooler_t *prev, schooler_t *next);
void sort(schooler_t *schoolers, int countlist, int (*compare)(schooler_t*, schooler_t*));
int out_file(schooler_t *schooler, int countlist);
int show_table(schooler_t *schooler, int countlist);
int check_date(char *date, int param);
int input_field(schooler_t *schooler);
int delete_field(schooler_t *schoolers, int curi, int *countlist);
int delete_girls(schooler_t *schoolers, int *countlist);
int add_marks(schooler_t *schoolers, int countlist);
schooler_t *create();
int resize(schooler_t **schooler, int newsize);
void freetable(schooler_t *schooler, int countlist);

#endif // APP_H

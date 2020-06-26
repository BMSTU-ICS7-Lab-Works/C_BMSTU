#ifndef MAIN_H
#define MAIN_H

#define CORR_END 0;
#define ERR_FLOAT_INP -1;
#define ERR_NUM_INP -2;
#define ERR_NO_MEM -3;
#define ERR_FUNC -4;
#define ERR_WRONG_INP -5;

long long int **create(long long int, long long int);
int input(long long int, long long int, long long int **);
int output(long long int, long long int, long long int **);
int freematr(long long int**, long long int);
int freerow(long long int, long long int, long long int***);
int del_rows(long long int*, long long int, long long int***, long long int);
long long int maxfinder(long long int, long long int, long long int**, int);
long long int **transpose(long long int*, long long int*, long long int***);
long long int srarifmcol(long long int**, long long int, long long int);
int add_row(long long int*, long long int, long long int***, int, long long int*);
int createrow(long long int, long long int, long long int***);
long long int minfinder(long long int, long long int, long long int**);
long long int **matrpow(long long int, long long int, long long int***, long long int**);
long long int **matrones(long long int, long long int, long long int**);

#endif // MAIN_H

#ifndef MAIN_H
#define MAIN_H
#define OK 0
#define ERR_N_INP -1
#define ERR_N_FLOAT -2
#define ERR_WRONG_ELEM -3
#define FUNC_ERR -4
#define ERR_NO_MEM -5
int mascreate(int, double**);
int masinp(double*, double*, double*);
int masout(double*, double*);
int resize(double**, int*);
int masremove(int*, double**, double, double*);
double maxfinder(double*, double*);
int insertmas(double**, double*, int*, int);
#endif // MAIN_H

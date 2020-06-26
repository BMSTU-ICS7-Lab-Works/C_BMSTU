#ifndef FUNC_H
#define FUNC_H

#include <stdio.h>
#include <limits.h>
#include <stdarg.h>

int my_snprintf(char *buf, size_t n, const char *format, ...);

int my_strlen(const char *str);
int my_strcmp(const char *a, const char *b);
void my_itoa(long int value, char *sp);
#endif // FUNC_H

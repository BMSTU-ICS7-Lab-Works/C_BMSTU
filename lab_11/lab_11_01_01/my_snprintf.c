#include "func.h"

int my_snprintf(char *buf, size_t n, const char *format, ...)
{
    int i = 0, j = 0, count = 0;
    va_list vl;
    va_start(vl, format);
    while (1)
    {
        if (i >= my_strlen(format))
            break;
        if (format[i] != '%')
        {
            if (i < (int) n - 1)
                buf[i + j] = format[i];
            count++;
        }
        else
        {
            if (format[i + 1] == 's')
            {
                char *str = va_arg(vl, char*);
                for (int x = i, z = j; x < i + my_strlen(str); x++, j++)
                {
                    count++;
                    if (x < (int) n - 1)
                        buf[x + z] = str[x - i];
                }
                i++;
                j -= 2;
            }
            else if (format[i + 1] == 'l')
            {
                if (format[i + 2] == 'd')
                {
                    char str[22];
                    my_itoa(va_arg(vl, long int), str);
                    for (int x = i, z = j; x < i + my_strlen(str); x++, j++)
                    {
                        count++;
                        if (x < (int) n - 1)
                            buf[x + z] = str[x - i];
                    }
                    i += 2;
                    j -= 3;
                }
                else
                {
                    if (i < (int) n - 1)
                        buf[i + j] = format[i];
                    count++;
                }
            }
            else
            {
                if (i < (int) n - 1)
                    buf[i + j] = format[i];
                count++;
            }
        }
        i++;
    }
    if (n > count)
        buf[count] = '\0';
    else if (n != 0)
        buf[(int) n - 1] = '\0';
    return count;
}

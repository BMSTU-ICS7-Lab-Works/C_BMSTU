#include <stdio.h>
#include <math.h>

float res(FILE *f, float midl, int count)
{
    float best, n, prev, tek;
    float arsred = midl / count;
    fscanf(f, "%f", &n);
    prev = arsred - n;
    if (prev < 0)
        prev *= -1;
    best = n;
    while (1)
    {
        if (fscanf(f, "%f", &n) != 1)
            break;
        tek = arsred - n;
        if (tek < 0)
            tek *= -1;
        if (prev > tek)
        {
            best = n;
            prev = tek;
        }
    }
    return best;
}

int middler(FILE *f, float *midl, int *count)
{
    float n;
    while (1)
    {
        if (fscanf(f, "%f", &n) != 1)
            break;
        *midl += n;
        *count = *count + 1;
    }
    return 0;
}

int main(int argc, char **argv)
{
    FILE *f;
    int count = 0;
    float midl = 0;
    float checker;
    f = fopen(argv[1], "r");
    if (fscanf(f, "%f", &checker) != 1)
    {
        printf("input error");
        fclose(f);
        return -1;
    }
    rewind(f);
    middler(f, &midl, &count);
    rewind(f);
    printf("%f", res(f, midl, count));
    fclose(f);
    return 0;
}

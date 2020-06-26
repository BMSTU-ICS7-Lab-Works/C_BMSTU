#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "main.h"

#define CORR_END 0;
#define ERR_FLOAT_INP -1;
#define ERR_NUM_INP -2;
#define ERR_WRONG_INP -5;

int main()
{
    float m1, n1, p1, q1;
    long long int m, n, p, q;
    long long int **matra = NULL, **matrb = NULL;
    int maxi = 0;
    puts("Enter M and N: ");
    if (!scanf("%f", &m1) || m1 <= 0)
    {
        printf("Wrong m");
        return ERR_NUM_INP;
    }
    m = m1;
    if (m != m1)
    {
        printf("m is float");
        return ERR_FLOAT_INP;
    }
    if (!scanf("%f", &n1) || n1 <= 0)
    {
        printf("Wrong n");
        return ERR_NUM_INP;
    }
    n = n1;
    if (n != n1)
    {
        printf("n is float");
        return ERR_FLOAT_INP;
    }
    matra = create(m, n);
    if (matra)
    {
        if (input(m, n, matra) != 0)
        {
            freematr(matra, m);
            return ERR_WRONG_INP;
        }
        while (m != n)
        {
            if (m > n)
            {
                maxi = maxfinder(m, n, matra, 1);
                del_rows(&m, n, &matra, maxi);
            }
            else
            {
                maxi = maxfinder(m, n, matra, 0);
                matra = transpose(&m, &n, &matra);
                del_rows(&m, n, &matra, maxi);
                matra = transpose(&m, &n, &matra);
            }
        }
    }
    else
    {
        freematr(matra, m);
        return ERR_FUNC;
    }
    puts("Enter P and Q: ");
    if (!scanf("%f", &p1) || p1 <= 0)
    {
        freematr(matra, m);
        printf("Wrong p");
        return ERR_NUM_INP;
    }
    p = p1;
    if (p != p1)
    {
        freematr(matra, m);
        printf("p is float");
        return ERR_FLOAT_INP;
    }
    if (!scanf("%f", &q1) || q1 <= 0)
    {
        freematr(matra, m);
        printf("Wrong q");
        return ERR_NUM_INP;
    }
    q = q1;
    if (q != q1)
    {
        freematr(matra, m);
        printf("q is float");
        return ERR_FLOAT_INP;
    }  
    matrb = create(p, q);
    if (matrb)
    {
        if (input(p, q, matrb) != 0)
        {
            freematr(matrb, p);
            freematr(matra, m);
            return ERR_WRONG_INP;
        }
        while (p != q)
        {
            if (p > q)
            {
                maxi = maxfinder(p, q, matrb, 1);
                del_rows(&p, q, &matrb, maxi);
            }
            else
            {
                maxi = maxfinder(p, q, matrb, 0);
                matrb = transpose(&p, &q, &matrb);
                del_rows(&p, q, &matrb, maxi);
                matrb = transpose(&p, &q, &matrb);
            }
        }
    }
    else
    {
        freematr(matrb, p);
        freematr(matra, m);
        return ERR_FUNC;
    }
    long long int masmin[m * p];
    while (m != p)
    {
        if (m < p)
            add_row(&m, n, &matra, 0, masmin);
        else
            add_row(&p, q, &matrb, 0, masmin);
    }
    while (n != q)
    {
        if (n < q)
        {
            for (long long int i = 0; i < m; i++)
                masmin[i] = minfinder(i, n, matra);
            matra = transpose(&m, &n, &matra);
            add_row(&m, n, &matra, 1, masmin);
            matra = transpose(&m, &n, &matra);
        }
        else
        {
            for (long long int i = 0; i < p; i++)
                masmin[i] = minfinder(i, q, matrb);
            matrb = transpose(&p, &q, &matrb);
            add_row(&p, q, &matrb, 1, masmin);
            matrb = transpose(&p, &q, &matrb);
        }
    }
    long long int st1, st2;
    double st11, st22;
    puts("Enter first and second degree: ");
    if (!scanf("%lf", &st11) || st11 < 0)
    {
        freematr(matrb, p);
        freematr(matra, m);
        printf("Wrong first degree");
        return ERR_NUM_INP;
    }
    st1 = st11;
    if (st1 != st11)
    {
        freematr(matrb, p);
        freematr(matra, m);
        printf("first degree is float");
        return ERR_FLOAT_INP;
    }
    if (!scanf("%lf", &st22) || st22 < 0)
    {
        freematr(matrb, p);
        freematr(matra, m);
        printf("Wrong second degree");
        return ERR_NUM_INP;
    }
    st2 = st22;
    if (st2 != st22)
    {
        freematr(matrb, p);
        freematr(matra, m);
        printf("second degree is float");
        return ERR_FLOAT_INP;
    }
    long long int **altmatr = create(m, n);
    if (altmatr == NULL)
    {
        freematr(matrb, p);
        freematr(matra, m);
        return ERR_NO_MEM;
    }
    if (st1 == 0)
    {
        matra = matrones(m, n, matra);
    }
    else
    {
        for (long long int i = 0; i < m; i++)
            for (long long int j = 0; j < n; j++)
                altmatr[i][j] = matra[i][j];
        for (long long int po = 1; po < st1; po++)
            matra = matrpow(m, n, &matra, altmatr);
    }
    if (st2 == 0)
    {
        matrb = matrones(p, q, matrb);
    }
    else
    {
        for (long long int i = 0; i < p; i++)
            for (long long int j = 0; j < q; j++)
                altmatr[i][j] = matrb[i][j];
        for (long long int po = 1; po < st2; po++)
            matrb = matrpow(p, q, &matrb, altmatr);
    }
    freematr(altmatr, m);
    matra = matrpow(m, m, &matra, matrb);
    output(m, n, matra);
    freematr(matra, m);
    freematr(matrb, p);
    return CORR_END;
}

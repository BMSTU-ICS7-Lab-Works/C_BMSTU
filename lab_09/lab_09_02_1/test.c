#include <stdio.h>
#include <stdlib.h>
#include "main.h"

void test_maxfinder()
{
    int err_cnt = 0;
    long long int **matra = create(3, 3);
    int maxij = 0;
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            matra[i][j] = i;
    maxij = maxfinder(3, 3, matra, 1);
    if (maxij != 2)
        err_cnt++;
    maxij = maxfinder(3, 3, matra, 0);
    if (maxij != 2)
        err_cnt++;
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            matra[i][j] = 1;
    maxij = maxfinder(3, 3, matra, 1);
    if (maxij != 2)
        err_cnt++;
    maxij = maxfinder(3, 3, matra, 0);
    if (maxij != 2)
        err_cnt++;
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
        {
            if ((j == 1 && i == 0) || (j == 1 && i == 2))
                matra[i][j] = 5;
            else
                matra[i][j] = 1;
        }
    maxij = maxfinder(3, 3, matra, 1);
    if (maxij != 2)
        err_cnt++;
    maxij = maxfinder(3, 3, matra, 0);
    if (maxij != 1)
        err_cnt++;
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            matra[i][j] = -i;
    maxij = maxfinder(3, 3, matra, 1);
    if (maxij != 0)
        err_cnt++;
    maxij = maxfinder(3, 3, matra, 0);
    if (maxij != 2)
        err_cnt++;
    if (err_cnt == 0)
        printf("test_maxfinder OK\n");
    else
    {
        printf("test_maxfinder ERROR\n");
    }
    freematr(matra, 3);
}

void test_del_rows()
{
    int err_cnt = 0;
    long long int **matra = create(3, 3);
    long long int m, n;
    m = 3;
    n = 3;
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            matra[i][j] = i + j;
    long long int maxij = maxfinder(m, n, matra, 1);
    del_rows(&m, n, &matra, maxij);
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            if (matra[i][j] != i + j)
                err_cnt++;
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
        {
            if (i == 0)
                matra[i][j] = 9;
            else
                matra[i][j] = 1;
        }
    maxij = maxfinder(m, n, matra, 1);
    del_rows(&m, n, &matra, maxij);
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            if (matra[i][j] != 1)
                err_cnt++;
    freematr(matra, m);
    matra = create(3, 3);
    m = 3;
    n = 3;
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            matra[i][j] = - i - 1;
    maxij = maxfinder(m, n, matra, 1);
    del_rows(&m, n, &matra, maxij);
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            if (matra[i][j] != -i - 2)
                err_cnt++;
    if (err_cnt == 0)
        printf("test_del_rows OK\n");
    else
    {
        printf("test_del_rows ERROR\n");
    }
    freematr(matra, m);
}

void test_transpose()
{
    int err_cnt = 0;
    long long int **matra = create(3, 3);
    long long int m, n;
    m = 3;
    n = 3;
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            matra[i][j] = i;
    matra = transpose(&m, &n, &matra);
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            if (matra[i][j] != j)
                err_cnt++;
    freematr(matra, m);
    matra = create(3, 2);
    m = 3;
    n = 2;
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            matra[i][j] = j;
    matra = transpose(&m, &n, &matra);
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            if (matra[i][j] != i)
                err_cnt++;
    freematr(matra, m);
    matra = create(2, 3);
    m = 2;
    n = 3;
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            matra[i][j] = j;
    matra = transpose(&m, &n, &matra);
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            if (matra[i][j] != i)
                err_cnt++;
    freematr(matra, m);
    if (err_cnt == 0)
        printf("test_transpose OK\n");
    else
    {
        printf("test_transpose ERROR\n");
    }
}

void test_srarifmcol()
{
    int err_cnt = 0;
    long long int **matra = create(3, 3);
    long long int res = 0;
    long long int m, n;
    m = 3;
    n = 3;
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            matra[i][j] = - i - 1;
    res = srarifmcol(matra, m, 2);
    if (res != -2)
        err_cnt++;
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
        {
            if (i == 1)
                matra[i][j] = 2;
            else
                matra[i][j] = -2;
        }
    res = srarifmcol(matra, m, 0);
    if (res != -1)
        err_cnt++;
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
        {
            if (i == 1)
                matra[i][j] = 5;
            else
                matra[i][j] = i;
        }
    res = srarifmcol(matra, m, 0);
    if (res != 2)
        err_cnt++;
    freematr(matra, m);
    if (err_cnt == 0)
        printf("test_srarifmcol OK\n");
    else
    {
        printf("test_srarifmcol ERROR\n");
    }
}

void test_minfinder()
{
    int err_cnt = 0;
    long long int **matra = create(3, 3);
    long long int res = 0;
    long long int m, n;
    m = 3;
    n = 3;
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            matra[i][j] = i + j;
    res = minfinder(0, n, matra);
    if (res != 0)
        err_cnt++;
    res = minfinder(2, n, matra);
    if (res != 2)
        err_cnt++;
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            matra[i][j] = - j - 1;
    res = minfinder(0, n, matra);
    if (res != -3)
        err_cnt++;
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            matra[i][j] = 0;
    res = minfinder(0, n, matra);
    if (res != 0)
        err_cnt++;
    freematr(matra, m);
    if (err_cnt == 0)
        printf("test_minfinder OK\n");
    else
    {
        printf("test_minfinder ERROR\n");
    }
}

void test_add_row()
{
    int err_cnt = 0;
    long long int **matra = create(3, 3);
    long long int m, n;
    long long int masmin[3] = { 0, 1, 2 };
    m = 3;
    n = 3;
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            matra[i][j] = i;
    add_row(&m, n, &matra, 0, masmin);
    if (matra[3][0] != 1 || matra[3][1] != 1 || matra[3][2] != 1)
        err_cnt++;
    add_row(&m, n, &matra, 1, masmin);
    if (matra[4][0] != masmin[0] || matra[4][1] != masmin[1] || matra[4][2] != masmin[2])
        err_cnt++;
    freematr(matra, m);
    matra = create(3, 3);
    long long int masmin1[3] = { -3, -3, -3 };
    m = 3;
    n = 3;
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            matra[i][j] = - j - 1;
    add_row(&m, n, &matra, 0, masmin1);
    if (matra[3][0] != -1 || matra[3][1] != -2 || matra[3][2] != -3)
        err_cnt++;
    add_row(&m, n, &matra, 1, masmin1);
    if (matra[4][0] != masmin1[0] || matra[4][1] != masmin1[1] || matra[4][2] != masmin1[2])
        err_cnt++;
    freematr(matra, m);
    if (err_cnt == 0)
        printf("test_add_row OK\n");
    else
    {
        printf("test_add_row ERROR\n");
    }
}
//matrpow i matrones ostalos'
void test_matrpow()
{
    long long int **altmatr = create(2, 2);
    int err_cnt = 0;
    long long int **matra = create(2, 2);
    long long int m, n;
    m = 2;
    n = 2;
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            matra[i][j] = i * m + j + 1;    
    for (long long int i = 0; i < m; i++)
        for (long long int j = 0; j < n; j++)
            altmatr[i][j] = matra[i][j];
    matra = matrpow(m, n, &matra, altmatr);
    if (matra[0][0] != 7 || matra[0][1] != 10 || matra[1][0] != 15 || matra[1][1] != 22)
        err_cnt++;
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            matra[i][j] = -(i * m + j + 1);
    for (long long int i = 0; i < m; i++)
        for (long long int j = 0; j < n; j++)
            altmatr[i][j] = matra[i][j];
    matra = matrpow(m, n, &matra, altmatr);
    if (matra[0][0] != 7 || matra[0][1] != 10 || matra[1][0] != 15 || matra[1][1] != 22)
        err_cnt++;
    freematr(matra, m);
    freematr(altmatr, m);
    if (err_cnt == 0)
        printf("test_matrpow OK\n");
    else
    {
        printf("test_matrpow ERROR\n");
    }
}

void test_matrones()
{
    int err_cnt = 0;
    long long int **matra = create(2, 2);
    long long int m, n;
    m = 2;
    n = 2;
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            matra[i][j] = i * m + j + 1;
    matra = matrones(m, n, matra);
    for (long long int i = 0; i < m; i++)
        for (long long int j = 0; j < n; j++)
        {
            if (i == j)
            {
                if (matra[i][j] != 1)
                    err_cnt++;
            }
            else
            {
                if (matra[i][j] != 0)
                    err_cnt++;
            }
        }
    freematr(matra, m);
    m = 3;
    n = 3;
    matra = create(m, m);
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            matra[i][j] = i * m + j + 1;
    matra = matrones(m, n, matra);
    for (long long int i = 0; i < m; i++)
        for (long long int j = 0; j < n; j++)
        {
            if (i == j)
            {
                if (matra[i][j] != 1)
                    err_cnt++;
            }
            else
            {
                if (matra[i][j] != 0)
                    err_cnt++;
            }
        }
    freematr(matra, m);
    if (err_cnt == 0)
        printf("test_matrones OK\n");
    else
    {
        printf("test_matrones ERROR\n");
    }
}

int main()
{
    test_maxfinder();
    test_del_rows();
    test_transpose();
    test_srarifmcol();
    test_minfinder();
    test_add_row();
    test_matrpow();
    test_matrones();
    return CORR_END;
}

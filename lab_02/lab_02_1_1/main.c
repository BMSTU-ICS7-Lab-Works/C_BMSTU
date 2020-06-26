#include <stdio.h>
int chast (int a, int d)
{
    int q;
    while (a >= d)
    {
      a -= d;
      q += 1;
    }
    return q;
}

int ost (int a, int d)
{
    int r;
    while (a >= d)
    {
      a -= d;
    }
    r = a;
    return r;
}

int main ()
{
    int q, r;
    int a = 0, d = 0;
    if ((scanf ("%d%d", &a, &d) != 2) || (a < 0) || (d <= 0))
    {
      printf ("incorrect data");
      return -1;
    }
    q = chast (a, d);
    r = ost (a, d);
    printf ("%d %d", q, r);
    return 0;
}

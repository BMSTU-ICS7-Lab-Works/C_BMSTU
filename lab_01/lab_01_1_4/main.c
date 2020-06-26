#include <stdio.h>

int main()
{
    int n, p, e;
    puts("vvedite kolvo kvartir");
    scanf("%d", &n);

    p = (n - 1) / (36) + 1;
    e = ((n - 1) / 4) % 9 + 1;

    printf("%d %d", p, e);

    return 0;
}

#include <stdio.h>

int main(void)
{
    float v1, t1, v2, t2, v3, t3;
    puts("Enter v and t of first and second water");
    scanf("%f %f %f %f", &v1, &t1, &v2, &t2);
    v3 = v1 + v2;
    t3 = (t1 * v1 + t2 * v2) / (v1 + v2);
    printf("new v = %.4f , t = %.4f", v3, t3);
    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include "matrix.h"

int main()
{
    int a[3][3] = {0};
    printf("Default matrix:\n");
    m_print(3, 3, a);
    m_unit(3, 3, a);
    printf("United matrix:\n");
    m_print(3, 3, a);
    printf("Random matrix:\n");
    m_randomfill(3, 3, a, 3, 5);
    m_print(3, 3, a);
    printf("Random matrix rotated 90%% from previous one:\n");
    m_rotate(3, 3, a, 90);
    m_print(3, 3, a);
    printf("Random matrix rotated 180%% from previous one:\n");
    m_rotate(3, 3, a, 180);
    m_print(3, 3, a);
    printf("Random matrix rotated 270%% from previous one:\n");
    m_rotate(3, 3, a, 270);
    m_print(3, 3, a);
    return 0;
}

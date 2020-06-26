#include <stdio.h>
#include <stdlib.h>
#include "windows.h"

//     DLL
typedef void (__cdecl *fn_unit_t)(int, int cols, int matrix[][cols]);
typedef void (__cdecl *fn_print_t)(int, int cols, int matrix[][cols]);
typedef void (__cdecl *fn_rotate_t)(int, int cols, int matrix[][cols], int);
typedef void (__cdecl *fn_randomfill_t)(int, int cols, int matrix[][cols], int, int);

int main()
{
	HMODULE hlib;
	fn_unit_t m_unit;
    fn_print_t m_print;
    fn_rotate_t m_rotate;
    fn_randomfill_t m_randomfill;
    int a[3][3] = {0};
	hlib = LoadLibrary("matrix.dll");
	if (!hlib)
    {
        printf("Cannot open library.\n");
		return -1;
    }   
    printf("Library is loaded at address %p.\n", (void*) hlib);
    
    m_unit = (fn_unit_t) GetProcAddress(hlib, "m_unit");
    if (!m_unit)
    {
        printf("Can not load function.\n");
        return -1;
    }
    printf("M_unit function is located at address %p.\n", (void*) m_unit);

    m_print = (fn_print_t) GetProcAddress(hlib, "m_print");
    if (!m_print)
    {
        printf("Can not load function.\n");
        return -1;
    }

    printf("M_print function is located at address %p.\n", (void*) m_print);

    m_rotate = (fn_rotate_t) GetProcAddress(hlib, "m_rotate");
    if (!m_rotate)
    {
        printf("Can not load function.\n");
        return -1;
    }

    printf("M_rotate function is located at address %p.\n", (void*) m_rotate);

	m_randomfill = (fn_randomfill_t) GetProcAddress(hlib, "m_randomfill");
    if (!m_randomfill)
    {
        printf("Can not load function.\n");
        return -1;
    }

    printf("M_randomfill function is located at address %p.\n", (void*) m_randomfill);
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

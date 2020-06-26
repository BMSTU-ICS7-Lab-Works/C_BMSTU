#ifndef MATRIX_H
#define MATRIX_H

#ifdef IL_EXPORTS
	#define IL_DLL __declspec(dllexport)
#else
	#define IL_DLL __declspec(dllimport)
#endif

#define IL_DECL __cdecl

#define CORR_END 0;
#define ERR_END -1;

IL_DLL void m_unit(int rows, int cols, int matrix[][cols]);
IL_DLL void m_print(int rows, int cols, int matrix[][cols]);
IL_DLL int m_rotate(int rows, int cols, int matrix[][cols], int angle);
IL_DLL int m_randomfill(int rows, int cols, int matrix[][cols], int left_border, int right_border);



#endif // MATRIX_H

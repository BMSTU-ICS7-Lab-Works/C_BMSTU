#ifndef MATRIX_H
#define MATRIX_H

#define CORR_END 0;
#define ERR_END -1;

void m_unit(int rows, int cols, int matrix[][cols]);
void m_print(int rows, int cols, int matrix[][cols]);
int m_rotate(int rows, int cols, int matrix[][cols], int angle);
int m_randomfill(int rows, int cols, int matrix[][cols], int left_border, int right_border);



#endif // MATRIX_H

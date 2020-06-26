#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "matrix.h"


IL_DLL void m_unit(int rows, int cols, int matrix[][cols])
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (i == j)
            {
                matrix[i][j] = 1;
            }
            else
                matrix[i][j] = 0;
        }
    }
}

IL_DLL void m_print(int rows, int cols, int matrix[][cols])
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

IL_DLL int m_randomfill(int rows, int cols, int matrix[][cols], int left_border, int right_border)
{
   srand(time(NULL));
   if (left_border > right_border)
   {
       return ERR_END;
   }
   else
   {
       for (int i = 0; i < rows; i++)
       {
           for (int j = 0; j < cols; j++)
           {
               matrix[i][j] = left_border + rand() % (right_border - left_border + 1);
           }
       }
       return CORR_END;
   }
}

IL_DLL int m_rotate(int rows, int cols, int matrix[][cols], int angle)
{
    if (angle % 90 == 0)
    {
        int tmp;
        if (angle % 360 == 90)
        {
            for (int i = 0; i < rows / 2; i++)
            {
                for (int j = 0; j < rows - 1 - i; j++)
                {
                    tmp = matrix[i][j];
                    matrix[i][j] = matrix[rows - j - 1][i];
                    matrix[rows - j - 1][i] = matrix[rows - i - 1][rows - j - 1];
                    matrix[rows - i - 1][rows - j - 1] = matrix[j][rows - i - 1];
                    matrix[j][rows - i - 1] = tmp;
                }
            }
        }
        else if (angle % 360 == 180)
        {
            for (int i = 0; i < rows / 2; i++)
            {
                for (int j = 0; j < rows - 1 - i; j++)
                {
                    tmp = matrix[i][j];
                    matrix[i][j] = matrix[rows - j - 1][i];
                    matrix[rows - j - 1][i] = matrix[rows - i - 1][rows - j - 1];
                    matrix[rows - i - 1][rows - j - 1] = matrix[j][rows - i - 1];
                    matrix[j][rows - i - 1] = tmp;
                }
            }
            for (int i = 0; i < rows / 2; i++)
            {
                for (int j = 0; j < rows - 1 - i; j++)
                {
                    tmp = matrix[i][j];
                    matrix[i][j] = matrix[rows - j - 1][i];
                    matrix[rows - j - 1][i] = matrix[rows - i - 1][rows - j - 1];
                    matrix[rows - i - 1][rows - j - 1] = matrix[j][rows - i - 1];
                    matrix[j][rows - i - 1] = tmp;
                }
            }
        }
        else if (angle % 360 == 270)
        {
            for (int i = 0; i < rows / 2; i++)
            {
                for (int j = 0; j < rows - 1 - i; j++)
                {
                    tmp = matrix[i][j];
                    matrix[i][j] = matrix[rows - j - 1][i];
                    matrix[rows - j - 1][i] = matrix[rows - i - 1][rows - j - 1];
                    matrix[rows - i - 1][rows - j - 1] = matrix[j][rows - i - 1];
                    matrix[j][rows - i - 1] = tmp;
                }
            }
            for (int i = 0; i < rows / 2; i++)
            {
                for (int j = 0; j < rows - 1 - i; j++)
                {
                    tmp = matrix[i][j];
                    matrix[i][j] = matrix[rows - j - 1][i];
                    matrix[rows - j - 1][i] = matrix[rows - i - 1][rows - j - 1];
                    matrix[rows - i - 1][rows - j - 1] = matrix[j][rows - i - 1];
                    matrix[j][rows - i - 1] = tmp;
                }
            }
            for (int i = 0; i < rows / 2; i++)
            {
                for (int j = 0; j < rows - 1 - i; j++)
                {
                    tmp = matrix[i][j];
                    matrix[i][j] = matrix[rows - j - 1][i];
                    matrix[rows - j - 1][i] = matrix[rows - i - 1][rows - j - 1];
                    matrix[rows - i - 1][rows - j - 1] = matrix[j][rows - i - 1];
                    matrix[j][rows - i - 1] = tmp;
                }
            }
        }
        return CORR_END;
    }
    else
    {
        return ERR_END;
    }
}

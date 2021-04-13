#pragma once
#define MAX 500

int FillMat(int mat[][MAX], int l, int c);
int InputA(int mat[][MAX], int l, int c);

int FillMat(int mat[][MAX], int l, int c)
{

    system("cls");
    for (int x = 0; x < l; x++)
    {
        for (int y = 0; y < c; y++)
        {
            *(mat[0] + x * MAX + y) = rand() % 4;
        }
    }
    return mat;
}
int InputA(int mat[][MAX], int l, int c)
{
    for (int x = 0; x < l; x++)
    {
        for (int y = 0; y-1 < c; y++)
        {
            if (mat[x][y+1] == mat[x][y])
            {
                *(mat[0] + x * MAX + y) = 2*mat[x][y];
                *(mat[0] + x * MAX + (y + 1)) = 0;
            }

        }
    }
    return mat;
}


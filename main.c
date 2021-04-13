#include <stdio.h>
#include <stdlib.h>
#include "MatFuncs.h"

int EmptyScreen(int mat[][MAX],int l,int c)
{

    system("cls");
    for (int x = 0; x < l; x++)
    {
        for (int y = 0; y < c; y++)
        {
           *(mat[0] + x *MAX + y) = 0;
            printf("%4d", mat[x][y]);
        }
        printf("\n");
    }
    return mat;
}

int UpdateScreen(int mat[][MAX], int l, int c)
{
    system("cls");
    for (int x = 0; x < l; x++)
    {
        for (int y = 0; y < c; y++)
        {
            printf("%4d", mat[x][y]);
        }
        printf("\n");
    }
    return mat;
}
char Input()
{
    int input;
    scanf_s(" %c", &input);
    return input;
}
void HandleInput(int mat[][MAX], int l, int c)
{
    while (1)
    {
        switch (Input())
        {
        default:
            break;
        case 'a':
            InputA(*mat, l, c);
            break;
        }
     UpdateScreen(*mat, l, c);
    }
}
int main()
{  
    int l = 4, c = 4;
    int mat[MAX][MAX];
    FillMat(*mat, l, c);
    UpdateScreen(*mat, l, c);
    HandleInput(*mat, l, c);

    return 0;
}

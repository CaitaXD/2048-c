#include <stdio.h>
#include <stdlib.h>
#include "MatFuncs.h"

/*
Nno momento usa-se o scanf como input
Creio que o comportamento da matriz esteje  correto mas e possivel que não
Para mover os numeros na matriz foi adaptado bublesort dentro de um laço for
Algumas direçõe presisaram de mais laços por causa da ordem de varredura
As funçoes de Input retornam a matriz
    (n sei se vale a mão de mudar o retorno para void e usar pointer?)
*/

int main() {
    int l = 4, c = 4;
    int mat[MAX][MAX];
    InitMat(mat, l, c);
    UpdateScreen(mat, l, c);
    HandleInput(mat, l, c);
    return 0;
}

int EmptyScreen(int mat[][MAX],int l,int c) {
    system("cls");
    for (int x = 0; x < l; x++)
    {
        for (int y = 0; y < c; y++)
        {
           *(mat[0] + x *MAX + y) = 0;
            printf("%7d", mat[x][y]);
        }
        printf("\n");
    }
    return mat;
}

int UpdateScreen(int mat[][MAX], int l, int c) {
    system("cls");
    for (int x = 0; x < l; x++) {
        for (int y = 0; y < c; y++) {
            printf("%7d", mat[x][y]);
        }
        printf("\n");
    }
    return mat;
}

char Input() {
    char c;
    scanf_s(" %c", &c);
    return c;
}

void HandleInput(int mat[][MAX], int l, int c) {
    while (1) {
        switch (Input())
        {
        default:
            break;
        case 'a':
            InputA(mat, l, c);
            break;
        case 'd':
            InputD(mat, l, c);
            break;
        case 'w':
            InputW(mat, l, c);
            break;
        case 's':
            InputS(mat, l, c);
            break;
        }
     UpdateScreen(mat, l, c);
    }
}

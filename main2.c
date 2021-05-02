#include <stdio.h>
#include <stdlib.h>
#include "MatFuncs.h"

int main() {
    game mat[MAX];
    InitMat(mat);
    UpdateScreen(mat);
    HandleInput(mat);
    return 0;
}

void EmptyScreen(game *mat) {
    system("cls");
    for (int x = 0; x < MAX; x++)
    {
        for (int y = 0; y < MAX; y++)
        {
           *(mat->tabuleiro[0] + x *MAX + y) = 0;
            printf("%7d", mat->tabuleiro[x][y]);
        }
        printf("\n");
    }
    return mat->tabuleiro;
}
void UpdateScreen(game *mat) {
    system("cls");
    for (int x = 0; x < MAX; x++) {
        for (int y = 0; y < MAX; y++) {
            printf("%7d", mat->tabuleiro[x][y]);
        }
        printf("\n");
    }
    return mat->tabuleiro;
}
char Input() {
    char c;
    scanf_s(" %c", &c);
    return c;
}
void HandleInput(game *mat) {
    while (1) {
        switch (Input())
        {
        default:
            break;
        case 'a':
            InputA(mat);
            break;
        case 'd':
            InputD(mat);
            break;
        case 'w':
            InputW(mat);
            break;
        case 's':
            InputS(mat);
            break;
        }
     UpdateScreen(mat);
    }
}

#include <stdio.h>
#include <stdlib.h>
#include "MatFuncs.h"
#include "StateMachine.h"
// N�o sei se era pra ta #include "conio.h" o VS ta pegando as fun��es sem 
int main() 
{
    int mat[MAX][MAX]; char nome[40];
    Game game = { 0 };
    game.backmoves = 1;
    StartState(&game);
    return 0;
}




#include <stdio.h>
#include <stdlib.h>
#include "MatFuncs.h"
#include "StateMachine.h"
int main() 
{
    int mat[MAX][MAX]; char nome[40];
    Game games[MAX];
    Game game = { mat, 0, nome };
    games[0] = game;
    StartState(game);
    return 0;
}




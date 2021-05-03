#include <stdio.h>
#include <stdlib.h>
#include "MatFuncs.h"
#include "StateMachine.h"
int main() 
{
    int mat[MAX][MAX]; char nome[40];
    Game game = { mat, 0, nome };
    StartState(&game);
    return 0;
}




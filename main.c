#include <stdio.h>
#include <stdlib.h>
#include "MatFuncs.h"
#include "StateMachine.h"

// Não sei se era pra ta #include "conio.h" o VS ta pegando as funções sem 
int main() 
{
    //Inicializa o jogo e chama a maquina de estados
    int mat[MAX][MAX];
    Game game = {0};
    game.moves = 0;
    game.backmoves = 1;
    StartState(&game);
    return 0;
}




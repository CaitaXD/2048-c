#include <stdio.h>
#include <stdlib.h>
#include "MatFuncs.h"
#include "StateMachine.h"

// N�o sei se era pra ta #include "conio.h" o VS ta pegando as fun��es sem 
int main() 
{
    //Inicializa o jogo e chama a maquina de estados
    int mat[MAX][MAX];
    Game game = {0};
    game.moves = 0;
    game.backmoves = 1;
    StartState(&game);
    return 0;
    //Inicializa os valores do struct jogo necessarios para come�ar a execu��o
    // Inicia a rotina StartState
}




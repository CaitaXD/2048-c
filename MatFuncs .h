#ifndef MAT_FUNCS
#define MAT_FUNCS
#include <stdio.h>
#include <stdlib.h>
#include<time.h>
#define TAM 40
#define LIM 10
#define MAX 4
typedef struct jogo {
    int tabuleiro[MAX][MAX], historyMat[MAX][MAX][MAX];
    int score, moves, backmoves;
    char nome[TAM];
}Game;
void InitMat (Game *mat);
void FillMat (Game *mat);
void InputW (Game *mat);
void InputA (Game *mat);
void InputS (Game *mat);
void InputD (Game *mat);
static void slide(Game* mat, int a, int b, int c);// agrupa os numeros para o lado selecionado
static void soma(Game* mat, int x, int y); // realiza a soma apos agrupamento
static void generate(Game* mat, int count); // gera o numero 2 ou 4 em uma posicao aleatoria
int CheckLegalMove(Game* game);
#endif

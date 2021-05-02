#ifndef MAT_FUNCS
#define MAT_FUNCS
#include <stdio.h>
#include <stdlib.h>
#include<time.h>
#define LIM 10
#define MAX 4

typedef struct jogo {
    int tabuleiro[MAX][MAX];
    int score;
    char nome[40];
}game;
void InitMat (game *mat);
void FillMat (game *mat);
void InputW (game *mat);
void InputA (game *mat);
void InputS (game *mat);
void InputD (game *mat);
void EmptyScreen(game *mat);
void UpdateScreen(game *mat);
void HandleInput(game *mat);
#endif

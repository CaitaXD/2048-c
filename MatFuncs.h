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
}Game;
void InitMat (Game *mat);
void FillMat (Game *mat);
void InputW (Game *mat);
void InputA (Game *mat);
void InputS (Game *mat);
void InputD (Game *mat);
void EmptyScreen(Game *mat);
void UpdateScreen(Game *mat);
void HandleInput(Game *mat);
#endif

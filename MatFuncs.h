#ifndef MAT_FUNCS
#define MAT_FUNCS
#include <stdio.h>
#include <stdlib.h>
#include<time.h>
#define LIM 10
#define MAX 4
int FillMat (int mat[][MAX], int a);
int InitMat (int mat[][MAX]);
int InputW (int mat[][MAX]);
int InputA (int mat[][MAX]);
int InputS (int mat[][MAX]);
int InputD (int mat[][MAX]);
int EmptyScreen(int mat[][MAX]);
void HandleInput(int mat[][MAX]);
#endif

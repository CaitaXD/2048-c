#ifndef MAT_FUNCS
#define MAT_FUNCS
#include <stdio.h>
#include <stdlib.h>
#include<time.h>
#define MAX 10
int FillMat (int mat[][MAX], int l, int c);
int InitMat (int mat[][MAX], int l, int c);
int InputW (int mat[][MAX], int l, int c);
int slideW (int mat[][MAX], int l, int c);
int InputA (int mat[][MAX], int l, int c);
int InputS (int mat[][MAX], int l, int c);
int slideS (int mat[][MAX], int l, int c);
int InputD (int mat[][MAX], int l, int c);
int EmptyScreen(int mat[][MAX],int l,int c);
void HandleInput(int mat[][MAX], int l, int c);
#endif

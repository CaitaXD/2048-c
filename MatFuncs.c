#include "MatFuncs.h"
static int slide (int mat[][MAX], int a, int b, int c);
static int soma(int mat[][MAX], int x, int y);
static int generate(int mat[][MAX], int count);

int InitMat(int mat[][MAX]) {
    int count = 2;
    system("cls");
    for (int i = 0; i < MAX; i++) {
        for (int j = 0; j < MAX; j++) {
            mat[i][j] = 0;
            }
        }
    generate (mat, count);
    return mat;
}

int FillMat(int mat[][MAX]) {
    int count = 1;
    system("cls");
    generate (mat, count);
    return mat;
}

int InputW(int mat[][MAX]) {
    slide(mat, 0, 1, 0);
    soma(mat, 0, 0);
    slide(mat, 0, 1, 0);
    FillMat(mat);
    return mat;
}

int InputS(int mat[][MAX]) {
    slide(mat, 1, 0, 0);
    soma(mat, 1, 0);
    slide(mat, 1, 0, 0);
    FillMat(mat);
    return mat;
}

int InputA(int mat[][MAX]) {
    slide(mat, 0, 1, 1);
    soma(mat, 0, 1);
    slide(mat, 0, 1, 1);
    FillMat(mat);
    return mat;
}

int InputD(int mat[][MAX]) {
    slide(mat, 1, 0, 1);
    soma(mat, 1, 1);
    slide(mat, 1, 0, 1);
    FillMat(mat);
    return mat;
}

static int generate (int mat[][MAX], int count) {
    srand(time(NULL));
    while (count != 0) {
        int x = rand() % 4, y = rand() % 4;
        int  sort = rand() % 100;
        if (sort > LIM && mat[x][y] == 0) {
            count--;
            mat[x][y] = 2;
            }
        else if (sort <= LIM && mat[x][y] == 0)
            {
                count--;
                mat[x][y] = 2;
            }
        }
    return mat;
}

static int slide (int mat[][MAX], int a, int b, int c) {
    for (int h = 0; h < MAX; h++) {
        for (int k = MAX-1; k > 0; k--) {
            for (int j = 0; j < k; j++) {
                if (c == 0) {
                    if (mat[j + a][h] == 0) {
                    mat[j + a][h] = mat[j + b][h];
                    mat[j + b][h] = 0;
                    }
                } else {
                    if (c == 1) {
                        if (mat[h][j + a] == 0) {
                            mat[h][j + a] = mat[h][j + b];
                            mat[h][j + b] = 0;
                        }
                    }
                }
            }
        }
    }
    return mat;
}

static int soma(int mat[][MAX], int x, int y) {
    if (x == 0) {
        for (int h = 0; h < MAX; h++) {
            for (int j = 0; j < MAX - 1; j++) {
                if (y == 0) {
                    if (mat[j + 1][h] == mat[j][h]) {
                        mat[j][h] = mat[j][h]*2;
                        mat[j + 1][h] = 0;
                    }
                } else {
                    if (y == 1) {
                        if (mat[h][j] == mat[h][j + 1]) {
                            mat[h][j] = mat[h][j]*2;
                            mat[h][j + 1] = 0;
                        }
                    }
                }
            }
        }
    } else {
        if (x == 1) {
            for (int h = MAX; h >= 0; h--) {
                for (int j = MAX - 1; j >= 0; j--) {
                    if (y == 0) {
                        if (mat[j + 1][h] == mat[j][h]) {
                            mat[j][h] = mat[j][h]*2;
                            mat[j + 1][h] = 0;
                        }
                    } else {
                        if (y == 1) {
                            if (mat[h][j] == mat[h][j + 1]) {
                                mat[h][j] = mat[h][j]*2;
                                mat[h][j + 1] = 0;
                            }
                        }
                    }
                }
            }
        }
    }
    return mat;
}

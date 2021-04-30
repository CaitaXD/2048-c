#include "MatFuncs.h"

static int slideW (int mat[][MAX], int l, int c);
static int slideS (int mat[][MAX], int l, int c);
static int generate(int mat[][MAX], int count);

int InitMat(int mat[][MAX], int l, int c) {
    int count = 2;
    system("cls");
    for (int i = 0; i < l; i++) {
        for (int j = 0; j < c; j++) {
            mat[i][j] = 0;
            }
        }
    generate (mat, count);
    return mat;
}

int FillMat(int mat[][MAX], int l, int c) {
    int count = 1;
    system("cls");
    generate (mat, count);
    return mat;
}
int InputD(int mat[][MAX], int l, int c) {
    //Slide the matrix
    int k, j, aux;
    for (int h = 0; h < l; h++) {
        for (k = l - 1; k > 0; k--) {
            for (j = 0; j < k; j++) {
                if (mat[h][j + 1] == 0) {
                    aux = mat[h][j];
                    mat[h][j] = mat[h][j + 1];
                    mat[h][j + 1] = aux;
                }
                if (mat[h][j] == mat[h][j + 1]) {
                    aux = 2*mat[h][j];
                    mat[h][j] =0;
                    mat[h][j + 1] = aux;
                }
            }
        }
    }
    FillMat(mat, l, c);
    return mat;
}
int InputA(int mat[][MAX], int l, int c) {
    int aux = 1;
    // Double The Equal Values
    for (int h = 0; h < l; h++) {
        for (int k = l - 1; k > 0; k--) {
            for (int j = 0; j < k; j++) {
                if (mat[h][j] == mat[h][j + 1]) {
                    aux = 2 * mat[h][j];
                    mat[h][j] = 0;
                    mat[h][j + 1] = aux;
                }
            }
        }
    }
    for (int h = 0; h < l; h++) {
        for (int k = l - 1; k > 0; k--) {
          for (int j = 0; j < k; j++) {
                if (mat[h][j] == 0){
                    aux = mat[h][j];
                    mat[h][j] = mat[h][j + 1];
                    mat[h][j + 1] = aux;
                }

            }
        }
    }
    FillMat(mat, l, c);
    return mat;
}

int InputW(int mat[][MAX], int l, int c) {
    int aux;
    slideW (mat, l, c);
        for (int h = 0; h < l; h++) {
            for (int k = l - 1; k > 0; k--) {
                for (int j = 0; j < k; j++) {
                    if (mat[j + 1][h] == mat[j][h]) {
                        aux = 2 * mat[j][h];
                        mat[j][h] = 0;
                        mat[j+1][h] = aux;
                }
            }
        }
    }
    slideW (mat, l, c);
    FillMat(mat, l, c);
    return mat;
}


int InputS(int mat[][MAX], int l, int c) {
    int aux;
    slideS (mat, l, c);
    for (int h = 0; h < l; h++) {
        for (int k = l - 1; k > 0; k--) {
            for (int j = 0; j < k; j++) {
                if (mat[j + 1][h] == mat[j][h]) {
                    aux = 2 * mat[j][h];
                    mat[j + 1][h] = 0;
                    mat[j][h] = aux;
                }
            }
        }
    }
    slideS (mat, l, c);
    FillMat(mat, l, c);
    return mat;
}

static int slideS (int mat[][MAX], int l, int c) {
    int aux;
    for (int h = 0; h < l; h++) {
        for (int k = l - 1; k > 0; k--) {
            for (int j = 0; j < k; j++) {
                if (mat[j + 1][h] == 0) {
                    aux = mat[j][h];
                    mat[j][h] = mat[j + 1][h];
                    mat[j + 1][h] = aux;
                }
            }
        }
    }
    return mat;
}

static int slideW (int mat[][MAX], int l, int c) {
    int aux;
    for (int h = 0; h < l; h++) {
        for (int k = l - 1; k > 0; k--) {
            for (int j = 0; j < k; j++) {
                if (mat[j][h] == 0) {
                    aux = mat[j+1][h];
                    mat[j+1][h] = mat[j][h];
                    mat[j][h] = aux;
                }
            }
        }
    }
    return mat;
}

static int generate (int mat[][MAX], int count) {
    srand(time(NULL));
    while (count != 0) {
        int x = rand() % 4, y = rand() % 4;
        int  sort = rand() % 100;
        if (sort > MAX && mat[x][y] == 0) {
            count--;
            mat[x][y] = 2;
            }
        else if (sort <= MAX && mat[x][y] == 0)
            {
                count--;
                mat[x][y] = 2;
            }
        }
    return mat;
}

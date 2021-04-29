#include "MatFuncs.h"

int InitMat(int mat[][MAX], int l, int c) {
    int count = 2;
    system("cls");
    srand(time(NULL));
    int  sort = rand() % 100, x = rand() % 4, y = rand() % 4;
    for (int i = 0; i <3; i++)
    {
        if (sort > MAX && count > 0) {
            count--;
            mat[x][y] = 2;
        }
        else {
        if (sort <= MAX && count > 0) {
            count--;
            mat[x][y] = 2;
            }
        }
        for (int i = 0; i < l; i++) {
        for (int j = 0; j < c; j++) {
            if (mat[i][j] != 2 && mat[i][j] != 4) {
            mat[i][j] = 0;
                }
            }
        }
        sort = rand() % 100, x = rand() % 4, y = rand() % 4;
    }
    return mat;
}

int FillMat(int mat[][MAX], int l, int c) {
    int count = 1;
    system("cls");
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

int slideS (int mat[][MAX], int l, int c) {
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

int slideW (int mat[][MAX], int l, int c) {
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
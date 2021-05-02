#include "MatFuncs.h"
static void slide (game *mat, int a, int b, int c);// agrupa os numeros para o lado selecionado
static void soma(game *mat, int x, int y); // realiza a soma apos agrupamento
static void generate(game *mat, int count); // gera o numero 2 ou 4 em uma posicao aleatoria
static void writefile (game *mat); //escreve arquivo
static void readfile (game *mat); //le arquivo

void InitMat(game *mat) { // inicializa o jogo
    int count = 2;
    system("cls");
    for (int i = 0; i < MAX; i++) {
        for (int j = 0; j < MAX; j++) {
            mat->tabuleiro[i][j] = 0;
            }
        }
    generate (mat, count);
}

void FillMat(game *mat) { // gera o numero 2 ou 4 apos um movimento
    int count = 1;
    system("cls");
    generate (mat, count);
}



void InputW(game *mat) { // movimento para cima
    slide(mat, 0, 1, 0);
    soma(mat, 0, 0);
    slide(mat, 0, 1, 0);
    FillMat(mat);
}

void InputS(game *mat) { // movimento para baixo
    slide(mat, 1, 0, 0);
    soma(mat, 1, 0);
    slide(mat, 1, 0, 0);
    FillMat(mat);
}

void InputA(game *mat) { // movimento para esquerda
    slide(mat, 0, 1, 1);
    soma(mat, 0, 1);
    slide(mat, 0, 1, 1);
    FillMat(mat);
}

void InputD(game *mat) { // movimento para direita
    slide(mat, 1, 0, 1);
    soma(mat, 1, 1);
    slide(mat, 1, 0, 1);
    FillMat(mat);
}

static void generate (game *mat, int count) {
    srand(time(NULL)); // comando utilizado para garantir q a semente seja sempre aleatoria
    while (count != 0) {
        int x = rand() % 4, y = rand() % 4; // gera um numero aleatorio entre 0 e 3
        int  sort = rand() % 100; // gera um numero aleatorio entre 0 e 99

        // a logica abaixo garante que o numero 4 tenha apenas 10% de chances de aparecer. LIM = 10.
        if (sort > LIM && mat->tabuleiro[x][y] == 0) {
            count--;
            mat->tabuleiro[x][y] = 2;
            }
            else {
                if (sort < LIM && mat->tabuleiro[x][y] == 0) {
                    count--;
                    mat->tabuleiro[x][y] = 4;
                }
            }
        }
}

static void slide (game *mat, int a, int b, int c) {
    for (int h = 0; h < MAX; h++) {
        for (int k = MAX-1; k > 0; k--) {
            for (int j = 0; j < k; j++) {
                if (c == 0) { //agrupa para os movimentos W e S (para W a = 0, b = 1 / para S a = 1, b = 0)
                    if (mat->tabuleiro[j + a][h] == 0) {
                    mat->tabuleiro[j + a][h] = mat->tabuleiro[j + b][h];
                    mat->tabuleiro[j + b][h] = 0;
                    }
                } else {
                    if (c == 1) { // agrupa para os movimentos A e D (para A a = 0, b = 1 / para D a = 1, b = 0)
                        if (mat->tabuleiro[h][j + a] == 0) {
                            mat->tabuleiro[h][j + a] = mat->tabuleiro[h][j + b];
                            mat->tabuleiro[h][j + b] = 0;
                        }
                    }
                }
            }
        }
    }
}

static void soma(game *mat, int x, int y) {
    if (x == 0) {
        for (int h = 0; h < MAX; h++) {
            for (int j = 0; j < MAX - 1; j++) {
                if (y == 0) { // soma para W
                    if (mat->tabuleiro[j][h] == mat->tabuleiro[j + 1][h]) {
                        mat->tabuleiro[j][h] = mat->tabuleiro[j][h]*2;
                        mat->tabuleiro[j + 1][h] = 0;
                    }
                } else {
                    if (y == 1) { // soma para A
                        if (mat->tabuleiro[h][j] == mat->tabuleiro[h][j + 1]) {
                            mat->tabuleiro[h][j] = mat->tabuleiro[h][j]*2;
                            mat->tabuleiro[h][j + 1] = 0;
                        }
                    }
                }
            }
        }
    } else {
        if (x == 1) {
            for (int h = MAX - 1; h >= 0; h--) {
                for (int j = MAX - 1; j >= 0; j--) {
                    if (y == 0) { // soma para S
                        if (mat->tabuleiro[j + 1][h] == mat->tabuleiro[j][h]) {
                            mat->tabuleiro[j + 1][h] = mat->tabuleiro[j][h]*2;
                            mat->tabuleiro[j][h] = 0;
                        }
                    } else {
                        if (y == 1) { // soma para D
                            if (mat->tabuleiro[h][j + 1] == mat->tabuleiro[h][j]) {
                                mat->tabuleiro[h][j + 1] = mat->tabuleiro[h][j]*2;
                                mat->tabuleiro[h][j] = 0;
                            }
                        }
                    }
                }
            }
        }
    }
}

static void writefile (game *mat) {
    FILE *arq = fopen("backup.dat", "w");
    if (arq != NULL) {
            fwrite(&mat, sizeof(game), 1, arq);
            fclose(arq);
        } else {
            printf("Problemas na escrita do arquivo\n");
        }
}

static void readfile (game *mat) {
    FILE *arq = fopen("backup.dat", "rb");
    if (arq != NULL) {
            fread(&mat, sizeof(game), 1, arq);
            fclose(arq);
        } else {
            printf("Problemas na leitura do arquivo\n");
        }

}

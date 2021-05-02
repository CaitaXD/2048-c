#include "MatFuncs.h"
static int slide (int mat[][MAX], int a, int b, int c);// agrupa os numeros para o lado selecionado
static int soma(int mat[][MAX], int x, int y); // realiza a soma apos agrupamento
static int generate(int mat[][MAX], int count); // gera o numero 2 ou 4 em uma posicao aleatoria
static void writefile (int item[][MAX], int tam); //escreve matriz auxiliar de verificacao de tentativas em arquivo
static void readfile (int *item[][MAX], int tam); //le arquivo para comparar matriz auxiliar com matriz do jogo

int InitMat(int mat[][MAX]) { // inicializa o jogo
    int count = 2;
    system("cls");
    for (int i = 0; i < MAX; i++) {
        for (int j = 0; j < MAX; j++) {
            mat[i][j] = 0;
            }
        }
    generate (mat, count);
    FillMat(mat, 0);
    return mat;
}

int FillMat(int mat[][MAX], int a) { // verifica jogadas e gera o numero 2 ou 4 apos um movimento
    int count = 1, aux[MAX][MAX], verif = 0, tam = MAX*MAX;
    if (a == 0) {
        for (int x = 0; x < MAX; x++) {
            for (int y = 0; y < MAX; y++) {
                aux[x][y] = 0;
            }
        }
        writefile(aux, tam);
    } else {
        if (a == 1) {
            readfile (&aux, tam);
            for (int x = 0; x < MAX; x++) {
                for (int y = 0; y < MAX; y++) {
                    if (aux[x][y] == mat[x][y]) {
                        verif++;
                        printf("%d", verif);
                    }
                }
            }
            if (verif < 16) {
                for (int x = 0; x < MAX; x++) {
                    for (int y = 0; y < MAX; y++) {
                        aux[x][y] = mat[x][y];
                    }
                }
                writefile (aux, tam);
                system("cls");
                generate (mat, count);
            } else {
                printf("Não eh possivel andar para esta direcao.");
            }
        return mat;
        }
    }
}



int InputW(int mat[][MAX]) { // movimento para cima
    slide(mat, 0, 1, 0);
    soma(mat, 0, 0);
    slide(mat, 0, 1, 0);
    FillMat(mat, 1);
    return mat;
}

int InputS(int mat[][MAX]) { // movimento para baixo
    slide(mat, 1, 0, 0);
    soma(mat, 1, 0);
    slide(mat, 1, 0, 0);
    FillMat(mat, 1);
    return mat;
}

int InputA(int mat[][MAX]) { // movimento para esquerda
    slide(mat, 0, 1, 1);
    soma(mat, 0, 1);
    slide(mat, 0, 1, 1);
    FillMat(mat, 1);
    return mat;
}

int InputD(int mat[][MAX]) { // movimento para direita
    slide(mat, 1, 0, 1);
    soma(mat, 1, 1);
    slide(mat, 1, 0, 1);
    FillMat(mat, 1);
    return mat;
}

static int generate (int mat[][MAX], int count) {
    srand(time(NULL)); // comando utilizado para garantir q a semente seja sempre aleatoria
    while (count != 0) {
        int x = rand() % 4, y = rand() % 4; // gera um numero aleatorio entre 0 e 3
        int  sort = rand() % 100; // gera um numero aleatorio entre 0 e 99

        // a logica abaixo garante que o numero 4 tenha apenas 10% de chances de aparecer. LIM = 10.
        if (sort > LIM && mat[x][y] == 0) {
            count--;
            mat[x][y] = 2;
            }
            else {
                if (sort < LIM && mat[x][y] == 0) {
                    count--;
                    mat[x][y] = 4;
                }
            }
        }
    return mat;
}

static int slide (int mat[][MAX], int a, int b, int c) {
    for (int h = 0; h < MAX; h++) {
        for (int k = MAX-1; k > 0; k--) {
            for (int j = 0; j < k; j++) {
                if (c == 0) { //agrupa para os movimentos W e S (para W a = 0, b = 1 / para S a = 1, b = 0)
                    if (mat[j + a][h] == 0) {
                    mat[j + a][h] = mat[j + b][h];
                    mat[j + b][h] = 0;
                    }
                } else {
                    if (c == 1) { // agrupa para os movimentos A e D (para A a = 0, b = 1 / para D a = 1, b = 0)
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
                if (y == 0) { // soma para W
                    if (mat[j][h] == mat[j + 1][h]) {
                        mat[j][h] = mat[j][h]*2;
                        mat[j + 1][h] = 0;
                    }
                } else {
                    if (y == 1) { // soma para A
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
            for (int h = MAX - 1; h >= 0; h--) {
                for (int j = MAX - 1; j >= 0; j--) {
                    if (y == 0) { // soma para S
                        if (mat[j + 1][h] == mat[j][h]) {
                            mat[j + 1][h] = mat[j][h]*2;
                            mat[j][h] = 0;
                        }
                    } else {
                        if (y == 1) { // soma para D
                            if (mat[h][j + 1] == mat[h][j]) {
                                mat[h][j + 1] = mat[h][j]*2;
                                mat[h][j] = 0;
                            }
                        }
                    }
                }
            }
        }
    }
    return mat;
}

static void writefile (int item[][MAX], int tam) {
    FILE *arq = fopen("backup.dat", "w");
    if (arq != NULL) {
            fwrite(item, sizeof(item), tam, arq);
            fclose(arq);
        } else {
            printf("Problemas na escrita do arquivo\n");
        }
}

static void readfile (int *item[][MAX], int tam) {
    FILE *arq = fopen("backup.dat", "rb");
    if (arq != NULL) {
            int i = fread(item, sizeof(item), tam, arq);
            fclose(arq);
        } else {
            printf("Problemas na leitura do arquivo\n");
        }
}

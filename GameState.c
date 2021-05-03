#include "StateMachine.h"
void GameState(Game* game)
{
    GameStateStart(game);
    GameStateUpdate(game);
}
int GameStateInputHandler(Game *game, int *count)
{
    switch (Input())
     {
        default:
        break;
        case 'a':
            InputA(game);
            break;
        case 'd':
            InputD(game);
            break;
        case 'w':
            InputW(game);
            break;
        case 's':
            InputS(game);
            break;
        case 'q':
            clrscr();
            saveGame(game,5);
            return 0;
            break;
        case 'r':
            InputR(game,count);
            break;
        }
    PrintScore(game);
    PrintMat(game->tabuleiro, 4, 1, 1);
}
void GameStateUpdate(Game *game)
{
    int check = 1;
    int count = 2;
    while (check)
    {
       saveMove(game, &count);
       check = GameStateInputHandler(game, &count);
    }
}
void GameStateStart(Game *game)
{
    clrscr();
    InitMat(game);
    PrintMat(game->tabuleiro, 4, 1, 1);
    textbackground(BLACK);
    textcolor(WHITE);
    PrintScore(game);

}
void saveGame(Game* mat) {
    Game savedGames[MAX];
    int slot = 0;
    textbackground(BLACK);
    textcolor(WHITE);
    cputsxy(1,1,"Insira o nome do jogador: ");
    char nome[40];
    fflush(stdin);
    fgets(nome, 40, stdin);
    cputsxy(1, 5, "Insira o numero do slot: ");
    scanf_s(" %d%*c",&slot);
    nome[strlen(nome) - 1] = '\0';
    mat->nome[39] = nome;
    FILE* arq;
    fopen_s(&arq, "backup.dat", "ab+");
    if (arq != NULL) {
        fseek(arq, slot*sizeof(Game), SEEK_SET);
        fwrite(mat, sizeof(Game), 1, arq);
        fclose(arq);
    }
    else {
        textbackground(BLACK);
        textcolor(RED);
        cputsxy(1, 1, "Error");
        return;
    }
    clrscr();
}
void InputR(Game* mat, int* count) {
    if (mat->backmoves > 0) {
        mat->moves--;
        mat->backmoves--;
        if (*count > 0) {
            for (int x = 0; x < MAX; x++) {
                for (int y = 0; y < MAX; y++) {
                    mat->tabuleiro[x][y] = mat->goback[*count - 1][x][y];
                }
            }
        }
        else {
            for (int x = 0; x < MAX; x++) {
                for (int y = 0; y < MAX; y++) {
                    mat->tabuleiro[x][y] = mat->goback[*count + MAX - 1];
                }
            }
        }
        *count--;
    }
}
void saveMove(Game* mat, int* count) {
    if (mat->backmoves > 0) {
        mat->moves++;
        if (*count < 0) {
            *count = *count + 1;
        }
        for (int x = 0; x < MAX; x++) {
            for (int y = 0; y < MAX; y++) {
                mat->goback[*count][x][y] = mat->tabuleiro[x][y];
            }
        }
        count++;
        if (count == MAX) {
            count = 0;
        }
    }
}
void PrintScore(Game* game)
{
    textbackground(BLACK);
    textcolor(WHITE);
    int score = game->score;
    int length = snprintf(NULL, 0, "%d", score);
    char* str = malloc(length + 1);
    snprintf(str, length + 1, "%d", score);
    cputsxy(25, 1, "Socre:");
    cputsxy(32, 1, str);
}
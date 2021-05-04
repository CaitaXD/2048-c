#include "StateMachine.h"
void GameState(Game* game)
{
    GameStateStart(game);
    for (int z = 0; z < 2; z++)
    {
        for (int x = 0; x < MAX; x++)
        {
            for (int y = 0; y < MAX; y++)
            {
                game->historyMat[z][x][y] = game->tabuleiro[x][y];
            }
        }
    }
    GameStateUpdate(game);
}
int GameStateInputHandler(Game *game, int *count)
{
    switch (Input())
     {
        default:
        break;
        case 'a':
            SavePrevius(game, count);
            InputA(game);
            game->backmoves = 1;
            SaveAtual(game);
            break;
        case 'd':
            SavePrevius(game, count);
            InputD(game);
            game->backmoves = 1;
            SaveAtual(game);
            break;
        case 'w':
            SavePrevius(game, count);
            InputW(game);
            game->backmoves = 1;
            SaveAtual(game);
            break;
        case 's':
            SavePrevius(game, count);
            InputS(game);
            game->backmoves = 1;
            SaveAtual(game);
            break;
        case 'q':
            clrscr();
            saveGame(game,5);
            return 0;
            break;
        case 'e':
                return 0;
                break;
        case 'r':
            InputR(game,count);
            SaveAtual(game);
            break;
        }
    PrintGameInfo(game);
    PrintMat(game->tabuleiro, 4, 1, 1);
}
void GameStateUpdate(Game *game)
{
    int check = 1;
    int count = 0;
    while (check)
    {
       check = GameStateInputHandler(game, &count);
    }
}
void GameStateStart(Game *game)
{
    clrscr();
    game->moves = 0;
    InitMat(game);
    PrintMat(game->tabuleiro, 4, 1, 1);
    textbackground(BLACK);
    textcolor(WHITE);
    PrintGameInfo(game);
    cputsxy(25, 5, "W,A,S,D: Slide");
    cputsxy(25, 10, "Q: Save Game E: Back to Menu");

}
void saveGame(Game* mat) {
    Game savedGames[MAX];
    int slot = 0;
    textbackground(BLACK);
    textcolor(WHITE);
    cputsxy(1,1,"Insira o nome do jogador: ");
    char nome[40];
    fgets(nome, 40, stdin);
    cputsxy(1, 5, "Insira o numero do slot: ");
    scanf_s(" %d%*c",&slot);
    nome[strlen(nome) - 1] = '\0';
    strcpy_s(mat->nome,40,nome);
    FILE* arq;
    fopen_s(&arq, "backup.dat", "rb+");
    if (arq != NULL) {
        fseek(arq, slot*sizeof(Game), SEEK_SET);
        fwrite(mat, sizeof(Game), 1, arq);
        fclose(arq);
    }
    else {
        fopen_s(&arq, "backup.dat", "wb");
        fseek(arq, slot * sizeof(Game), SEEK_SET);
        fwrite(mat, sizeof(Game), 1, arq);
        fclose(arq);
        return;
    }
    clrscr();
}
void InputR(Game* mat, int* count) 
{
    if(mat->moves > 0 && mat->backmoves>0)
    {
        mat->moves--;
        mat->backmoves--;
        for (int x = 0; x < MAX; x++) {
            for (int y = 0; y < MAX; y++) {
                mat->tabuleiro[x][y] = mat->historyMat[1][x][y];
                mat->historyMat[2][x][y] = mat->historyMat[3][x][y];
                mat->historyMat[1][x][y] = mat->historyMat[2][x][y];
            }
        }
    }
}
void SavePrevius(Game* mat, int *index)
{
    for (int x = 0; x < MAX; x++) {
        for (int y = 0; y < MAX; y++) {
            mat->historyMat[3][x][y] = mat->historyMat[2][x][y];
            mat->historyMat[2][x][y] = mat->historyMat[1][x][y];
            mat->historyMat[1][x][y] =  mat->tabuleiro[x][y];

        }
    }
}
void SaveAtual(Game* mat)
{
    for (int x = 0; x < MAX; x++) {
        for (int y = 0; y < MAX; y++) {
            mat->historyMat[0][x][y] = mat->tabuleiro[x][y];
        }
    }
}
void PrintGameInfo(Game* game)
{
    textbackground(BLACK);
    textcolor(WHITE);
    int score = game->score;
    int length = snprintf(NULL, 0, "%d", score);
    char* str = malloc(length + 1);
    snprintf(str, length + 1, "%d", score);
    cputsxy(25, 1, "Socre:");
    cputsxy(32, 1, str);
    int currentMoves = game->moves;
    length = snprintf(NULL, 0, "%d", currentMoves);
    str = malloc(length + 1);
    snprintf(str, length + 1, "%d", currentMoves);
    cputsxy(50, 1, str);
    cputsxy(40, 1, "Moves: ");
}

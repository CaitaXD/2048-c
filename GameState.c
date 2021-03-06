#include "StateMachine.h"
//Estado de jogo
void GameState(Game* game)
{
    //Rotina do Estado de jogo
    GameStateStart(game);
    //Preenche o historico de jogadas
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
    //Ouve o Teclado e executa uma rotina baseada na tecla apertada
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
    victoryCondition(game);
}
void GameStateUpdate(Game *game)
{
    //Rotina de repeti??o do estado
    int check = 1;
    //check valor responsavel por fechar o loop
    int count = 0;
    while (check)
    {
       check = GameStateInputHandler(game, &count);
    }
}
void GameStateStart(Game *game)
{
    //Rotina Executada no inicio do estado de jogo
    //clrscr(); limpa a tela
    clrscr();
    game->moves = 0;
    InitMat(game);
    PrintMat(game->tabuleiro, 4, 1, 1);
    textbackground(BLACK);
    textcolor(WHITE);
    PrintGameInfo(game);
    //cputsxy escreve na tela
    cputsxy(25, 5, "W,A,S,D: Slide");
    cputsxy(25, 10, "Q: Save Game E: Back to Menu R: TO Go Back 1 move");

}
void saveGame(Game* mat) {
    Game savedGames[MAX];
    FILE* arq;
    fopen_s(&arq, "backup.dat", "rb+");
    if(arq == NULL)
    {
        fopen_s(&arq, "backup.dat", "w");
    }
    fseek(arq, 0L, SEEK_END);
    int fileSize = ftell(arq);
    int slot = 0;
    textbackground(BLACK);
    textcolor(WHITE);
    cputsxy(1,1,"Insira o nome do jogador: ");
    char nome[40];
    fgets(nome, 40, stdin);
    fflush(stdin);
    int slots = (fileSize / sizeof(Game)-1);
    if (slots == -1) slots = 0;
    int length = snprintf(NULL, 0, "%d", slots);
    char* str = malloc(length + 1);
    snprintf(str, length + 1, "%d", slots);

    fseek(arq, 0L, SEEK_SET);
    do {
        clrscr();
        textbackground(BLACK);
        textcolor(WHITE);
        cputsxy(43, 5, str);
        cputsxy(45, 5, "Slots Salvos Subscreva ou salve no proximo slot");
        cputsxy(1, 5, "Insira o numero do slot: ");
        scanf_s(" %d%*c", &slot);
    }while(slot == 0 || slot -1> slots || slot > 20);
    nome[strlen(nome) - 1] = '\0';
    strcpy_s(mat->nome,40,nome);

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
            }
        }
    }
}
void SavePrevius(Game* mat, int *index)
{
    for (int x = 0; x < MAX; x++) {
        for (int y = 0; y < MAX; y++) {
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
    cputsxy(25, 1, "Score:");
    cputsxy(32, 1, str);
    int currentMoves = game->moves;
    length = snprintf(NULL, 0, "%d", currentMoves);
    str = malloc(length + 1);
    snprintf(str, length + 1, "%d", currentMoves);
    cputsxy(50, 1, str);
    cputsxy(40, 1, "Moves: ");
}
void victoryCondition(Game* game)
{
    for (int x = 0; x < MAX; x++)
    {
        for (int y = 0; y < MAX; y++)
        {
            if (game->tabuleiro[x][y] == 2048)
            {
                do {} while (Input() == NULL);
                clrscr();
                saveGame(game);
            }
        }
    }

    for (int x = 0; x < MAX; x++)
    {
        for (int y = 0; y < MAX; y++)
        {
            if (game->tabuleiro[x][y] == 0)
            {
                return;
            }
        }
    }
    textbackground(BLACK);
    textcolor(WHITE);
    clrscr();
    cputsxy(1, 1, "Game Over Q to Save Score");
    do {} while (Input() == NULL);
    clrscr();
    saveGame(game);
}

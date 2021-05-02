#include "StateMachine.h"
int GameStateInputHandler(Game *game)
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
            return 0;
            break;
        }
    PrintMat(game->tabuleiro, 4, 1, 1);
}
void GameStateUpdate(Game *game)
{
    int check = 1;
    while (check)
    {
       check = GameStateInputHandler(game);
    }
}
void GameStateStart(Game *game)
{
    clrscr();
    InitMat(game);
    PrintMat(game->tabuleiro, 4, 1, 1);
}

void GameState(Game *game)
{
    GameStateStart(game);
    GameStateUpdate(game);
}

#include "StateMachine.h"
void GameStateInputHandler(int mat[MAX][MAX])
{
        switch (Input())
        {
        default:
            break;
        case 'a':
            PrintMat(InputA(mat), 4, 1, 1);
            break;
        case 'd':
            PrintMat(InputD(mat), 4, 1, 1);
            break;
        case 'w':
            PrintMat(InputW(mat), 4, 1, 1);
            break;
        case 's':
            PrintMat(InputS(mat), 4, 1, 1);
            break;
        }
}
void GameStateUpdate(int mat[MAX][MAX])
{
    while (1)
    {
        GameStateInputHandler(mat);
    }
}
void GameStateStart(int mat[MAX][MAX])
{
    InitMat(mat);
    PrintMat(mat, 4, 1, 1);
}

void GameState(int mat[MAX][MAX])
{
    GameStateStart(mat);
    GameStateUpdate(mat);
}

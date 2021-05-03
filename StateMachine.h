#define MAX 4
#include "MatFuncs.h"
#include <string.h>
typedef enum
{
	BLACK, /**< black color */
	BLUE, /**< blue color */
	GREEN, /**< green color */
	CYAN, /**< cyan color */
	RED, /**< red color */
	MAGENTA, /**< magenta color */
	BROWN, /**< brown color */
	LIGHTGRAY, /**< light gray color */
	DARKGRAY, /**< dark gray color */
	LIGHTBLUE, /**< light blue color */
	LIGHTGREEN, /**< light green color */
	LIGHTCYAN, /**< light cyan color */
	LIGHTRED, /**< light red color */
	LIGHTMAGENTA, /**< light magenta color */
	YELLOW, /**< yellow color */
	WHITE /**< white color */
} COLORS;
void GameStateUpdate(Game* game);
void GameStateStart(Game* game);
char Input();
void PrintScore(Game* game);
void GameState(Game *game);
static void writefile(Game* mat); //escreve arquivo
static void readfile(Game* mat); //le arquivo
void recoveryGame(Game* mat, Game* savedGames[LIM], int n);
void saveGame(Game* mat, int n);
Game loadGame();
void InputR(Game* mat, int* count);
void saveMove(Game* mat, int* count);



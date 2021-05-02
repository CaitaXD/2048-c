#define MAX 4
#include "MatFuncs.h"
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

char Input();
void GameState(Game *game);




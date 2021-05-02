#include "Tela.h"
void PrintaCelula(int posx, int posy, int value)
{
	switch (value)
	{
	default:
		textbackground(CYAN);
		textcolor(BLACK);
		cputsxy(posx, posy, "|   |");		posy++;
		cputsxy(posx, posy, "|   |");		posy++;
		cputsxy(posx, posy, "|   |");
		textbackground(BLACK);
		break;
	case 2:
		textbackground(WHITE);
		textcolor(BLACK);
		cputsxy(posx, posy, "|   |");		posy++;
		cputsxy(posx, posy, "| 2 |");		posy++;
		cputsxy(posx, posy, "|   |");
		textbackground(BLACK);
		break;
	case 4:
		textbackground(RED);
		textcolor(BLACK);
		cputsxy(posx, posy, "|   |");		posy++;
		cputsxy(posx, posy, "| 4 |");		posy++;
		cputsxy(posx, posy, "|   |");
		textbackground(BLACK);
		break;
	case 8:
		textbackground(LIGHTMAGENTA);
		textcolor(BLACK);
		cputsxy(posx, posy, "|   |");		posy++;
		cputsxy(posx, posy, "| 8 |");		posy++;
		cputsxy(posx, posy, "|   |");
		textbackground(BLACK);
		break;
	case 16:
		textbackground(LIGHTRED);
		textcolor(BLACK);
		cputsxy(posx, posy, "|   |");		posy++;
		cputsxy(posx, posy, "|1 6|");		posy++;
		cputsxy(posx, posy, "|   |");
		textbackground(BLACK);
		break;
	case 32:
		textbackground(LIGHTCYAN);
		textcolor(BLACK);
		cputsxy(posx, posy, "|   |");		posy++;
		cputsxy(posx, posy, "|3 2|");		posy++;
		cputsxy(posx, posy, "|   |");
		textbackground(BLACK);
		break;
	case 64:
		textbackground(BROWN);
		textcolor(BLACK);
		cputsxy(posx, posy, "|   |");		posy++;
		cputsxy(posx, posy, "|6 4|");		posy++;
		cputsxy(posx, posy, "|   |");
		textbackground(BLACK);
		break;
	case 128:
		textbackground(BLUE);
		textcolor(BLACK);
		cputsxy(posx, posy, "|   |");		posy++;
		cputsxy(posx, posy, "|128|");		posy++;
		cputsxy(posx, posy, "|   |");
		textbackground(BLACK);
		break;
	case 256:
		textbackground(DARKGRAY);
		textcolor(BLACK);
		cputsxy(posx, posy, "|   |");		posy++;
		cputsxy(posx, posy, "|256|");		posy++;
		cputsxy(posx, posy, "|   |");
		textbackground(BLACK);
		break;
	case 512:
		textbackground(LIGHTGRAY);
		textcolor(BLACK);
		cputsxy(posx, posy, "|   |");		posy++;
		cputsxy(posx, posy, "|512|");		posy++;
		cputsxy(posx, posy, "|   |");
		textbackground(BLACK);
		break;
	case 1024:
		textbackground(YELLOW);
		textcolor(BLACK);
		cputsxy(posx, posy, "|   |");		posy++;
		cputsxy(posx, posy, "|1024");		posy++;
		cputsxy(posx, posy, "|   |");
		textbackground(BLACK);
		break;
	case 2048:
		textbackground(LIGHTGREEN);
		textcolor(BLACK);
		cputsxy(posx, posy, "|   |");		posy++;
		cputsxy(posx, posy, "|2048");		posy++;
		cputsxy(posx, posy, "|   |");
		textbackground(BLACK);
		break;
	}
}


void PrintMat(int mat[][MAX],int n , int posx, int posy)
{
	int startPosx = posx;
	for (int l = 0; l < n; l++)
	{
		posx = startPosx;
		for (int c = 0; c < n; c++)
		{
			PrintaCelula(posx, posy, mat[l][c]);
			posx += 5;
		}
		posy += 3;
	}
}
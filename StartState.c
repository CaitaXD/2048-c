#include "StateMachine.h"

int CheckOption(int *option)
{
	int value = *option;
	int input = Input();
	if (input == 's')
	{
		if (value < 2)
		{
			value++;
		}
		else { value = 0; };
	}
	else if (input == 'w')
	{
		if (value > 0)
		{
			value--;
		}
		else { value = 2; }
	}
	else if (input == 'e')
	{
		return 1;
	}
	*option = value;
}

char ScrollTroughOptions(int *option, Game *game)
{
	textbackground(BLACK);
	int value = *option;
	clrscr();
	switch (value)
	{
	case 0:
		textcolor(RED);
		cputsxy(5, 5, "Novo Jogo");
		textcolor(WHITE);
		cputsxy(5, 10, "Carregar Jogo Salvo");
		cputsxy(5, 15, "Sair");
		cputsxy(5, 20, "E to Select W to Scroll Up S to Scroll Down");
		if (CheckOption(option) == 1)
			return 'P';
		break;
	case 1:
		cputsxy(5, 5, "Novo Jogo");
		textcolor(RED);
		cputsxy(5, 10, "Carregar Jogo Salvo");
		textcolor(WHITE);
		cputsxy(5, 15, "Sair");
		cputsxy(5, 20, "E to Select W to Scroll Up S to Scroll Down");
		if (CheckOption(option) == 1)
			return 'L';
		break;
	case 2:
		cputsxy(5, 5, "Novo Jogo");
		cputsxy(5, 10, "Carregar Jogo Salvo");
		textcolor(RED);
		cputsxy(5, 15, "Sair");
		textcolor(WHITE);
		cputsxy(5, 20, "E to Select W to Scroll Up S to Scroll Down");
		if (CheckOption(option) == 1)
			return 'E';
		break;
	}
}

void StartState(Game *game)
{
	int option = 0;
	while (1)
	{
		switch (ScrollTroughOptions(&option, game))
		{
		case 'P':
			GameState(game->tabuleiro);
			break;
		case 'E':
			exit(0);
			break;
		case 'L':
			clrscr();
			Game newGame = {0};
			newGame = loadGame();
			clrscr();
			PrintMat(&newGame.tabuleiro, 4, 1, 1);

			textbackground(BLACK);
			textcolor(WHITE);
			int score = newGame.score;
			int length = snprintf(NULL, 0, "%d", score);
			char* str = malloc(length + 1);
			snprintf(str, length + 1, "%d", score);
			cputsxy(25, 1, "Socre:");
			cputsxy(32, 1, str);
			GameStateUpdate(&newGame.tabuleiro);
			break;
		}
		
	}
}
Game loadGame() {
	Game game;
	int slot = 0;
	clrscr();
	cputsxy(1, 5, "Insira o numero do slot: ");
	scanf_s(" %d%*c", &slot);
	FILE* arq;
	fopen_s(&arq, "backup.dat", "rb+");
	fseek(arq, 0L, SEEK_END);
	int fileSize = ftell(arq);
	long pos = (sizeof(Game))*(slot);
	while (pos >= fileSize)
	{
		clrscr();
		cputsxy(1, 5, "Insira um slot valido ou E para voltar: ");
		if (Input() == 'e')
		{
			clrscr();
			fclose(arq);
			StartState(&game);
		}
		scanf_s(" %d%*c", &slot);	
		pos = (sizeof(Game)) * (slot);
	}
	if (arq != NULL) 
	{
		clrscr();
		fseek(arq, pos, SEEK_SET);
		fread(&game, sizeof(Game), 1, arq);
		fclose(arq);
		return game;
	}
	else
	{
		exit(0);
	}
}
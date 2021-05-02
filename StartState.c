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

char ScrollTroughOptions(int *option)
{
	textbackground(BLACK);
	int value = *option;
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
		if (CheckOption(option) == -1)
			break;
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
		switch (ScrollTroughOptions(&option))
		{
		case 'P':
			GameState(game->tabuleiro);
			break;
		case 'E':
			exit(0);
			break;
		}
		
	}
}
#include "StateMachine.h"
int CheckOption(int *option)
{
	//Le o teclado e navega no menu ou aciona a rotina
	int value = *option;
	//inteiro relacionado a opção selecionada
	int input = Input();
	if (input == 's')
	{
		if (value < 3)
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
	//Escreve as opções do menu na tela
	textbackground(BLACK);
	int value = *option;
	//interiro relacionado a opção selecionada na tela
	clrscr();
	switch (value)
	{
	case 0:
		textcolor(RED);
		cputsxy(5, 5, "Novo Jogo");
		textcolor(WHITE);
		cputsxy(5, 10, "Carregar Jogo Salvo");
		cputsxy(5, 15, "Sair");
		cputsxy(5, 20, "High Scores");
		cputsxy(5, 25, "E to Select W to Scroll Up S to Scroll Down");
		if (CheckOption(option) == 1)
			return 'P';
		break;
	case 1:
		textcolor(WHITE);
		cputsxy(5, 5, "Novo Jogo");
		textcolor(RED);
		cputsxy(5, 10, "Carregar Jogo Salvo");
		textcolor(WHITE);
		cputsxy(5, 15, "Sair");
		cputsxy(5, 20, "High Scores");
		cputsxy(5, 25, "E to Select W to Scroll Up S to Scroll Down");
		if (CheckOption(option) == 1)
			return 'L';
		break;
	case 2:
		textcolor(WHITE);
		cputsxy(5, 5, "Novo Jogo");
		cputsxy(5, 10, "Carregar Jogo Salvo");
		textcolor(RED);
		cputsxy(5, 15, "Sair");
		textcolor(WHITE);
		cputsxy(5, 20, "High Scores");
		cputsxy(5, 25, "E to Select W to Scroll Up S to Scroll Down");
		if (CheckOption(option) == 1)
			return 'E';
		break;
	case 3:
		textcolor(WHITE);
		cputsxy(5, 5, "Novo Jogo");
		cputsxy(5, 10, "Carregar Jogo Salvo");
		cputsxy(5, 15, "Sair");
		textcolor(RED);
		cputsxy(5, 20, "High Scores");
		textcolor(WHITE);
		cputsxy(5, 25, "E to Select W to Scroll Up S to Scroll Down");
		if (CheckOption(option) == 1)
			return 'H';
		break;
	}
}

void StartState(Game *game)
{
	//Estado Inicial
	int option = 0;
	//Laço responsavel pela navegção dos menus
	while (1)
	{
		switch (ScrollTroughOptions(&option, game))
		{
		//Dado o retono de ScrollTroughOptions e aciona a rotina equivalente
		case 'P':
			//Inicia O GameState
			GameState(game->tabuleiro);
			break;
		case 'E':
			//Fecha a aplicação
			exit(0);
			break;
		case 'L':
			//Rotina responsavel por Carregar um jogo
			clrscr();
			Game newGame = {0};
			newGame = loadGame();
			clrscr();
			PrintMat(&newGame.tabuleiro, 4, 1, 1);
			textbackground(BLACK);
			textcolor(WHITE);
			cputsxy(25, 5, "W,A,S,D: Slide");
			cputsxy(25, 10, "Q: Save Game E: Back to Menu");

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



			GameStateUpdate(&newGame.tabuleiro);
			break;
		case 'H':
			PrintHighSocres();
			break;
		}

	}
}

void PrintHighSocres()
{
	//Escreve os Maior Socres na tela
	clrscr();
	Game games[10] = {0};
	int scores[10];
	FILE  *arq;
	fopen_s(&arq, "backup.dat", "rb+");
	if (arq == NULL)
	{
		fopen_s(&arq, "backup.dat", "w");
	}
	long pos = sizeof(Game);
	fseek(arq, 0L, SEEK_END);
	int fileSize = ftell(arq);
	int items = fileSize / sizeof(Game);
	fseek(arq,0, SEEK_SET);
	fread(&games, sizeof(Game), items, arq);
	int x = 0, position = 1;
	while (x < items)
	{
		int score = games[x].score;
		if (score != 0)
			scores[x] = score;
		x++;
	}
	SortScores(games,items);
	for (x = 0; x < 5; x++)
	{
		int score = games[x].score;
		if (score != 0)
		{
			int length = snprintf(NULL, 0, "%d", score);
			char* str = malloc(length + 1);
			snprintf(str, length + 1, "%d", score);
			cputsxy(5, position, "Name:");
			cputsxy(25, position, games[x].nome);
			cputsxy(50, position, "Socre:");
			cputsxy(80, position, str);
			position = position + 5;
		}
	}
	fclose(arq);
	do
	{

	} while (Input() != 'e');
}
Game loadGame() {
	//Carrega um jogo de um arquivo e retorna no struct jogo
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
void SortScores(Game vetor[], int n)
{
	//Bublesort pra ordenar os scores
	int k, j; Game aux;
	for (k = n - 1; k > 0; k--)
	{
		for (j = 0; j < k; j++) {
			if (vetor[j].score < vetor[j + 1].score) {
				aux = vetor[j];
				vetor[j] = vetor[j + 1];
				vetor[j + 1] = aux;
			}
		}
	}
}

#include "game.h"

void Game()
{
	_card empty_card = { 0, 0 };

	system("cls");
	printf("�� �÷��̾� �� : %d\n", player_num);
	
#if(!TEST)
	for (int i = 1; i <= 3; i++)
	{
		for (int j = 1; j <= player_num; j++)
		{
			player_card[i][j] = Make_Card();

			if (i == 3) Print_Card(player_card[i][j], j, i);
			else Print_Card(empty_card, j, i);

			Sleep(400);
		}
		Sleep(500);
	}
	getchar();
#else
	for (int i = 1; i <= 3; i++)
	{
		for (int j = 1; j <= player_num; j++)
		{
			player_card[i][j] = Make_Card();
			if (i == 3) Print_Card(player_card[i][j], j, i);
			else Print_Card(empty_card, j, i);
		}
	}
#endif

	int k;
	char temp_id[MAX_ID_LENGTH];
	while (1)
	{
		Erase_Line(2);
		Erase_Line(3);

		gotoxy(0, 2);
		printf("���̵� �Է��ϸ� ������ �� ī�尡 �����˴ϴ�.\n");
		printf("���̵� �Է����ּ���(�������� ������ !�� �Է����ּ���) >> "); 
		fgets(temp_id, sizeof(temp_id), stdin);
		temp_id[strlen(temp_id) - 1] = '\0';
		if (temp_id[0] == '!') break;

		k = Find_Gamer(temp_id);
		if (k == 0)
		{
			// id ���� ��.
		}
		else {
			for (int i = 1; i <= 3; i++) Print_Card(player_card[i][k], k, i);

			gotoxy(0, 5);
			printf("�ƹ� Ű�� ������ ���� ������� ȭ���� �ѱ⼼��.");
			getchar();
			gotoxy(0, 5);
			Erase_Line(5);
			
			for (int i = 1; i <= 3; i++)			
			{
				if (i == 3) Print_Card(player_card[i][k], k, i);
				else Print_Card(empty_card, k, i);
			}
		}
	}


}

int Find_Gamer(char *id)
{
	for (int i = 1; i <= player_num; i++)
	{
		if(!strcmp(id, gamer[i].id)) return i;
	}
	return 0;
}
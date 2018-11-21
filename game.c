#include "game.h"

void Game()
{
	_card empty_card = { 0, 0 };

	system("cls");
	printf("총 플레이어 수 : %d\n", player_num);
	
#if(!TEST)
	// Step 3, 4
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

	// step 3, 4 : 자신의 카드를 확인하는 과정
	char temp_id[MAX_ID_LENGTH];
	while (1)
	{
		Erase_Line(2);
		Erase_Line(3);

		gotoxy(0, 2);
		printf("아이디를 입력하면 나머지 두 카드가 공개됩니다.\n");
		printf("아이디를 입력해주세요(다음으로 가려면 !를 입력해주세요) >> "); 
		fgets(temp_id, sizeof(temp_id), stdin);
		temp_id[strlen(temp_id) - 1] = '\0';
		if (temp_id[0] == '!') break;

		k = Find_Gamer(temp_id);
		if (k == 0)
		{
			gotoxy(0, 5);
			printf("아이디가 틀렸습니다. 엔터 키를 누르고 다시 입력하세요.");
			getchar();
			fflush(stdin);
			Erase_Line(5);
		}
		else {
			for (int i = 1; i <= 3; i++) Print_Card(player_card[i][k], k, i);

			gotoxy(0, 5);
			printf("엔터 키를 누르고 다음 사람에게 화면을 넘기세요.");
			getchar();
			fflush(stdin);
			Erase_Line(5);
			
			for (int i = 1; i <= 3; i++)			
			{
				if (i == 3) Print_Card(player_card[i][k], k, i);
				else Print_Card(empty_card, k, i);
			}
		}
	}

	Erase_Line(2);
	Erase_Line(3);

	int step = 3;
	while (step != 6)
	{
		k = 1;// Boss(step);
		for (int i = 1; i <= player_num; i++)
		{
			//Bet();
			k = k % player_num + 1;
		}
		for (int i = 1; i <= player_num; i++)
		{
			player_card[step][k] = Make_Card();
			Print_Card(player_card[step][k], k, step + 1);
			Sleep(400);

			k = k % player_num + 1;
		}

		step++;
	}
	// 마지막 7번째 카드는 뒤집어 놓는다는 규칙 때문에
	{
		k = 1;// Boss(step);
		for (int i = 1; i <= player_num; i++)
		{
			//Bet();
			k = k % player_num + 1;
		}
		for (int i = 1; i <= player_num; i++)
		{
			player_card[step][k] = Make_Card();
			Print_Card(empty_card, k, step + 1);
			Sleep(400);

			k = k % player_num + 1;
		}
		step++;
	}

	// 모든 베팅과 카드 배분은 끝났고 공개만이 남았다.
}

int Boss(int step)
{

}
int Find_Gamer(char *id)
{
	for (int i = 1; i <= player_num; i++)
	{
		if(!strcmp(id, gamer[i].id)) return i;
	}
	return 0;
}
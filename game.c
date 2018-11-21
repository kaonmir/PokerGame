#include "game.h"

void Game()
{
	_card empty_card = { 0, 0 };

	system("cls");
	printf("�� �÷��̾� �� : %d\n", player_num);
	
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

	// step 3, 4 : �ڽ��� ī�带 Ȯ���ϴ� ����
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
			gotoxy(0, 5);
			printf("���̵� Ʋ�Ƚ��ϴ�. ���� Ű�� ������ �ٽ� �Է��ϼ���.");
			getchar();
			fflush(stdin);
			Erase_Line(5);
		}
		else {
			for (int i = 1; i <= 3; i++) Print_Card(player_card[i][k], k, i);

			gotoxy(0, 5);
			printf("���� Ű�� ������ ���� ������� ȭ���� �ѱ⼼��.");
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
		k = Boss(step);
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
	// ������ 7��° ī��� ������ ���´ٴ� ��Ģ ������
	{
		k = Boss(step);
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

	// ��� ���ð� ī�� ����� ������ �������� ���Ҵ�.
}

int Boss(int step)
{
	int k, max = 0, max_num = 0;
	int *chk;
	chk = (int *)calloc(player_num+1, sizeof(int));
	_card temp_card[8];

	for (int i = 1; i <= player_num; i++)
	{
		for (int j = 1; j <= step; j++) temp_card[j] = player_card[j][i];
	
		if (k = Royal_Flush(temp_card, step));			//�ξ� ��Ʈ����Ʈ �÷���
		else if (k = Straight_Flush(temp_card, step));	//��Ʈ����Ʈ �÷���
		else if (k = Four_of_a_Kind(temp_card, step));	//��ī��
		else if (k = Full_House(temp_card, step));		//Ǯ�Ͽ콺
		else if (k = Flush(temp_card, step));			//�÷���
		else if (k = Straight(temp_card, step));		//��Ʈ����Ʈ
		else if (k = Three_of_a_Kind(temp_card, step));//Ʈ����
		else if (k = Two_Pair(temp_card, step));		//�����
		else if (k = One_pair(temp_card, step));		//�����

		if (max < k) { max = k; max_num = i;}
	}
	return max_num;
}
int Find_Gamer(char *id)
{
	for (int i = 1; i <= player_num; i++)
	{
		if(!strcmp(id, gamer[i].id)) return i;
	}
	return 0;
}
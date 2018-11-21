#include "game.h"

void Game()
{
	_card empty_card = { 0, 0 };
	is_drop_allin = (int *)calloc(player_num + 1, sizeof(int));
	before_betting = BASIC_BET;

	system("cls");
	printf("총 플레이어 수 : %d", player_num);
	gotoxy(60, 0);
	printf("총 베팅 금액   : %d", betting_money);
	gotoxy(60, 1);
	printf("이전 베팅 금액 : %d", before_betting);
	
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

	Erase_Line(2);
	Erase_Line(3);

	int step = 3;
	while (step != 7)
	{
		k = 2;//Boss(step);
		for (int i = 1; i <= player_num; i++)
		{
			if (is_drop_allin[k] == DROP || is_drop_allin[k] == ALLIN) {
				k = k % player_num + 1;
				continue;
			}
			if (i == 1) Bet(k, 1);
			else Bet(k, 0);
			k = k % player_num + 1;
		}
		for (int i = 1; i <= player_num; i++)
		{
			if (is_drop_allin[k] == DROP) {
				k = k % player_num + 1;
				continue;
			}
			player_card[step][k] = Make_Card();
			if (step == 6) Print_Card(empty_card, k, step + 1);
			else Print_Card(player_card[step][k], k, step + 1);
			Sleep(400);

			k = k % player_num + 1;
		}

		step++;
	}
	// 모든 베팅과 카드 배분은 끝났고 공개만이 남았다.
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
	
		if (k = Royal_Flush(temp_card, step));			//로얄 스트레이트 플러시
		else if (k = Straight_Flush(temp_card, step));	//스트레이트 플러시
		else if (k = Four_of_a_Kind(temp_card, step));	//포카드
		else if (k = Full_House(temp_card, step));		//풀하우스
		else if (k = Flush(temp_card, step));			//플러시
		else if (k = Straight(temp_card, step));		//스트레이트
		else if (k = Three_of_a_Kind(temp_card, step));	//트리플
		else if (k = Two_Pair(temp_card, step));		//투페어
		else if (k = One_pair(temp_card, step));		//원페어

		if (max < k) { max = k; max_num = i;}
	}
	return max_num;
}
void Bet(int temp_player, bool is_boss)
{
	int n;
	int betting;

	Erase_Line(4);

	gotoxy(0, 2);
	printf("%s의 차례입니다.\n\n", gamer[temp_player].id);
	printf(" 1. Call  2. D.D   3. Half  4. Drop  5. All in\n");
	printf(" 6. Full  ");
	if (is_boss) printf("7. Ping(Boss)  8. Check(Boss)");

	while (1) {
		Erase_Line(3);
		gotoxy(0, 3);
		printf("어떤 베팅을 하시겠습니까? ");
		scanf("%d", &n);

		switch (n)
		{
		case 1: //Call
			betting = before_betting;
			break;
		case 2: // D.D
			betting = before_betting * 2;
			break;
		case 3: //Half
			betting = betting_money / 2;
			break;
		case 4: //Drop
			is_drop_allin[temp_player] = DROP;
			gotoxy((temp_player - 1) * 16 + 7, 9);
			printf("    DROP");
			betting = 0;
			break;
		case 5: //All in
			betting = gamer[temp_player].money;
			gotoxy((temp_player - 1) * 16 + 7, 9);
			printf("   ALL IN");
			break;
		case 6: // Full
			betting = betting_money;
			break;
		case 7: // Ping
			if (!is_boss){
				Betting_Error(INPUT_ERROR);
				continue;
			}
			betting = BASIC_BET;
			break;
		case 8: // Check
			if (!is_boss) {
				Betting_Error(INPUT_ERROR);
				continue;
			}
			betting = 0;
			break;
		default:
			Betting_Error(INPUT_ERROR);
			continue;
		}

		if (gamer[temp_player].money >= betting) break;
		Betting_Error(MONEY_ERROR);
	}

	betting_money += betting;
	before_betting = (betting ? betting : before_betting);
	gamer[temp_player].money -= betting;

	gotoxy(60, 0);
	printf("총 베팅 금액   : %d", betting_money);
	gotoxy(60, 1);
	printf("이전 베팅 금액 : %d", before_betting);
}

int Find_Gamer(char *id)
{
	for (int i = 1; i <= player_num; i++)
	{
		if(!strcmp(id, gamer[i].id)) return i;
	}
	return 0;
}

void Betting_Error(int error_num)
{
	gotoxy(0, 7);
	printf("잘못입력하셨습니다. 다시 입력하세요.");
	Sleep(1000);
	Erase_Line(7);
}
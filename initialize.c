#include "initialize.h"

int Find_Player(char *temp)
{
	int i;
	for (i = 1; i <= all_player; i++)
		if (strcmp(player[i].id, temp) == 0)
			return i;
	return 0;
}
bool Call_Player()
{
	FILE *fi = fopen("player.dat", "r");
	if (fi == NULL)
	{
		printf("ERROR");
		return 1;
	}

	fscanf(fi, "%d", &all_player);

	player = (_player *)malloc(sizeof(_player) * (all_player + 10));

	for (int i = 1; i <= all_player; i++)
		fscanf(fi, "%s %d\n", player[i].id, &player[i].money);
	
	fclose(fi);
	return 0;
}
int Make_Player()
{
	all_player++;

	while (1) {
		printf("사용하실 아이디를 입력해 주세요. >> ");
		scanf("%s", player[all_player].id);
		if (player[all_player].id[0] != '!') break;
		printf("아이디 첫 문자는 !가 될 수 없어요,\n\n");
	}
	//이미 있는 아이디;
	// ID length

	printf("가입 기념 100코인을 지급합니다.\n");
	player[all_player].money = 100;
	return all_player;
}
void init()
{
	if(Call_Player(player)) return;
#if(!TEST)
	while (1) {
		printf("플레이어의 수를 입력하세요 >> ");
		scanf("%d", &player_num);									 // a 넣으면 에러난다.
		if (1 <= player_num && player_num <= MAX_PLAYER) break;
		printf("입력이 잘못되었습니다.\n다시 입력 해주세요\n\n");
	}
	system("cls");
	printf("총 플레이어의 수 : %d\n", player_num);
	gamer = (_player **)malloc(sizeof(_player *) * (player_num + 1));

	for (int i = 1; i <= player_num; i++)
	{
		char temp[MAX_ID_LENGTH];
		while(1) {
			printf("아이디를 입력해주세요(가입하실려면 !를 입력하세요) >> ");
			scanf("%s", temp);

			int k;
			if (temp[0] == '!') k = Make_Player(player);
			else k = Find_Player(temp);

			if (k) {
				gamer[i] = &(player[k]);
				break;
			}
			printf("아이디가 존재하지 않습니다.\n다시 입력 해주세요\n\n");
		}
		printf("플레이어 %d에 %s님이 등록되었습니다.\n\n", i, gamer[i]->id);
	}

	Sleep(400);
	system("cls");
	printf("자 그럼 게임을 시작하겠습니다.\n");
	//Sleep(1000);
	//Shuffling();
#else
	player_num = 2;
	gamer = (_player **)malloc(sizeof(_player *) * (player_num + 1));
	gamer[1] = &(player[1]);
	gamer[2] = &(player[2]);
	return;
#endif
}

void Shuffling()
{
	system("cls");
	gotoxy(50, 3);
	printf("카드를 섞고 있어요:)");
	for (int i = 0; i < 100; i++)
	{
		gotoxy((i%10)*2 + 50, 5 + i/10);
		printf("■", i+1);
		gotoxy(70, 3);
		printf("(%2d%%)", i + 1);

		Sleep(200);
	}
}
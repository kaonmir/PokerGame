#include "initialize.h"

bool Call_Player()
{
	FILE *fi;
	if (fi = fopen("player.dat", "r") == NULL)
	{
		printf("ERROR");
		return 1;
	}

	fscanf(fi, "%d", &all_player);

	player = (_player *)malloc(sizeof(_player) * (all_player + 1));

	for (int i = 1; i <= all_player; i++)
		scanf("%s %d\n", player[i].id, &player[i].money);
	
	fclose(fi);
	return 0;
}
int Make_Player()
{
	realloc(player, sizeof(_player) * (++all_player + 1));

	while (1) {
		printf("사용하실 아이디를 입력해 주세요. >> ");
		scanf("%s", &player[all_player - 1].id);
		if (player[all_player - 1].id[0] != '!') break;
		printf("아이디 첫 문자는 !가 될 수 없어요,\n\n");
	}	
	printf("가입 기념 100코인을 지급합니다.");
	player[all_player].money = 100;

	return all_player;
}
void init()
{
	int player_num;

	if(Call_Player(player)) return;

	while (1) {
		printf("플레이어의 수를 입력하세요 >> ");
		scanf("%d", &player_num);
		if (1 <= player_num && player_num <= MAX_PLAYER) break;
		printf("입력이 잘못되었습니다.\n다시 입력 해주세요\n\n");
	}
	system("cls");
	printf("총 플레이어의 수 : %d\n", player_num);

	for (int i = 1; i <= player_num; i++)
	{
		char temp[MAX_ID_LENGTH];
		while(1) {
			printf("아이디를 입력해주세요(가입하실려면 !를 입력하세요) >> ");
			scanf("%s", temp);

			int k;
			if (temp[0] == '!') k = Make_Player(player);
			//else k = Find_Player(player, temp);

			if (k) break;

		}
	}
}
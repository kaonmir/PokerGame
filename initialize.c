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
		FILE *fp = fopen("player.dat", "w");
		fprintf(fp, "0");
		fclose(fp);
		fi = fopen("player.dat", "r");
	}

	fscanf(fi, "%d", &all_player);

	player = (_player *)malloc(sizeof(_player) * (all_player + 10));
	chkplayer = (int *)calloc(all_player + 10, sizeof(int));

	for (int i = 1; i <= all_player; i++)
		fscanf(fi, "%s %d\n", player[i].id, &player[i].money);
	
	fclose(fi);
	return 0;
}
void Write_Player()
{
	FILE *fp = fopen("player.dat", "w");

	fprintf(fp, "%d\n", all_player);
	for (int i = 1; i <= all_player; i++)
		fprintf(fp, "%s %d\n", player[i].id, player[i].money);

	fclose(fp);
	return 0;
}
int Make_Player()
{

	while (1) {
		printf("사용하실 아이디를 입력해 주세요. >> ");
		scanf("%s", player[all_player+1].id);
		if (player[all_player + 1].id[0] == '!') {
			printf("아이디 첫 문자는 !가 될 수 없어요,\n\n");
			continue;
		}
		if (strlen(player[all_player + 1].id) > MAX_ID_LENGTH) {
			printf("길이가 10자리를 넘어가면 안되요..\n\n");
			continue;
		}
		if (Find_Player(player[all_player + 1].id)) {
			printf("이미 있는 아이디에요..\n\n");
			continue;
		}
		break;
	}
	all_player++;

	printf("가입 기념 100코인을 지급합니다.\n");
	player[all_player].money = 100;
	return all_player;
}
void Init()
{
	if(Call_Player(player)) return;
#if(!TEST)
	while (1) {
		printf("플레이어의 수를 입력하세요 >> ");
		scanf("%d", &player_num);									 // a 넣으면 에러난다.
		if (1 < player_num && player_num <= MAX_PLAYER) break;
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

			if (k && !chkplayer[k]) {
				gamer[i] = &(player[k]);
				chkplayer[k] = 1;
				break;
			}

			if(!k)	printf("아이디가 존재하지 않습니다.\n다시 입력 해주세요\n\n");
			else if (chkplayer[k]) printf("이미 등록되어있습니다.\n다시 입력 해주세요\n\n");
		}
		printf("플레이어 %d에 %s님이 등록되었습니다.\n\n", i, gamer[i]->id);
	}

	Sleep(1000);
	system("cls");
	printf("자 그럼 게임을 시작하겠습니다.\n");
	Sleep(1000);
	Shuffling();
#else
	player_num = 2;
	gamer = (_player **)malloc(sizeof(_player *) * (player_num + 1));
	gamer[1] = &(player[1]);
	gamer[2] = &(player[2]);
	return;
#endif
}
void End()
{
	system("cls");
	printf("\n\n\n");
	printf("     THANK YOUU FOR ENJOYING THIS GAME\n\n");
	printf("           MADE BY : KAONMIR\n\n");
	printf("    CHUNANG UNIV. DEPARTMENT OF SOFTWARE\n");

	Write_Player();
	getch();
}
void Shuffling()
{
	system("cls");
	gotoxy(50, 3);
	printf("카드를 섞고 있어요:)");
	for (int i = 0; i < 100; i++)
	{
		gotoxy((i%10)*2 + 50, 5 + i/10);
		printf("■");
		gotoxy(70, 3);
		printf("(%2d%%)", i + 1);

		Sleep(200);
	}
}
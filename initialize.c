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
		printf("����Ͻ� ���̵� �Է��� �ּ���. >> ");
		scanf("%s", &player[all_player - 1].id);
		if (player[all_player - 1].id[0] != '!') break;
		printf("���̵� ù ���ڴ� !�� �� �� �����,\n\n");
	}	
	printf("���� ��� 100������ �����մϴ�.");
	player[all_player].money = 100;

	return all_player;
}
void init()
{
	int player_num;

	if(Call_Player(player)) return;

	while (1) {
		printf("�÷��̾��� ���� �Է��ϼ��� >> ");
		scanf("%d", &player_num);
		if (1 <= player_num && player_num <= MAX_PLAYER) break;
		printf("�Է��� �߸��Ǿ����ϴ�.\n�ٽ� �Է� ���ּ���\n\n");
	}
	system("cls");
	printf("�� �÷��̾��� �� : %d\n", player_num);

	for (int i = 1; i <= player_num; i++)
	{
		char temp[MAX_ID_LENGTH];
		while(1) {
			printf("���̵� �Է����ּ���(�����ϽǷ��� !�� �Է��ϼ���) >> ");
			scanf("%s", temp);

			int k;
			if (temp[0] == '!') k = Make_Player(player);
			//else k = Find_Player(player, temp);

			if (k) break;

		}
	}
}
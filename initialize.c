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
		printf("����Ͻ� ���̵� �Է��� �ּ���. >> ");
		scanf("%s", player[all_player].id);
		if (player[all_player].id[0] != '!') break;
		printf("���̵� ù ���ڴ� !�� �� �� �����,\n\n");
	}
	//�̹� �ִ� ���̵�;
	// ID length

	printf("���� ��� 100������ �����մϴ�.\n");
	player[all_player].money = 100;
	return all_player;
}
void init()
{
	if(Call_Player(player)) return;
#if(!TEST)
	while (1) {
		printf("�÷��̾��� ���� �Է��ϼ��� >> ");
		scanf("%d", &player_num);									 // a ������ ��������.
		if (1 <= player_num && player_num <= MAX_PLAYER) break;
		printf("�Է��� �߸��Ǿ����ϴ�.\n�ٽ� �Է� ���ּ���\n\n");
	}
	system("cls");
	printf("�� �÷��̾��� �� : %d\n", player_num);
	gamer = (_player **)malloc(sizeof(_player *) * (player_num + 1));

	for (int i = 1; i <= player_num; i++)
	{
		char temp[MAX_ID_LENGTH];
		while(1) {
			printf("���̵� �Է����ּ���(�����ϽǷ��� !�� �Է��ϼ���) >> ");
			scanf("%s", temp);

			int k;
			if (temp[0] == '!') k = Make_Player(player);
			else k = Find_Player(temp);

			if (k) {
				gamer[i] = &(player[k]);
				break;
			}
			printf("���̵� �������� �ʽ��ϴ�.\n�ٽ� �Է� ���ּ���\n\n");
		}
		printf("�÷��̾� %d�� %s���� ��ϵǾ����ϴ�.\n\n", i, gamer[i]->id);
	}

	Sleep(400);
	system("cls");
	printf("�� �׷� ������ �����ϰڽ��ϴ�.\n");
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
	printf("ī�带 ���� �־��:)");
	for (int i = 0; i < 100; i++)
	{
		gotoxy((i%10)*2 + 50, 5 + i/10);
		printf("��", i+1);
		gotoxy(70, 3);
		printf("(%2d%%)", i + 1);

		Sleep(200);
	}
}
#include "card.h"


void Print_Card(_card card, int player_num, int times)
{
	int x, y;
	const char *shape[3], *number[3];
	switch (card.shape)
	{
	case Diamond:
		shape[0] = "��";
		break;
	case Club:
		shape[0] = "��";
		break;
	case Hearts:
		shape[0] = "��";
		break;
	case Spade:
		shape[0] = "��";
		break;
	default:
		break;
	}
	switch (card.number)
	{
	case 1:
		number[0] = "��";
		break;
	case 2:
		number[0] = "��";
		break;
	case 3:
		number[0] = "��";
		break;
	case 4:
		number[0] = "��";
		break;
	case 5:
		number[0] = "��";
		break;
	case 6:
		number[0] = "��";
		break;
	case 7:
		number[0] = "��";
		break;
	case 8:
		number[0] = "��";
		break;
	case 9:
		number[0] = "��";
		break;
	case 10:
		number[0] = "��";
		break;
	case 11:
		number[0] = "��";
		break;
	case 12:
		number[0] = "��";
		break;
	case 13:
		number[0] = "��";
		break;
	default:
		break;
	}
	
	x = CARD_START_X + CARD_GAP_X * (player_num - 1);
	y = CARD_START_Y + CARD_GAP_Y * (times - 1);

	if (card.number) {
		gotoxy(x, y);
		printf("��������������������������");
		gotoxy(x, y + 1);
		printf("�� %s      ", number[0]);
		if(card.shape == Club)	printf("��");
		else if (card.shape == Spade) printf("��");
		else {
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
			printf("%s", shape[0]);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
		}
		printf("��");
	}
	switch (card.number)
	{
	case 0: {
		gotoxy(x, y);
		printf("��������������������������");
		gotoxy(x, y + 1);
		printf("�� �ءءءءئ�");
		gotoxy(x, y + 2);
		printf("�� �ءءءءئ�");
		gotoxy(x, y + 3);
		printf("�� �ءءءءئ�");
		gotoxy(x, y + 4);
		printf("�� �ءءءءئ�");
		gotoxy(x, y + 5);
		printf("�� �ءءءءئ�");
		gotoxy(x, y + 6);
		printf("�� �ءءءءئ�");
		gotoxy(x, y + 7);
		printf("�� �ءءءءئ�");
		gotoxy(x, y + 8);
		printf("�� �ءءءءئ�");
		gotoxy(x, y + 9);
		printf("�� �ءءءءئ�");
		gotoxy(x, y + 10);
		printf("��������������������������");
		break;
	}
	case 1: {
		gotoxy(x, y + 2);
		printf("��           ��");
		gotoxy(x, y + 3);
		printf("��           ��");
		gotoxy(x, y + 4);
		printf("��           ��");
		gotoxy(x, y + 5);
		printf("��     %s    ��", shape[0]);
		gotoxy(x, y + 6);
		printf("��           ��");
		gotoxy(x, y + 7);
		printf("��           ��");
		gotoxy(x, y + 8);
		printf("��           ��");
		break;
	}
	case 2: {
		gotoxy(x, y + 2);
		printf("��           ��");
		gotoxy(x, y + 3);
		printf("��     %s    ��", shape[0]);
		gotoxy(x, y + 4);
		printf("��           ��");
		gotoxy(x, y + 5);
		printf("��           ��");
		gotoxy(x, y + 6);
		printf("��           ��");
		gotoxy(x, y + 7);
		printf("��     %s    ��", shape[0]);
		gotoxy(x, y + 8);
		printf("��           ��");
		break;
	}
	case 3: {
		gotoxy(x, y + 2);
		printf("��     %s    ��", shape[0]);
		gotoxy(x, y + 3);
		printf("��           ��");
		gotoxy(x, y + 4);
		printf("��           ��");
		gotoxy(x, y + 5);
		printf("��     %s    ��", shape[0]);
		gotoxy(x, y + 6);
		printf("��           ��");
		gotoxy(x, y + 7);
		printf("��           ��");
		gotoxy(x, y + 8);
		printf("��     %s    ��", shape[0]);
		break;
	}
	case 4: {
		gotoxy(x, y + 2);
		printf("��  %s    %s ��", shape[0], shape[0]);
		gotoxy(x, y + 3);
		printf("��           ��");
		gotoxy(x, y + 4);
		printf("��           ��");
		gotoxy(x, y + 5);
		printf("��           ��");
		gotoxy(x, y + 6);
		printf("��           ��");
		gotoxy(x, y + 7);
		printf("��           ��");
		gotoxy(x, y + 8);
		printf("��  %s    %s ��", shape[0], shape[0]);
		break;
	}
	case 5: {
		gotoxy(x, y + 2);
		printf("��  %s    %s ��", shape[0], shape[0]);
		gotoxy(x, y + 3);
		printf("��           ��");
		gotoxy(x, y + 4);
		printf("��           ��");
		gotoxy(x, y + 5);
		printf("��     %s    ��", shape[0]);
		gotoxy(x, y + 6);
		printf("��           ��");
		gotoxy(x, y + 7);
		printf("��           ��");
		gotoxy(x, y + 8);
		printf("��  %s    %s ��", shape[0], shape[0]);
		break;
	}
	case 6: {
		gotoxy(x, y + 2);
		printf("��  %s    %s ��", shape[0], shape[0]);
		gotoxy(x, y + 3);
		printf("��           ��");
		gotoxy(x, y + 4);
		printf("��           ��");
		gotoxy(x, y + 5);
		printf("��  %s    %s ��", shape[0], shape[0]);
		gotoxy(x, y + 6);
		printf("��           ��");
		gotoxy(x, y + 7);
		printf("��           ��");
		gotoxy(x, y + 8);
		printf("��  %s    %s ��", shape[0], shape[0]);
		break;
	}
	case 7: {
		gotoxy(x, y + 2);
		printf("��   %s  %s  ��", shape[0], shape[0]);
		gotoxy(x, y + 3);
		printf("��           ��");
		gotoxy(x, y + 4);
		printf("��           ��");
		gotoxy(x, y + 5);
		printf("��  %s %s %s ��", shape[0], shape[0], shape[0]);
		gotoxy(x, y + 6);
		printf("��           ��");
		gotoxy(x, y + 7);
		printf("��           ��");
		gotoxy(x, y + 8);
		printf("��   %s  %s  ��", shape[0], shape[0]);
		break;
	}
	case 8: {
		gotoxy(x, y + 2);
		printf("��  %s    %s ��", shape[0], shape[0]);
		gotoxy(x, y + 3);
		printf("��           ��");
		gotoxy(x, y + 4);
		printf("��  %s    %s ��", shape[0], shape[0]);
		gotoxy(x, y + 5);
		printf("��           ��");
		gotoxy(x, y + 6);
		printf("��  %s    %s ��", shape[0], shape[0]);
		gotoxy(x, y + 7);
		printf("��           ��");
		gotoxy(x, y + 8);
		printf("��  %s    %s ��", shape[0], shape[0]);
		break;
	}
	case 9: {
		gotoxy(x, y + 2);
		printf("��     %s    ��", shape[0]);
		gotoxy(x, y + 3);
		printf("��  %s    %s ��", shape[0], shape[0]);
		gotoxy(x, y + 4);
		printf("��           ��");
		gotoxy(x, y + 5);
		printf("��  %s %s %s ��", shape[0], shape[0], shape[0]);
		gotoxy(x, y + 6);
		printf("��           ��");
		gotoxy(x, y + 7);
		printf("��  %s    %s ��", shape[0], shape[0]);
		gotoxy(x, y + 8);
		printf("��     %s    ��", shape[0]);
		break;
	}
	case 10: {
		gotoxy(x, y + 2);
		printf("��  %s    %s ��", shape[0], shape[0]);
		gotoxy(x, y + 3);
		printf("��     %s    ��", shape[0]);
		gotoxy(x, y + 4);
		printf("��  %s    %s ��", shape[0], shape[0]);
		gotoxy(x, y + 5);
		printf("��           ��");
		gotoxy(x, y + 6);
		printf("��  %s    %s ��", shape[0], shape[0]);
		gotoxy(x, y + 7);
		printf("��     %s    ��", shape[0]);
		gotoxy(x, y + 8);
		printf("��  %s    %s ��", shape[0], shape[0]);
		break;
	}
	case 11: {
		gotoxy(x, y + 2);
		printf("��        %s ��", shape[0]);
		gotoxy(x, y + 3);
		printf("��        %s ��", shape[0]);
		gotoxy(x, y + 4);
		printf("��        %s ��", shape[0]);
		gotoxy(x, y + 5);
		printf("��        %s ��", shape[0]);
		gotoxy(x, y + 6);
		printf("��        %s ��", shape[0]);
		gotoxy(x, y + 7);
		printf("��  %s    %s ��", shape[0], shape[0]);
		gotoxy(x, y + 8);
		printf("��   %s%s%s  ��", shape[0], shape[0], shape[0]);
		break;
	}
	case 12: {
		gotoxy(x, y + 2);
		printf("��   %s%s%s  ��", shape[0], shape[0], shape[0]);
		gotoxy(x, y + 3);
		printf("��  %s    %s ��", shape[0], shape[0]);
		gotoxy(x, y + 4);
		printf("��  %s    %s ��", shape[0], shape[0]);
		gotoxy(x, y + 5);
		printf("��  %s    %s ��", shape[0], shape[0]);
		gotoxy(x, y + 6);
		printf("��  %s    %s ��", shape[0], shape[0]);
		gotoxy(x, y + 7);
		printf("��  %s  %s   ��", shape[0], shape[0]);
		gotoxy(x, y + 8);
		printf("��   %s%s %s ��", shape[0], shape[0], shape[0]);
		break;
	}
	case 13: {
		gotoxy(x, y + 2);
		printf("�� %s      %s��", shape[0], shape[0]);
		gotoxy(x, y + 3);
		printf("�� %s    %s  ��", shape[0], shape[0]);
		gotoxy(x, y + 4);
		printf("�� %s  %s    ��", shape[0], shape[0]);
		gotoxy(x, y + 5);
		printf("�� %s%s      ��", shape[0], shape[0]);
		gotoxy(x, y + 6);
		printf("�� %s  %s    ��", shape[0], shape[0]);
		gotoxy(x, y + 7);
		printf("�� %s    %s  ��", shape[0], shape[0]);
		gotoxy(x, y + 8);
		printf("�� %s      %s��", shape[0], shape[0]);
		break;
	}
	default:
		break;
	}
	if (card.number) {
		gotoxy(x, y + 9);
		printf("��         %s��", number[0]);
		gotoxy(x, y + 10);
		printf("��������������������������");
	}
}
_card Make_Card()
{
	srand(time(NULL));

	_card temp;
	while (1)
	{
		temp.number = rand() % 13 + 1;
		temp.shape = rand() % 4 + 1;
		if (card[temp.shape][temp.number] == 0) break;
	}
	card[temp.shape][temp.number] = 1;
	return temp;
}

int Royal_Flush(_card player[], int start, int end)
{
	if (end - start < 5) return 0;
	return 0;
}

int Straight_Flush(_card player[], int start, int end)
{
	if (end - start < 5) return 0;
	return 0;
}

int Four_of_a_Kind(_card player[], int start, int end)
{
	if (end - start < 4) return 0;
	return 0;
}

int Full_House(_card player[], int start, int end)
{
	if (end - start < 5) return 0;
	return 0;
}

int Flush(_card player[], int start, int end)
{
	int i, cnt = 1;

	if (end - start < 4) return 0;
	sort(player, SORT_BY_SHAPE, start, end);
	for (i = end - 1; i >= start; i--)
	{
		if (cnt == 4) break;

		if (player[i].shape == player[i + 1].shape) cnt++;
		else cnt = 1;
	}
	if (cnt == 4)
		for (int j = end; j >= start; j++)
			if (player[j].shape == player[i + 1].shape)
				return 6 * JOKBO + player[j].number * NUMBER + player[j].shape * SHAPE;
	return 0;
}
int	Straight(_card player[], int start, int end)
{
	int cnt = 1;
	int before_num;

	if (end - start < 5) return 0;
	sort(player, SORT_BY_NUMBER_ONE, start, end);
	before_num = player[end].number;

	for (int i = end - 1; i >= start; i--)
	{
		if (cnt == 5) break;

		if (player[i].number == before_num - 1) {
			cnt++; before_num--;
		}
		else {
			cnt = 1; before_num = player[i].number;
		}
	}
	if (cnt == 5)
		for (int i = end; i >= start; i++)
			if (player[i].number == before_num - 4)
				return 5 * JOKBO + player[i].number * NUMBER + player[i].shape * SHAPE;
	return 0;
}
int Three_of_a_Kind(_card player[], int start, int end)
{
	if (end - start < 3) return 0;
	sort(player, SORT_BY_NUMBER_FOURTEEN, start, end);
	for (int i = end; i > start + 1; i--) {
		if (player[i].number == player[i - 1].number && player[i - 1].number == player[i - 2].number) {
			if (player[i].number == 1) player[i].number = 14;
			return 4 * JOKBO + player[i].number * NUMBER + player[i].shape * SHAPE;
		}
	}
	return 0;
}
int Two_Pair(_card player[], int start, int end)
{
	int cnt = 0;
	_card return_card;

	if (end - start < 4) return 0;
	sort(player, SORT_BY_NUMBER_FOURTEEN, start, end);
	for (int i = end; i > start; i--) {
		if (player[i].number == player[i - 1].number){
			if (cnt == 0) return_card = player[i];
			cnt++;
		}
	}
	if (return_card.number == 1) return_card.number = 14;
	if(cnt >= 1) return 3 * JOKBO + return_card.number * NUMBER + return_card.shape * SHAPE;
	return 0;
}
int One_pair(_card player[], int start, int end)
{
	if (end - start < 2) return 0;
	sort(player, SORT_BY_NUMBER_FOURTEEN, start, end);
	for (int i = end; i > start; i--) {
		if (player[i].number == player[i - 1].number) {
			if (player[i].number == 1) player[i].number = 14;
			return 2 * JOKBO + player[i].number * NUMBER + player[i].shape * SHAPE;
		}
	}
	return 0;
}
int Top(_card player[], int start, int end)
{
	sort(player, SORT_BY_NUMBER_FOURTEEN, start, end);
	if (player[end].number == 1) player[end].number = 14;
	return 1 * JOKBO + player[end].number * NUMBER + player[end].shape * SHAPE;
}
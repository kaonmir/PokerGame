#include "card.h"


bool Royal_Flush(_card player)
{
}
bool Four_of_a_Kind(_card player)
{

	sort(&player, SORT_BY_NUMBER);;
}
bool Straight_Flush(_card player);
bool Four_of_a_Kind(_card player);
bool Full_House(_card player);
bool Flush(_card player);
bool Straight();
bool Three_of_a_Kind(_card player);
bool Two_Pair(_card player);
bool One_pair(_card player);


void Print_Card(_card card, int player_num, int times)
{
	int x, y;
	const char *shape[3], *number[3];
	switch (card.shape)
	{
	case Diamond:
		shape[0] = "¡ß";
		break;
	case Club:
		shape[0] = "¢À";
		break;
	case Hearts:
		shape[0] = "¢¾";
		break;
	case Spade:
		shape[0] = "¢¼";
		break;
	default:
		break;
	}
	switch (card.number)
	{
	case 1:
		number[0] = "¨ç";
		break;
	case 2:
		number[0] = "¨è";
		break;
	case 3:
		number[0] = "¨é";
		break;
	case 4:
		number[0] = "¨ê";
		break;
	case 5:
		number[0] = "¨ë";
		break;
	case 6:
		number[0] = "¨ì";
		break;
	case 7:
		number[0] = "¨í";
		break;
	case 8:
		number[0] = "¨î";
		break;
	case 9:
		number[0] = "¨ï";
		break;
	case 10:
		number[0] = "¨ð";
		break;
	case 11:
		number[0] = "£Ê";
		break;
	case 12:
		number[0] = "£Ñ";
		break;
	case 13:
		number[0] = "£Ë";
		break;
	default:
		break;
	}
	
	x = CARD_START_X + CARD_GAP_X * (player_num - 1);
	y = CARD_START_Y + CARD_GAP_Y * (times - 1);

	if (card.number) {
		gotoxy(x, y);
		printf("¦£¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¤");
		gotoxy(x, y + 1);
		printf("¦¢ %s      ", number[0]);
		if(card.shape == Club)	printf("¢¿");
		else if (card.shape == Spade) printf("¢»");
		else {
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
			printf("%s", shape[0]);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
		}
		printf("¦¢");
	}
	switch (card.number)
	{
	case 0: {
		gotoxy(x, y);
		printf("¦£¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¤");
		gotoxy(x, y + 1);
		printf("¦¢ ¡Ø¡Ø¡Ø¡Ø¡Ø¦¢");
		gotoxy(x, y + 2);
		printf("¦¢ ¡Ø¡Ø¡Ø¡Ø¡Ø¦¢");
		gotoxy(x, y + 3);
		printf("¦¢ ¡Ø¡Ø¡Ø¡Ø¡Ø¦¢");
		gotoxy(x, y + 4);
		printf("¦¢ ¡Ø¡Ø¡Ø¡Ø¡Ø¦¢");
		gotoxy(x, y + 5);
		printf("¦¢ ¡Ø¡Ø¡Ø¡Ø¡Ø¦¢");
		gotoxy(x, y + 6);
		printf("¦¢ ¡Ø¡Ø¡Ø¡Ø¡Ø¦¢");
		gotoxy(x, y + 7);
		printf("¦¢ ¡Ø¡Ø¡Ø¡Ø¡Ø¦¢");
		gotoxy(x, y + 8);
		printf("¦¢ ¡Ø¡Ø¡Ø¡Ø¡Ø¦¢");
		gotoxy(x, y + 9);
		printf("¦¢ ¡Ø¡Ø¡Ø¡Ø¡Ø¦¢");
		gotoxy(x, y + 10);
		printf("¦¦¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¥");
		break;
	}
	case 1: {
		gotoxy(x, y + 2);
		printf("¦¢           ¦¢");
		gotoxy(x, y + 3);
		printf("¦¢           ¦¢");
		gotoxy(x, y + 4);
		printf("¦¢           ¦¢");
		gotoxy(x, y + 5);
		printf("¦¢     %s    ¦¢", shape[0]);
		gotoxy(x, y + 6);
		printf("¦¢           ¦¢");
		gotoxy(x, y + 7);
		printf("¦¢           ¦¢");
		gotoxy(x, y + 8);
		printf("¦¢           ¦¢");
		break;
	}
	case 2: {
		gotoxy(x, y + 2);
		printf("¦¢           ¦¢");
		gotoxy(x, y + 3);
		printf("¦¢     %s    ¦¢", shape[0]);
		gotoxy(x, y + 4);
		printf("¦¢           ¦¢");
		gotoxy(x, y + 5);
		printf("¦¢           ¦¢");
		gotoxy(x, y + 6);
		printf("¦¢           ¦¢");
		gotoxy(x, y + 7);
		printf("¦¢     %s    ¦¢", shape[0]);
		gotoxy(x, y + 8);
		printf("¦¢           ¦¢");
		break;
	}
	case 3: {
		gotoxy(x, y + 2);
		printf("¦¢     %s    ¦¢", shape[0]);
		gotoxy(x, y + 3);
		printf("¦¢           ¦¢");
		gotoxy(x, y + 4);
		printf("¦¢           ¦¢");
		gotoxy(x, y + 5);
		printf("¦¢     %s    ¦¢", shape[0]);
		gotoxy(x, y + 6);
		printf("¦¢           ¦¢");
		gotoxy(x, y + 7);
		printf("¦¢           ¦¢");
		gotoxy(x, y + 8);
		printf("¦¢     %s    ¦¢", shape[0]);
		break;
	}
	case 4: {
		gotoxy(x, y + 2);
		printf("¦¢  %s    %s ¦¢", shape[0], shape[0]);
		gotoxy(x, y + 3);
		printf("¦¢           ¦¢");
		gotoxy(x, y + 4);
		printf("¦¢           ¦¢");
		gotoxy(x, y + 5);
		printf("¦¢           ¦¢");
		gotoxy(x, y + 6);
		printf("¦¢           ¦¢");
		gotoxy(x, y + 7);
		printf("¦¢           ¦¢");
		gotoxy(x, y + 8);
		printf("¦¢  %s    %s ¦¢", shape[0], shape[0]);
		break;
	}
	case 5: {
		gotoxy(x, y + 2);
		printf("¦¢  %s    %s ¦¢", shape[0], shape[0]);
		gotoxy(x, y + 3);
		printf("¦¢           ¦¢");
		gotoxy(x, y + 4);
		printf("¦¢           ¦¢");
		gotoxy(x, y + 5);
		printf("¦¢     %s    ¦¢", shape[0]);
		gotoxy(x, y + 6);
		printf("¦¢           ¦¢");
		gotoxy(x, y + 7);
		printf("¦¢           ¦¢");
		gotoxy(x, y + 8);
		printf("¦¢  %s    %s ¦¢", shape[0], shape[0]);
		break;
	}
	case 6: {
		gotoxy(x, y + 2);
		printf("¦¢  %s    %s ¦¢", shape[0], shape[0]);
		gotoxy(x, y + 3);
		printf("¦¢           ¦¢");
		gotoxy(x, y + 4);
		printf("¦¢           ¦¢");
		gotoxy(x, y + 5);
		printf("¦¢  %s    %s ¦¢", shape[0], shape[0]);
		gotoxy(x, y + 6);
		printf("¦¢           ¦¢");
		gotoxy(x, y + 7);
		printf("¦¢           ¦¢");
		gotoxy(x, y + 8);
		printf("¦¢  %s    %s ¦¢", shape[0], shape[0]);
		break;
	}
	case 7: {
		gotoxy(x, y + 2);
		printf("¦¢   %s  %s  ¦¢", shape[0], shape[0]);
		gotoxy(x, y + 3);
		printf("¦¢           ¦¢");
		gotoxy(x, y + 4);
		printf("¦¢           ¦¢");
		gotoxy(x, y + 5);
		printf("¦¢  %s %s %s ¦¢", shape[0], shape[0], shape[0]);
		gotoxy(x, y + 6);
		printf("¦¢           ¦¢");
		gotoxy(x, y + 7);
		printf("¦¢           ¦¢");
		gotoxy(x, y + 8);
		printf("¦¢   %s  %s  ¦¢", shape[0], shape[0]);
		break;
	}
	case 8: {
		gotoxy(x, y + 2);
		printf("¦¢  %s    %s ¦¢", shape[0], shape[0]);
		gotoxy(x, y + 3);
		printf("¦¢           ¦¢");
		gotoxy(x, y + 4);
		printf("¦¢  %s    %s ¦¢", shape[0], shape[0]);
		gotoxy(x, y + 5);
		printf("¦¢           ¦¢");
		gotoxy(x, y + 6);
		printf("¦¢  %s    %s ¦¢", shape[0], shape[0]);
		gotoxy(x, y + 7);
		printf("¦¢           ¦¢");
		gotoxy(x, y + 8);
		printf("¦¢  %s    %s ¦¢", shape[0], shape[0]);
		break;
	}
	case 9: {
		gotoxy(x, y + 2);
		printf("¦¢     %s    ¦¢", shape[0]);
		gotoxy(x, y + 3);
		printf("¦¢  %s    %s ¦¢", shape[0], shape[0]);
		gotoxy(x, y + 4);
		printf("¦¢           ¦¢");
		gotoxy(x, y + 5);
		printf("¦¢  %s %s %s ¦¢", shape[0], shape[0], shape[0]);
		gotoxy(x, y + 6);
		printf("¦¢           ¦¢");
		gotoxy(x, y + 7);
		printf("¦¢  %s    %s ¦¢", shape[0], shape[0]);
		gotoxy(x, y + 8);
		printf("¦¢     %s    ¦¢", shape[0]);
		break;
	}
	case 10: {
		gotoxy(x, y + 2);
		printf("¦¢  %s    %s ¦¢", shape[0], shape[0]);
		gotoxy(x, y + 3);
		printf("¦¢     %s    ¦¢", shape[0]);
		gotoxy(x, y + 4);
		printf("¦¢  %s    %s ¦¢", shape[0], shape[0]);
		gotoxy(x, y + 5);
		printf("¦¢           ¦¢");
		gotoxy(x, y + 6);
		printf("¦¢  %s    %s ¦¢", shape[0], shape[0]);
		gotoxy(x, y + 7);
		printf("¦¢     %s    ¦¢", shape[0]);
		gotoxy(x, y + 8);
		printf("¦¢  %s    %s ¦¢", shape[0], shape[0]);
		break;
	}
	case 11: {
		gotoxy(x, y + 2);
		printf("¦¢        %s ¦¢", shape[0]);
		gotoxy(x, y + 3);
		printf("¦¢        %s ¦¢", shape[0]);
		gotoxy(x, y + 4);
		printf("¦¢        %s ¦¢", shape[0]);
		gotoxy(x, y + 5);
		printf("¦¢        %s ¦¢", shape[0]);
		gotoxy(x, y + 6);
		printf("¦¢        %s ¦¢", shape[0]);
		gotoxy(x, y + 7);
		printf("¦¢  %s    %s ¦¢", shape[0], shape[0]);
		gotoxy(x, y + 8);
		printf("¦¢   %s%s%s  ¦¢", shape[0], shape[0], shape[0]);
		break;
	}
	case 12: {
		gotoxy(x, y + 2);
		printf("¦¢   %s%s%s  ¦¢", shape[0], shape[0], shape[0]);
		gotoxy(x, y + 3);
		printf("¦¢  %s    %s ¦¢", shape[0], shape[0]);
		gotoxy(x, y + 4);
		printf("¦¢  %s    %s ¦¢", shape[0], shape[0]);
		gotoxy(x, y + 5);
		printf("¦¢  %s    %s ¦¢", shape[0], shape[0]);
		gotoxy(x, y + 6);
		printf("¦¢  %s    %s ¦¢", shape[0], shape[0]);
		gotoxy(x, y + 7);
		printf("¦¢  %s  %s   ¦¢", shape[0], shape[0]);
		gotoxy(x, y + 8);
		printf("¦¢   %s%s %s ¦¢", shape[0], shape[0], shape[0]);
		break;
	}
	case 13: {
		gotoxy(x, y + 2);
		printf("¦¢ %s      %s¦¢", shape[0], shape[0]);
		gotoxy(x, y + 3);
		printf("¦¢ %s    %s  ¦¢", shape[0], shape[0]);
		gotoxy(x, y + 4);
		printf("¦¢ %s  %s    ¦¢", shape[0], shape[0]);
		gotoxy(x, y + 5);
		printf("¦¢ %s%s      ¦¢", shape[0], shape[0]);
		gotoxy(x, y + 6);
		printf("¦¢ %s  %s    ¦¢", shape[0], shape[0]);
		gotoxy(x, y + 7);
		printf("¦¢ %s    %s  ¦¢", shape[0], shape[0]);
		gotoxy(x, y + 8);
		printf("¦¢ %s      %s¦¢", shape[0], shape[0]);
		break;
	}
	default:
		break;
	}
	if (card.number) {
		gotoxy(x, y + 9);
		printf("¦¢         %s¦¢", number[0]);
		gotoxy(x, y + 10);
		printf("¦¦¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¥");
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
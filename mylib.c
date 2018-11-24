#include "mylib.h"

void sort(_card *card, int SORT_BY, int num)
{
	_card temp;
	for (int i = start; i <= end; i++) {
		for (int j = i + 1; j <= end; j++) {
			if (compare(card[i], card[j], SORT_BY)) {
				temp = card[i];
				card[i] = card[j];
				card[j] = temp;
			}
		}
	}
	return;
}

bool compare(const _card A, const _card B, int SORT_BY)
{
	switch (SORT_BY)
	{
	case SORT_BY_NUMBER_ONE:
		if (A.number > B.number) return true;
		else if (A.number == B.number && A.shape > B.shape) return true;
		else return false;
	case SORT_BY_NUMBER_FOURTEEN:
		if (A.number == 1 && B.number == 1 && A.shape < B.shape) return false;
		else if (A.number == 1) return true;
		else if (B.number == 1) return false;
		else if (A.number > B.number) return true;
		else if (A.number == B.number && A.shape > B.shape) return true;
		else return false;
	case SORT_BY_SHAPE:
		if (A.shape > B.shape) return true;
		else if (A.shape == B.shape && A.number > B.number) return true;
		else return false;
	default:
		break;
	}
}

void Erase_Line(int line)
{
	gotoxy(0, line);
	printf("                                                                                        ");
}

void gotoxy(int x, int y)
{
	COORD pos = { x,y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}
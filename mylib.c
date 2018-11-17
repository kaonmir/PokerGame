#include "mylib.h"

void sort(_card *card, int SORT_BY)
{
	_card temp;
	for (int i = 0; i < SEVEN; i++) {
		for (int j = i + 1; j < SEVEN; j++) {
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
	if (SORT_BY == SORT_BY_NUMBER && A.number > B.number) return true;
	else if (SORT_BY == SORT_BY_SHAPE && A.shape > B.shape) return true;
	else return false;
}
#pragma once
#ifndef __H_MYLIB_INCLUDED_
#define __H_MYLIB_INCLUDED_

#include "Setting.h"

#define SORT_BY_NUMBER_ONE 0
#define SORT_BY_NUMBER_FOURTEEN 1
#define SORT_BY_SHAPE 2

void sort(_card *card, int SORT_BY, int start, int end); // 오름차순
bool compare(const _card A, const _card B, int SORT_BY);

void Erase_Line(int line);
void gotoxy(int x, int y);
#endif
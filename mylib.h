#pragma once
#ifndef __H_MYLIB_INCLUDED_
#define __H_MYLIB_INCLUDED_

#include "Setting.h"

#define SORT_BY_NUMBER 0
#define SORT_BY_SHAPE 1

void sort(_card *card, int SORT_BY, int num); // ��������
bool compare(const _card A, const _card B, int SORT_BY);

void Erase_Line(int line);
void gotoxy(int x, int y);
#endif
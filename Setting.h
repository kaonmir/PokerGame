#pragma warning(disable:4996)
#ifndef __H_SETTING_INCLUDED_
#define __H_SETTING_INCLUDED_

#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>

typedef int bool;
#define true 1
#define false 0

#define SEVEN 7

#define MAX_PLAYER 7
#define MAX_ID_LENGTH 100

// 숫자가 클 수록 족보가 높다
enum _card_shape {
	Diamond = 1,
	Club,
	Hearts,
	Spade
};

//카드 구조체 선언
typedef struct _card {
	enum _card_shape shape;
	int number; //1~13
} _card;

typedef struct _player {
	char id[MAX_ID_LENGTH];
	int money;
} _player;
#endif
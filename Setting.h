#pragma warning(disable:4996)
#ifndef __H_SETTING_INCLUDED_
#define __H_SETTING_INCLUDED_

#define TEST 0

#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>

typedef int bool;
#define true 1
#define false 0

#define MAX_PLAYER 7
#define MAX_ID_LENGTH 10

// 숫자가 클 수록 족보가 높다
typedef enum _card_shape {
	Club = 1,
	Diamond,
	Hearts,
	Spade
} _card_shape;

//카드 구조체 선언
typedef struct _card {
	_card_shape shape;
	int number; //1~13
} _card;

// 플레이어의 정보
typedef struct _player {
	char id[MAX_ID_LENGTH];
	int money;
} _player;

int player_num;
_player **gamer;
#endif

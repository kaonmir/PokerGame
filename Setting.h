#pragma warning(disable:4996)
#ifndef __H_SETTING_INCLUDED_
#define __H_SETTING_INCLUDED_

#define TEST 1

#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>

typedef int bool;
#define true 1
#define false 0

#define MAX_PLAYER 7
#define MAX_ID_LENGTH 100

// ���ڰ� Ŭ ���� ������ ����
typedef enum _card_shape {
	Diamond = 1,
	Club,
	Hearts,
	Spade
} _card_shape;

//ī�� ����ü ����
typedef struct _card {
	_card_shape shape;
	int number; //1~13
} _card;

// �÷��̾��� ����
typedef struct _player {
	char id[MAX_ID_LENGTH];
	int money;
} _player;

int player_num;
_player *gamer;
#endif
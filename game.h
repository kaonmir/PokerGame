#pragma warning(disable:4996)
#ifndef __H_GAME_INCLUDED_
#define __H_GAME_INCLUDED_

#include <stdlib.h>
#include <time.h>
#include "card.h"
#include "mylib.h"
#include "Setting.h"

_card player_card[8][8]; // step, player
int betting_money;

void Game();
int Find_Gamer(char *id);
int Boss(int step); // ���� ���� ���� ī���и� ������ �ִ°�
void Bet(int temp_player);
#endif
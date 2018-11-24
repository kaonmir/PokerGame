#pragma warning(disable:4996)
#ifndef __H_GAME_INCLUDED_
#define __H_GAME_INCLUDED_

#include <stdlib.h>
#include <time.h>
#include "card.h"
#include "mylib.h"
#include "Setting.h"

#define BASIC_BET 5

#define WINDOWS_X_BETTING 30
#define WINDOWS_X_MONEY 55

#define INPUT_ERROR 1
#define MONEY_ERROR 2

#define RESET 0
#define DROP 1
#define ALLIN 2


_card player_card[8][8]; // step, player
int betting_money;
int before_betting;
int *is_drop_allin;


void Game();
int Boss(int step); // 누가 가장 높은 카드패를 가지고 있는가
void Bet(int temp_player, bool is_boss);

int Find_Gamer(char *id);
void Betting_Error(int error_num);
void Print_status(int status, int num);
void Print_Windows();
#endif
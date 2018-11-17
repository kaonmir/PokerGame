#pragma warning(disable:4996)
#ifndef __H_CARD_INCLUDED_
#define __H_CARD_INCLUDED_

#include <stdio.h>
#include "Setting.h"

int all_player;
_player *player; // 1-index

bool Call_Player();
int Make_Player();
void init();

#endif
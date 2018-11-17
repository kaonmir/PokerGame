#ifndef __H_CARD_INCLUDED_
#define __H_CARD_INCLUDED_

#include "Setting.h"
#include "mylib.h"

#define CARD_START_X 6
#define CARD_GAP_X 16
#define CARD_START_Y 10
#define CARD_GAP_Y 2

int card[5][14]; // 카드 중복 체크

//족보 높은 순으로
bool Royal_Flush(_card player);		//로얄 스트레이트 플러시
bool Straight_Flush(_card player);	//스트레이트 플러시
bool Four_of_a_Kind(_card player);	//포카드
bool Full_House(_card player);		//풀하우스
bool Flush(_card player);			//플러시
bool Straight(_card player);		//스트레이트
bool Three_of_a_Kind(_card player);	//트리플
bool Two_Pair(_card player);		//투페어
bool One_pair(_card player);		//원페어
// Top(No_pair)

void Print_Card(_card card, int player_num, int times); // 카드 그림 출력 함수
_card Make_Card(); // 중복되지 않는 카드 한 장을 반환하는 함수
#endif
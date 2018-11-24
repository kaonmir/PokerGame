#ifndef __H_CARD_INCLUDED_
#define __H_CARD_INCLUDED_

#include "Setting.h"
#include <time.h>
#include <stdlib.h>
#include "mylib.h"

#define CARD_START_X 6
#define CARD_GAP_X 16
#define CARD_START_Y 12
#define CARD_GAP_Y 2

#define JOKBO 16 * 16
#define NUMBER 16
#define SHAPE 1

int card[5][14]; // 카드 중복 체크

// 족보 높은 순으로
// 리턴값은 16진법으로 족보, 숫자, 그림
// 모든 함수가 자신의 함수가 가장 높은 패일 때 가장 정확한 값을 리턴한다.
// 숫자 1은 14로 해서 리턴한다
int Royal_Flush(_card player[], int start, int end);		//로얄 스트레이트 플러시	// 10
int Straight_Flush(_card player[], int start, int end);		//스트레이트 플러시			// 9
int Four_of_a_Kind(_card player[], int start, int end);		//포카드					// 8
int Full_House(_card player[], int start, int end);			//풀하우스					// 7
int Flush(_card player[], int start, int end);				//플러시					// 6
int Straight(_card player[], int start, int end);			//스트레이트				// 5
int Three_of_a_Kind(_card player[], int start, int end);	//트리플					// 4
int Two_Pair(_card player[], int start, int end);			//투페어					// 3
int One_pair(_card player[], int start, int end);			//원페어					// 2
int Top(_card player[], int start, int end);				//노페어					// 1

void Print_Card(_card card, int player_num, int times); // 카드 그림 출력 함수
_card Make_Card(); // 중복되지 않는 카드 한 장을 반환하는 함수
#endif
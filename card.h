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

int card[5][14]; // ī�� �ߺ� üũ

// ���� ���� ������
// ���ϰ��� 16�������� ����, ����, �׸�
// ��� �Լ��� �ڽ��� �Լ��� ���� ���� ���� �� ���� ��Ȯ�� ���� �����Ѵ�.
// ���� 1�� 14�� �ؼ� �����Ѵ�
int Royal_Flush(_card player[], int start, int end);		//�ξ� ��Ʈ����Ʈ �÷���	// 10
int Straight_Flush(_card player[], int start, int end);		//��Ʈ����Ʈ �÷���			// 9
int Four_of_a_Kind(_card player[], int start, int end);		//��ī��					// 8
int Full_House(_card player[], int start, int end);			//Ǯ�Ͽ콺					// 7
int Flush(_card player[], int start, int end);				//�÷���					// 6
int Straight(_card player[], int start, int end);			//��Ʈ����Ʈ				// 5
int Three_of_a_Kind(_card player[], int start, int end);	//Ʈ����					// 4
int Two_Pair(_card player[], int start, int end);			//�����					// 3
int One_pair(_card player[], int start, int end);			//�����					// 2
int Top(_card player[], int start, int end);				//�����					// 1

void Print_Card(_card card, int player_num, int times); // ī�� �׸� ��� �Լ�
_card Make_Card(); // �ߺ����� �ʴ� ī�� �� ���� ��ȯ�ϴ� �Լ�
#endif
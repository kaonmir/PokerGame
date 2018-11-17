#ifndef __H_CARD_INCLUDED_
#define __H_CARD_INCLUDED_

#include "Setting.h"
#include "mylib.h"

#define CARD_START_X 6
#define CARD_GAP_X 16
#define CARD_START_Y 10
#define CARD_GAP_Y 2

int card[5][14]; // ī�� �ߺ� üũ

//���� ���� ������
bool Royal_Flush(_card player);		//�ξ� ��Ʈ����Ʈ �÷���
bool Straight_Flush(_card player);	//��Ʈ����Ʈ �÷���
bool Four_of_a_Kind(_card player);	//��ī��
bool Full_House(_card player);		//Ǯ�Ͽ콺
bool Flush(_card player);			//�÷���
bool Straight(_card player);		//��Ʈ����Ʈ
bool Three_of_a_Kind(_card player);	//Ʈ����
bool Two_Pair(_card player);		//�����
bool One_pair(_card player);		//�����
// Top(No_pair)

void Print_Card(_card card, int player_num, int times); // ī�� �׸� ��� �Լ�
_card Make_Card(); // �ߺ����� �ʴ� ī�� �� ���� ��ȯ�ϴ� �Լ�
#endif
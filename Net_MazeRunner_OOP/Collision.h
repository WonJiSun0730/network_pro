#pragma once
#include "stdafx.h"

//////////////////////////////////////
//			Collision.h				//
//									//
//	���� �� �浹üũ�� ����ϴ� �κ���	//
//	��Ƴ��� cpp�Դϴ�.				//
//	1. �÷��̾� to ��(�̷� ����)		//
//	2. �÷��̾� to ��(�ܰ� ����)		//
//	3. �÷��̾� to ������				//
//	4. �÷��̾� to ��(���� ȹ���)	//
//	5. �÷��̾� to ��������			//
//	6. �÷��̾� to ����				//
//	7. �÷��̾� to ��(Ʈ��)			//
//									//
//////////////////////////////////////

void collision(point a, int i, int j);
void collision_sideline(point a, int i, int j);
void collision_item(point a);
void collision_endline(point a);
void collision_ghost(float pos_x, float pos_z);
bool collision_track(point a);
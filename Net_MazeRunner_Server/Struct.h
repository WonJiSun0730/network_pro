#pragma once

//position
struct Position{
	float fX;
	float fY;
	float fZ;

	Position(){}
	Position(float X, float Y, float Z)		//���� ������ ������
		: fX(X), fY(Y), fZ(Z)
	{}
};

//player -> get set �Լ� �ְ� ��ü�� �ٲ� ���� ����
struct Player {
	unsigned int	uiSerialNum;	//������ȣ
	int				iMyTeam;		//�� �Ҽ�

	Position		Pos;			//��ġ��
	float			fAngle;			//ȸ������
	float			DeltaAngle;		//���ۿ���������
	//Position	Vector;	//����
};

//map
struct Maze
{
	int			iStatus;			//ENUM������ ���� �Ӽ��� ��Ÿ��
	float		fEdge[EDGE_END];	//�߾Ӱ� +- �۾� ����...
};
// example
// Maze MyMaze[B_SIZE][B_SIZE]
// if( MyMaze[i][j].iStatus == BLOCK_Empty ) { }...
// MyMaze[i][j].fEdge[EDGE_Right] = 15.f + 3.f;

//ghost

//illuminate
//int iLightRotation;

struct ForPingPong {
	Player PlayerList[PLAYERMAX];
};
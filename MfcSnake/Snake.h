#pragma once

struct Point  // �����ÿһ����
{
	int x;
	int y;
};

class CSnake
{
public:
	CSnake();
	~CSnake(); 
	int len;  // �ߵĳ���
	Point body[1255];  // �ߵ�����
	int direc;   // �˶�����
	void UpMove();  // �����˶�
	void DownMove();  // �����˶� 
	void LeftMove();  // �����˶�
	void RightMove();  // �����˶�
	void init();
};

#include "stdafx.h"
#include "MfcSnake.h"
#include "MfcSnakeDlg.h"
#include "Snake.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

CSnake::CSnake()
{
<<<<<<< HEAD
	// ≥ı ºªØ…ﬂµƒ≥§∂»Œ™1£¨ œÚ”“‘À∂Ø£¨ Õ∑µƒŒª÷√Œ™(10, 10)
	len = 1;
	direc = 4; // …œœ¬◊Û”“1,2,3,4
	body[0].x = 10;
	body[0].y = 10;
=======
	// ≥ı ºªØ…ﬂµƒ≥§∂»Œ™1£¨ œÚ”“‘À∂Ø£¨ Õ∑µƒŒª÷√Œ™(12, 19)
	len = 1;
	direc = 4; // …œœ¬◊Û”“1,2,3,4
	body[0].x = 12;
	body[0].y = 19;
>>>>>>> 78f0edb ('Á¨¨‰∏ÄÊ¨°Êèê‰∫§')
}

CSnake::~CSnake()
{
}

void CSnake::UpMove()
{
	for (int i = len - 1; i > 0; --i) {
		body[i].x = body[i - 1].x;
		body[i].y = body[i - 1].y;
	}
	body[0].x--;
	direc = 1;
}

void CSnake::DownMove()
{
	for (int i = len - 1; i > 0; --i) {
		body[i].x = body[i - 1].x;
		body[i].y = body[i - 1].y;
	}
	body[0].x++;
	direc = 2;
}

void CSnake::LeftMove()
{
	for (int i = len - 1; i > 0; --i) {
		body[i].x = body[i - 1].x;
		body[i].y = body[i - 1].y;
	}
	body[0].y--;
	direc = 3;
}

void CSnake::RightMove()
{
	for (int i = len - 1; i > 0; --i) {
		body[i].x = body[i - 1].x;
		body[i].y = body[i - 1].y;
	}
	body[0].y++;
	direc = 4;
}

void CSnake::init()
{
<<<<<<< HEAD
	body[0].x = 10;
	body[0].y = 10;
=======
	body[0].x = 12;
	body[0].y = 19;
>>>>>>> 78f0edb ('Á¨¨‰∏ÄÊ¨°Êèê‰∫§')
	len = 1;
	direc = 4;
}

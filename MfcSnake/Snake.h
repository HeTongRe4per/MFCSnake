#pragma once

struct Point  // ¾ßÌåµÄÃ¿Ò»¸öµã
{
	int x;
	int y;
};

class CSnake
{
public:
	CSnake();
	~CSnake(); 
	int len;  // ÉßµÄ³¤¶È
	Point body[1255];  // ÉßµÄÉíÌå
	int direc;   // ÔË¶¯·½Ïò
	void UpMove();  // ÏòÉÏÔË¶¯
	void DownMove();  // ÏòÏÂÔË¶¯ 
	void LeftMove();  // Ïò×óÔË¶¯
	void RightMove();  // ÏòÓÒÔË¶¯
	void init();
<<<<<<< HEAD


private:

=======
>>>>>>> 78f0edb ('ç¬¬ä¸€æ¬¡æäº¤')
};

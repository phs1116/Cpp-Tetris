#ifndef __GAMEHANDLER_H__
#define __GAMEHANDLER_H__
#define LEFT 75
#define RIGHT 77
#define UP 72
#define SPACE 32
#include "TetrisBoard.h"
#include <conio.h>


class GameHandler {
private:
	int gamespeed = 1;
	int score = 0;
	TBoard * game;
public:
	GameHandler();
	void GameStart();
	bool GameOver();
	void GameInit();
	bool MoveDown();
	void PressLeft();
	void PressRight();
	void PressUp();
	void PressKey();
	void GameSpeedUp();
	void ShowScore();
};

#endif // !__GAMEHANDLER_H__

/*
Name : TetirsBoard.h
Ver : 0.1

보드 객체의 선언을 위한 헤더파일
*/


#ifndef __TETRISBOARD_H__
#define __TETRISBOARD_H__
#include "Brick.h"
#include "TetrisCommon.h"


#define BW 10 //보드의 너비
#define BH 20 //보드의 길이
#define NW 5
#define NH 5
#define BX 5 // 보드를 그리기 시작할 위치 X좌표
#define BY 1 // 보드를 그리기 시작할 위치 Y좌표


class TBoard{
private:
	int board[BH + 2][BW + 2]; // 위아래 좌우 테두리를 포함.
	int next[NH + 2][NW + 2];
	int nx, ny;// 현재 커서의 위치
	Brick* brick = NULL; // 벽돌 클래스를 포함관계로
	Brick* nextbrick = NULL;
public:
	// 보드 기본 생성자
	TBoard();// board판의 초기화. 테두리일경우 WALL(1)로 초기화, 아닐경우 EMPTY(0)으로 초기화.
	void InitXY(){
		nx = BW / 2;
		ny = 3;
	}
	
	void drawBoard();
	void PrintBrickToBoard(bool Show);

	bool CollisionCheck(int x, int y, int shape, int rot);
	int FullBelowCheck();

	int GetCurrentX() const;

	int ChangeCurrentX(int x);
	int GetCurrentY() const;

	int ChangeCurrentY(int y);
	Brick& GetCurrentBrick() const;
	void ShowNextBrick(bool show) const;
};





#endif // !__TETRISBOARD_H__

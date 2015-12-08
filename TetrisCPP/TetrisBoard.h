/*
Name : TetirsBoard.h
Ver : 0.1

���� ��ü�� ������ ���� �������
*/


#ifndef __TETRISBOARD_H__
#define __TETRISBOARD_H__
#include "Brick.h"
#include "TetrisCommon.h"


#define BW 10 //������ �ʺ�
#define BH 20 //������ ����
#define NW 5
#define NH 5
#define BX 5 // ���带 �׸��� ������ ��ġ X��ǥ
#define BY 1 // ���带 �׸��� ������ ��ġ Y��ǥ


class TBoard{
private:
	int board[BH + 2][BW + 2]; // ���Ʒ� �¿� �׵θ��� ����.
	int next[NH + 2][NW + 2];
	int nx, ny;// ���� Ŀ���� ��ġ
	Brick* brick = NULL; // ���� Ŭ������ ���԰����
	Brick* nextbrick = NULL;
public:
	// ���� �⺻ ������
	TBoard();// board���� �ʱ�ȭ. �׵θ��ϰ�� WALL(1)�� �ʱ�ȭ, �ƴҰ�� EMPTY(0)���� �ʱ�ȭ.
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

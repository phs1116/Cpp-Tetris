#include "TetrisCommon.h"
#include "TetrisBoard.h"
#include "CursurControl.h"


TBoard::TBoard() :nx(BW / 2), ny(3){
	brick = new Brick();
	// board���� �ʱ�ȭ. �׵θ��ϰ�� WALL(1)�� �ʱ�ȭ, �ƴҰ�� EMPTY(0)���� �ʱ�ȭ.
	for (int y = 0; y < BH + 2; y++){
		for (int x = 0; x < BW + 2; x++){
			board[y][x] = (y == 0 || y == BH + 1 || x == 0 || x == BW + 1) ? WALL : EMPTY;
		}
	}

	for (int y = 0; y < NH+2; y++){
		for (int x = 0; x < NW + 2; x++){
			next[y][x] = (y == 0 || y == NH + 1 || x == 0 || x == NW + 1) ? SUB : EMPTY;
		}
	}
}

void TBoard::drawBoard(){
	for (int y = 0; y < BH + 2; y++){
		for (int x = 0; x < BW + 2; x++){
			gotoxy(BX + x * 2, BY + y);
			puts(tile[board[y][x]]);
			//printf("%d", board[y][x]);
		}
	}

	for (int y = 0; y < NH + 2; y++){
		for (int x = 0; x < NW + 2; x++){
			gotoxy(BX + (x+18) * 2, BY + y);
			puts(tile[next[y][x]]);
		}
	}


}

void TBoard::PrintBrickToBoard(bool Show){ // ������ ȭ�鿡 ����
	if (nextbrick == NULL)
		nextbrick = new Brick();
	for (int i = 0; i < 4; i++){
		//���� ��ġ��ǥ + �����ǥ�� �̵�.
		gotoxy(BX + (BrickShape::shape[brick->GetShape()][brick->GetRot()][i].x + nx) * 2, BY + BrickShape::shape[brick->GetShape()][brick->GetRot()][i].y + ny);
		puts(tile[Show ? BRICK : EMPTY]); // ���� : ����
		//printf("%d", Show ? BRICK : EMPTY);
	}
}

bool TBoard::CollisionCheck(int x, int y, int shape, int rot){ //ȸ��, Ȥ�� �̵��� �浹 üũ.
	//�� ���·� ȸ�� or �� ��ġ�� ����������. board[][]�迭�� �̹� BRICK�̳� WALL�� �ִ����� Ȯ��.
	for (int i = 0; i < 4; i++){
		if (board[y + (BrickShape::shape[shape][rot][i].y)][x + (BrickShape::shape[shape][rot][i].x)] != EMPTY){
			return false;
		}
	}
	return true; // ������ �����ҽ� true ��ȯ
}

int TBoard::FullBelowCheck(){



	int x, y, cy, count = 0;
	for (int i = 0; i < 4; i++){
		board[ny + BrickShape::shape[brick->GetShape()][brick->GetRot()][i].y][nx + (BrickShape::shape[brick->GetShape()][brick->GetRot()][i].x)] = BRICK;
	}
	delete brick;

	brick = nextbrick;
	ShowNextBrick(false);
	nextbrick = NULL;

	InitXY();

	//���ٷ� �̾��� ���� �ִ��� �˻�.
	for (y = 1; y < BH + 1; y++){ //y ��ĭ�� ��.
		for (x = 1; x < BW + 1; x++){
			if (board[y][x] != BRICK) break; //���� xù��°�� ������ �ƴϸ� �˻��� �ʿ䰡 ������ �н�
		}
		if (x != BW + 1) continue;
		//������ �̻��� ��������� ���� ĭ���� ������ ��ĭ�� ��ܾ���.
		count++;
		for (cy = y; cy > 1; cy--){
			for (x = 1; x < BW + 1; x++){
				board[cy][x] = board[cy - 1][x];
			}
		}

	}

	return count;

}


int TBoard::GetCurrentX() const{
	return nx;
}

int TBoard::ChangeCurrentX(int x){
	nx += x;
	return nx;
}

int TBoard::GetCurrentY() const{
	return ny;
}

int TBoard::ChangeCurrentY(int y){
	ny += y;
	return ny;
}

Brick& TBoard::GetCurrentBrick() const{
	return *brick;
}

void TBoard::ShowNextBrick(bool Show) const{

	

	for (int i = 0; i < 4; i++){
		//���� ��ġ��ǥ + �����ǥ�� �̵�.
		//if (Show){
		gotoxy(BX + (BrickShape::shape[brick->GetShape()][brick->GetRot()][i].x + 21) * 2, BY + BrickShape::shape[brick->GetShape()][brick->GetRot()][i].y + 3);
			puts(tile[Show ? BRICK : EMPTY]); // ���� : ����
			//printf(Show ?tile[BRICK]:" ");
		}
		//else {
		//	gotoxy(50 + (BrickShape::shape[brick->GetShape()][brick->GetRot()][i].x) * 2, 3 + BrickShape::shape[brick->GetShape()][brick->GetRot()][i].y);
		//	puts("  "); // ����
		//	//printf("%d", Show ? BRICK : EMPTY);
		//}
	
}
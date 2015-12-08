#include "TetrisCommon.h"
#include "TetrisBoard.h"
#include "CursurControl.h"


TBoard::TBoard() :nx(BW / 2), ny(3){
	brick = new Brick();
	// board판의 초기화. 테두리일경우 WALL(1)로 초기화, 아닐경우 EMPTY(0)으로 초기화.
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

void TBoard::PrintBrickToBoard(bool Show){ // 벽돌을 화면에 생성
	if (nextbrick == NULL)
		nextbrick = new Brick();
	for (int i = 0; i < 4; i++){
		//현재 위치좌표 + 상대좌표로 이동.
		gotoxy(BX + (BrickShape::shape[brick->GetShape()][brick->GetRot()][i].x + nx) * 2, BY + BrickShape::shape[brick->GetShape()][brick->GetRot()][i].y + ny);
		puts(tile[Show ? BRICK : EMPTY]); // 생성 : 제거
		//printf("%d", Show ? BRICK : EMPTY);
	}
}

bool TBoard::CollisionCheck(int x, int y, int shape, int rot){ //회전, 혹은 이동시 충돌 체크.
	//이 형태로 회전 or 이 위치로 움직였을때. board[][]배열에 이미 BRICK이나 WALL이 있는지를 확인.
	for (int i = 0; i < 4; i++){
		if (board[y + (BrickShape::shape[shape][rot][i].y)][x + (BrickShape::shape[shape][rot][i].x)] != EMPTY){
			return false;
		}
	}
	return true; // 변경이 가능할시 true 반환
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

	//한줄로 이어진 줄이 있는지 검사.
	for (y = 1; y < BH + 1; y++){ //y 한칸씩 비교.
		for (x = 1; x < BW + 1; x++){
			if (board[y][x] != BRICK) break; //만약 x첫번째가 벽돌이 아니면 검사할 필요가 없으니 패스
		}
		if (x != BW + 1) continue;
		//끝까지 이상이 없었을경우 위의 칸들을 밑으로 한칸씩 당겨야함.
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
		//현재 위치좌표 + 상대좌표로 이동.
		//if (Show){
		gotoxy(BX + (BrickShape::shape[brick->GetShape()][brick->GetRot()][i].x + 21) * 2, BY + BrickShape::shape[brick->GetShape()][brick->GetRot()][i].y + 3);
			puts(tile[Show ? BRICK : EMPTY]); // 생성 : 제거
			//printf(Show ?tile[BRICK]:" ");
		}
		//else {
		//	gotoxy(50 + (BrickShape::shape[brick->GetShape()][brick->GetRot()][i].x) * 2, 3 + BrickShape::shape[brick->GetShape()][brick->GetRot()][i].y);
		//	puts("  "); // 제거
		//	//printf("%d", Show ? BRICK : EMPTY);
		//}
	
}
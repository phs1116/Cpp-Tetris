#include "Brick.h"
#include <random>
#include <ctime>
#include <Windows.h>


Brick::Brick() // 랜덤으로 벽돌을 생성하는 함수. 형태종류와 회전한 수를 랜덤으로 저장.
{
	srand(GetTickCount());
	this->shape = rand() % 6; // 7가지 종류의 형태중에 하나 택일
	this->rot = rand() % 3; // 회전한 4형태중에 하나 택일.
}
int Brick::GetShape() const{
	return shape;
}

int Brick::GetRot() const{
	return rot;
}

void Brick::RotateBrick(){

	rot = (rot + 1 > 3) ? 0 : ++rot;

}
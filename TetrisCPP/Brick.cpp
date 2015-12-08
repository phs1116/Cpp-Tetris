#include "Brick.h"
#include <random>
#include <ctime>
#include <Windows.h>


Brick::Brick() // �������� ������ �����ϴ� �Լ�. ���������� ȸ���� ���� �������� ����.
{
	srand(GetTickCount());
	this->shape = rand() % 6; // 7���� ������ �����߿� �ϳ� ����
	this->rot = rand() % 3; // ȸ���� 4�����߿� �ϳ� ����.
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
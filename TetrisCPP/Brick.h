#ifndef __BRICK_H__
#define __BRICK_H__

class Brick{
private:
	int shape;
	int rot;
public:
	Brick(); // �������� ������ �����ϴ� �Լ�. ���������� ȸ���� ���� �������� ����.
	int GetShape() const;
	int GetRot() const;
	void RotateBrick(); // ���� ȸ����Ų��.
};	




#endif // !__BRICK_H__




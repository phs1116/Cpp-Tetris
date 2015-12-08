#ifndef __BRICK_H__
#define __BRICK_H__

class Brick{
private:
	int shape;
	int rot;
public:
	Brick(); // 랜덤으로 벽돌을 생성하는 함수. 형태종류와 회전한 수를 랜덤으로 저장.
	int GetShape() const;
	int GetRot() const;
	void RotateBrick(); // 블럭을 회전시킨다.
};	




#endif // !__BRICK_H__




#pragma once
#include "GameNode.h"
#include "Flame.h"
#include "Bullets.h"

#define ROCKET_SPEED	3.0f

//������Ƽ�� ����?
class Rocket : public GameNode
{
private:
	my::Image* _image;
	Flame* _flame;

	Missile* _missile;
	MissileM1* _missileM1;
	RECT _rc;
	float _x, _y;

	//������Ƽ��...
	AMissile* _aMissile;
	AMissile* _arrAMissile[5];

public :
	HRESULT init(void);
	void release(void);
	void update(void);
	void render(void);

	//������Ƽ��...
	void setAMissile(int index);
	void fireAMissile(void);

	Rocket() {}
	~Rocket() {}
};


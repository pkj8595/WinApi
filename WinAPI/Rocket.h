#pragma once
#include "GameNode.h"
#include "Flame.h"
#include "Bullets.h"

#define ROCKET_SPEED	3.0f

//스프레티지 패턴?
class Rocket : public GameNode
{
private:
	my::Image* _image;
	Flame* _flame;

	Missile* _missile;
	MissileM1* _missileM1;
	RECT _rc;
	float _x, _y;

	//스프레티지...
	AMissile* _aMissile;
	AMissile* _arrAMissile[5];

public :
	HRESULT init(void);
	void release(void);
	void update(void);
	void render(void);

	//스프레티지...
	void setAMissile(int index);
	void fireAMissile(void);

	Rocket() {}
	~Rocket() {}
};


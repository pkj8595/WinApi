#pragma once
#include "GameNode.h"
#include "Flame.h"
#include "Bullets.h"
#include "ProgressBar.h"

#define ROCKET_SPEED	3.0f

enum EWeapon 
{
	MISSILE,BEAM
};

//스프레티지 패턴?
//심는다는게 무슨말 ? 
//Manager 옵저버로 매니저 
class Rocket : public GameNode
{
private:
	my::Image* _image;
	Flame* _flame;
	MissileM1* _missileM1;
	Beam* _beam;
	EWeapon _setWeapon;

	RECT _rc;
	float _x, _y;

	ProgressBar* _hpBar;
	float _currentHp;
	float _maxHp;

	bool _beamIrradiation;

	//스프레티지...
	AMissile* _aMissile;		//실질적으로 쓰이는 미사일
	AMissile* _arrAMissile[5];	//마사일 창고

public :
	HRESULT init(void);
	void release(void);
	void update(void);
	void render(void);

	void removeMissile(int arrNum);
	MissileM1* getMissile(void) { return _missileM1; }
	Beam* getBeam(void) { return _beam; }
	RECT getRect(void) { return _rc; }

	//test
	inline void hitDamage(float damage) 
	{
		if (_currentHp <= 0) 
		{
			_currentHp = 0; 
			return;
		}
		_currentHp -= damage;
	}

	//스프레티지...
	void setAMissile(int index);
	void fireAMissile(void);

	Rocket() {}
	~Rocket() {}
};


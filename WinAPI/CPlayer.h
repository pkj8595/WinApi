#pragma once
class CPlayer
{
private:
	enum EState
	{
		IDLE=0,
		MOVE,
		ATTACK,
		DEFFENCE,
	};

	EState _state;
	RECT _rc;
	RECT _hitBox;
	bool _isLeft;

	int _maxHp;
	int _hp;
	int _speed;
	int _damage;

public:
	EState getState() { return _state; }
	RECT getRC() { return _rc; }
	RECT getHitBox() { return _hitBox; }
	int getHp() { return _hp; }
	int getSpeed() { return _speed; }
	int getDamage() { return _damage; }

	void setState(EState state) { _state = state; }
	void setRC(RECT rc) { _rc = rc; }
	void setHitBox(RECT hitBox) { _hitBox = hitBox; }
	void setSpeed(int speed) { _speed = speed; }
	void setHp(int hp) { _hp = hp; }
	void setMaxHp(int maxhp) { _maxHp = maxhp; }
	void setDamage(int damage) { _damage = damage; }

	void beAttacked(int damage) { _hp -= damage; }


	CPlayer():_state(IDLE),_maxHp(100),_hp(100),_speed(3),_damage(10){}
	~CPlayer() {}
};


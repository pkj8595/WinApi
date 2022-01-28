#pragma once
class CShapePlayer
{
private:
	
	Gdiplus::RectF _rc;
	Gdiplus::RectF _dashRc;
	Matrix	_mPlayer;

	POINT _pt;
	POINT _previousPt;
	float _angle;
	long _dashTime;
	int _dashSpeed;
	int _speed;
	int _maxHp;
	int _hp;
	bool _isMove;
	bool _isDash;
	//Gdiplus::Matrix _m;

public:
	//EState getState() { return _state; }
	RectF getRC() { return _rc; }
	RectF getDashRC() { return _dashRc; }
	int getHp() { return _hp; }
	int getSpeed() { return _speed; }
	float getAngle() { return _angle; }
	POINT getPoint() { return _pt; }

	//void setState(EState state) { _state = state; }
	void setRC(RectF rc) { _rc = rc; }
	void setSpeed(int speed) { _speed = speed; }
	void setHp(int hp) { _hp = hp; }
	void setMaxHp(int maxhp) { _maxHp = maxhp; }

	void beAttacked(int damage) { _hp -= damage; }

	void update(int time);
	void render(Gdiplus::Graphics &g);


	CShapePlayer() :_isMove(false), _maxHp(5), _hp(4), _speed(8),_pt(PointMake(100,WINSIZE_Y/2)), _angle(0), _rc(RectF(-10,-10,20,20)),_dashRc(RectF(0,0,0,0)), _isDash(false){}
	~CShapePlayer() {}
};


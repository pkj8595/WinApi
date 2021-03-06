#pragma once
#include "GameNode.h"
#include "IRectObserved.h"


//Enemy (기반클래스) : 이 클래스를 기반으로 일반 몬스터들을 만든다고 했을때 문제가 없는지 생각
/*
	코드적 추상화 
	충돌, draw, 확장성,
	hp를 안만드는 이유 : 전투가 일어나기도 전에 필요없는 메모리를 잡아먹기 때문에 전투 할 때만 있으면 된다.
*/

class Enemy : public GameNode, public IRectObserved
{
protected:
	my::Image* _image;
	RECT _rc;
	int _currentFrameX;
	int _currentFrameY;

	float _x, _y;
	float _rndTimeCount;
	float _worldTimeCount;

	float _bulletFireCount;
	float _rndFireCount;

	ObservedType _type;
	bool _isActive;
public:
	virtual HRESULT init(void);
	virtual HRESULT init(const char* imageName, POINT position);
	virtual void release(void);
	virtual void update(void);
	virtual void render(void);

	virtual void move(void);
	virtual void draw(void);
	virtual void animation(void);

	bool bulletCountFire(void);

	RECT getRect(void) { return _rc; }
	bool getIsActive(void) { return _isActive; }

	virtual STObservedData getRectUpdate();
	virtual void collideObject();

	Enemy(void);
	virtual ~Enemy(void) {}
};


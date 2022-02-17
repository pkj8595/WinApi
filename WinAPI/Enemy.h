#pragma once
#include "GameNode.h"
#include "IRectObserved.h"


//Enemy (���Ŭ����) : �� Ŭ������ ������� �Ϲ� ���͵��� ����ٰ� ������ ������ ������ ����
/*
	�ڵ��� �߻�ȭ 
	�浹, draw, Ȯ�强,
	hp�� �ȸ���� ���� : ������ �Ͼ�⵵ ���� �ʿ���� �޸𸮸� ��ƸԱ� ������ ���� �� ���� ������ �ȴ�.
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


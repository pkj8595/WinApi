#pragma once
#include "GameNode.h"

//Enemy (���Ŭ����) : �� Ŭ������ ������� �Ϲ� ���͵��� ����ٰ� ������ ������ ������ ����
/*
	�ڵ��� �߻�ȭ 
	�浹, draw, Ȯ�强,
	hp�� �ȸ���� ���� : ������ �Ͼ�⵵ ���� �ʿ���� �޸𸮸� ��ƸԱ� ������ ���� �� ���� ������ �ȴ�.
*/
class Enemy : public GameNode
{
protected:
	my::Image* _image;
	RECT _rc;
	int _currentFrameX;
	int _currentFrameY;

	float _x, _y;
	float _rndTimeCount;
	float _worldTimeCount;


public:
	virtual HRESULT init(void);
	virtual HRESULT init(const char* imageName, POINT position);
	virtual void release(void);
	virtual void update(void);
	virtual void render(void);

	virtual void move(void);
	virtual void draw(void);
	virtual void animation(void);

	Enemy(void);
	virtual ~Enemy(void) {}
};


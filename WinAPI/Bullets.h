#pragma once
#include "GameNode.h"

#define FLAME_COUNT		4.0f

struct tagBullet 
{
	my::Image* img;
	RECT rc;
	int radius;
	int count;
	float x, y;
	float fireX, fireY;
	float angle;
	float speed;
	bool fire;
	//float flameTick;
};

/*
�ǽ� �� ���� 1. ���� ���� �����߰�
f1 : �Ϲ� �̻���
f2 : ��ź
f3 : �̴� ���� ����
f4 : �ǵ�
f5 : �����̻���
f6 : ������
f7 : ��Ȧ

���� 2 �� ������ ����
-������ ��ü�� ���� �ٸ��� �������� �Ѵ�.
*/

//�迭ó�� �̸� �����صΰ� �߻�
class Missile : public GameNode
{
private:
	vector<tagBullet> _vBullet;
	vector<tagBullet>::iterator _viBullet;

	int _bulletMax;
	float _range;

public:
	HRESULT init(int bulletMax, float range);
	void release(void);
	void update(void);
	void render(void);

	void fire(float x, float y);
	void draw(void);
	void move(void);

	Missile() {}
	~Missile() {}
};

//�򶧸��� ����� ����
class MissileM1 : public GameNode
{	
private:
	vector<tagBullet> _vBullet;
	vector<tagBullet>::iterator _viBullet;

	float _range;
	int _bulletMax;

public:
	HRESULT init(int bulletMax, float range);
	void release(void);
	void update(void);
	void render(void);

	void fire(float x, float y);
	void draw(void);
	void move(void);

	MissileM1() {}
	~MissileM1() {}
};

//�߻� �̻���
class AMissile : public GameNode
{
protected:
	vector<tagBullet> _vBullet;
	vector<tagBullet>::iterator _viBullet;

	float _range;
	int _bulletMax;

public:
	virtual HRESULT init(int bulletMax, float range);
	virtual void release(void);
	virtual void update(void);
	virtual void render(void);

	virtual void fire(float x, float y);
	virtual void draw(void);
	virtual void move(void);
	virtual void isRange(void);

	AMissile() {}
	virtual ~AMissile() {}
};

class CaseShotMissile : public AMissile
{
private:
	int _bulletCount;
	float _firstAngle;
	const float _offsetAngle = 0.1;

public:
	virtual HRESULT init(int bulletMax, float range);
	virtual void move(void);
	virtual void fire(float x, float y);
};


class BlackholeMissile : public AMissile 
{
private:

public:
	virtual HRESULT init(int bulletMax, float range);
	virtual void move(void);
	virtual void fire(float x, float y);
};
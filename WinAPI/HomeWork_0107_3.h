#pragma once

#define _USE_MATH_DEFINES // �޽� ���� ��ƾ���
#include <math.h>

// 9.8m/s^2
//0.98/0.s^2


typedef struct tagCostomFloatPoint0110
{
	float x;
	float y;
} FLOAT_POINT1;

struct tagBullet3
{
	FLOAT_POINT1 pt;
	int radius;
	bool isFire = false;
	float angle;
	int xDir;
	int yDir;
	float airResidenceTime;		//����ü���ð�
	bool isAirResidence;		//����ü������
};

struct tagCannon3
{
	POINT center;
	POINT cannonEnd;
	float angle;
	float cannonAngleStart;
	float cannonAngleEnd;
	int radius;
	int length;
	bool dir;				//����
};

class HomeWork_0107_3 : public Scene_inter
{
private:

	tagCannon3 _cannon;
	tagBullet3 _bullet[60];
	SYSTEMTIME _st;
	int _count;
	float _gravity;

public:
	virtual HRESULT init(void);
	virtual void release(void);
	virtual void update(void);
	virtual void render(HDC hdc);

	void fire(void);

};


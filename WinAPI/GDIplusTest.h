#pragma once
#include "GameNode.h"
#include "CShapePlayer.h"
#include "CBlock.h"
//using namespace Gdiplus;
#define BLOCK_SIZE		10

class GDIplusTest : public GameNode
{
private:
	CShapePlayer _cplayer;
	CBlock _block[BLOCK_SIZE];

	Gdiplus::Rect _rc;
	DWORD	_time;
	DWORD	_timeStart;

	Matrix	_m;
	PointF	_posi;
	PointF	_pt;
	float	_angle;

	RectF _topRc;
	RectF _downRc;

	float _count;
	bool _gameStop;

public:
	virtual HRESULT init(void);
	virtual void release(void);
	virtual void update(void);
	virtual void render(HDC hdc);


	GDIplusTest() {}
	~GDIplusTest() {}


};


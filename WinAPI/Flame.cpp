#include "Stdafx.h"
#include "Flame.h"

Flame::Flame()
{
}

Flame::~Flame()
{
}

HRESULT Flame::init(void)
{
	IMAGEMANAGER->addFrameImage("ºÒ²É","Resource/Images/Rocket/Flame.BMP",437,297,9,1,true,RGB(255,0,255));
	_frameX = 0;
	_time = 0;
	_rc = RectMake(0,0,0,0);

	return S_OK;
}

void Flame::release(void)
{
}

void Flame::update(void)
{
	_time++;
	if (_time % 5 ==0) 
	{
		_frameX++;
		if (_frameX == 9)_frameX = 0;
	}
}

void Flame::render(void)
{
	IMAGEMANAGER->frameRender("ºÒ²É",getMemDC(), _rc.left,_rc.top, _frameX,1);
}


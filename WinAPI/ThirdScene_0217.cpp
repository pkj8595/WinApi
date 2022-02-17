#include "Stdafx.h"
#include "ThirdScene_0217.h"

HRESULT ThirdScene_0217::init(void)
{
	IMAGEMANAGER->addImage("배경3", "Resource/Images/Background/BackgroundSample2.bmp", WINSIZE_X, WINSIZE_Y);
	_img = IMAGEMANAGER->findImage("공룡1");
	_x = CENTER_X;
	_y = CENTER_Y + 400;
	_isRight = true;
	_rc = RectMakeCenter(_x, _y, _img->getFrameWidth(), _img->getFrameWidth());
	_hp = 10;

	_hpBar = new ProgressBar;
	_hpBar->init(_x, _y, 50, 10);
	_previousTime = 0;

	return S_OK;
}

void ThirdScene_0217::release(void)
{
	//_hpBar->release();
}

void ThirdScene_0217::update(void)
{
	_hpBar->setGauge(_hp, 10);
	_hpBar->setX(_x);
	_hpBar->setY(_y - 120);
	_hpBar->update();

	if (static_cast<int>(TIMEMANAGER->getWorldTime()) != _previousTime) 
	{
		_previousTime =static_cast<int>(TIMEMANAGER->getWorldTime());
		_hp--;
		if (_hp < 0) 
		{
			SCENEMANAGER->changeScene("StartScene_0217");
		}
	}
	if (KEYMANAGER->isStayKeyDown(VK_LEFT))
	{
		_x -= 4;
		_isRight = false;
	}
	if (KEYMANAGER->isStayKeyDown(VK_RIGHT))
	{
		_x += 4;
		_isRight = true;
	}
	_rc = RectMakeCenter(_x, _y, _img->getFrameWidth(), _img->getFrameWidth());
}

void ThirdScene_0217::render(void)
{
	IMAGEMANAGER->render("배경3", getMemDC());
	_img->frameRender(getMemDC(), _rc.left, _rc.top, _isRight, 0);
	_hpBar->render();
}

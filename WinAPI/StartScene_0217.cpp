#include "Stdafx.h"
#include "StartScene_0217.h"

HRESULT StartScene_0217::init(void)
{
	IMAGEMANAGER->addImage("배경1", "Resource/Images/Background/bk_2017.bmp", WINSIZE_X, WINSIZE_Y);
	_img = IMAGEMANAGER->addFrameImage("공룡1", "Resource/Images/Object/dino.bmp", 300, 110, 2, 1, true , RGB(255,0,255));

	_x = CENTER_X;
	_y = CENTER_Y+400;
	_isRight = true;
	_rc = RectMakeCenter(_x, _y, _img->getFrameWidth(), _img->getFrameWidth());

	return S_OK;
}

void StartScene_0217::release(void)
{
}

void StartScene_0217::update(void)
{
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
	if (_x> WINSIZE_X) 
	{
		SCENEMANAGER->changeScene("SecondScene_0217");
	}

	_rc = RectMakeCenter(_x, _y, _img->getWidth(), _img->getHeight());

}

void StartScene_0217::render(void)
{
	IMAGEMANAGER->render("배경1", getMemDC());
	_img->frameRender(getMemDC(), _rc.left, _rc.top, _isRight, 0);
}

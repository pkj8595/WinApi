#include "Stdafx.h"
#include "Rocket.h"

HRESULT Rocket::init(void)
{
	_image = IMAGEMANAGER->addImage("╥ндо", "Resource/Images/Rocket/Rocket.BMP", 52 , 64 , true, RGB(255,0,255));
	_flame.init();
	_x = CENTER_X;
	_y = CENTER_Y;

	_rc = RectMakeCenter(_x, _y,_image->getWidth(), _image->getHeight());

	return S_OK;
}

void Rocket::release(void)
{
}

void Rocket::update(void)
{
	_flame.update();
	if (KEYMANAGER->isStayKeyDown(VK_RIGHT) && _rc.right < WINSIZE_X) 
	{
		_x += ROCKET_SPEED;
	}
	if (KEYMANAGER->isStayKeyDown(VK_LEFT) && _rc.left > 0) 
	{
		_x -= ROCKET_SPEED;
	}
	if (KEYMANAGER->isStayKeyDown(VK_UP) && _rc.top > 0) 
	{
		_y -= ROCKET_SPEED;
	}
	if (KEYMANAGER->isStayKeyDown(VK_DOWN) && _rc.bottom < WINSIZE_Y) 
	{
		_y += ROCKET_SPEED;
	}

	_rc = RectMakeCenter(_x, _y, _image->getWidth(), _image->getHeight());
	_flame.setRc(RectMake(_rc.left,_rc.bottom,0,0));

	if (KEYMANAGER->isOnceKeyDown(VK_SPACE)) 
	{

	}

}

void Rocket::render(void)
{
	_image->render(getMemDC(),_rc.left,_rc.top);
	_flame.render();
}

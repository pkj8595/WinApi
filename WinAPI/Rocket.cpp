#include "Stdafx.h"
#include "Rocket.h"

HRESULT Rocket::init(void)
{
	_image = IMAGEMANAGER->addImage("로켓", "Resource/Images/Rocket/Rocket.BMP", 52 , 64 , true, RGB(255,0,255));
	IMAGEMANAGER->addFrameImage("미사일", "Resource/Images/Rocket/Missile.BMP", 0.0f, 0.0f, 416, 64, 13, 1, true, RGB(255, 0, 255));

	_x = CENTER_X;
	_y = WINSIZE_Y-100;

	_rc = RectMakeCenter(_x, _y,_image->getWidth(), _image->getHeight());

	_flame = new Flame;
	_flame->init("Flame.bmp", &_x, &_y);

	_missile = new Missile;
	_missile->init(5, 700);

	_missileM1 = new MissileM1;
	_missileM1->init(5, 700);

	_aMissile = nullptr;
	ZeroMemory(&_arrAMissile, sizeof(_arrAMissile));
	_arrAMissile[0] = new CaseShotMissile;


	return S_OK;
}

void Rocket::release(void)
{
	_flame->release();
	SAFE_DELETE(_flame);

	_missile->release();
	SAFE_DELETE(_missile);
	_missileM1->release();
	SAFE_DELETE(_missileM1);

	if (_aMissile != nullptr) _aMissile->release();
	SAFE_DELETE(_aMissile);
}

void Rocket::update(void)
{
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

	if (KEYMANAGER->isOnceKeyDown(VK_SPACE)) 
	{
		fireAMissile();
	}
	//Missile
	if (KEYMANAGER->isOnceKeyDown('Q'))
	{
		_missile->fire(_x, _y-60);
	}
	//MissileM1
	if (KEYMANAGER->isOnceKeyDown('W'))
	{
		_missileM1->fire(_x, _y-60);
	}
	//AMissile
	if (KEYMANAGER->isOnceKeyDown('1'))
	{
		setAMissile(0);
	}

	_flame->update();
	_missile->update();
	_missileM1->update();
	if(_aMissile != nullptr) _aMissile->update();

}

void Rocket::render(void)
{
	_image->render(getMemDC(),_rc.left,_rc.top);
	_flame->render();
	_missile->render();
	_missileM1->render();
	if (_aMissile != nullptr) _aMissile->render();
}


void Rocket::setAMissile(int index)
{
	if (_arrAMissile[index] == nullptr) return;
	_aMissile = _arrAMissile[index];
	_aMissile->init(10, 700);
}

void Rocket::fireAMissile(void)
{
	if (_aMissile == nullptr) return;
	//cout << "Rocket::fireAMissile" << endl;
	_aMissile->fire(_x, _y - 60);
}

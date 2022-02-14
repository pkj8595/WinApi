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

	_missileM1 = new MissileM1;
	_missileM1->init(5, 700);
	
	_beam = new Beam;
	_beam->init(1, 0.5f);
	_beamIrradiation = false;
	_setWeapon = MISSILE;


	_currentHp = 10;
	_maxHp = 10;

	_hpBar = new ProgressBar;
	_hpBar->init(_x,_y, _rc.right-_rc.left,10);


	_aMissile = nullptr;
	ZeroMemory(&_arrAMissile, sizeof(_arrAMissile));
	_arrAMissile[0] = new CaseShotMissile;

	return S_OK;
}

void Rocket::release(void)
{
	_flame->release();
	SAFE_DELETE(_flame);

	_missileM1->release();
	SAFE_DELETE(_missileM1);

	_beam->release();
	SAFE_DELETE(_beam);

	_hpBar->release();
	SAFE_DELETE(_hpBar);

	if (_aMissile != nullptr) _aMissile->release();
	SAFE_DELETE(_aMissile);
}

void Rocket::update(void)
{
	if (KEYMANAGER->isStayKeyDown(VK_RIGHT) && _rc.right < WINSIZE_X &&_beamIrradiation == false) 
	{
		_x += ROCKET_SPEED;
	}
	if (KEYMANAGER->isStayKeyDown(VK_LEFT) && _rc.left > 0 && _beamIrradiation == false)
	{
		_x -= ROCKET_SPEED;
	}

	_rc = RectMakeCenter(_x, _y, _image->getWidth(), _image->getHeight());
	if (KEYMANAGER->isOnceKeyDown(VK_F1))
	{
		_setWeapon = MISSILE;
	}
	if (KEYMANAGER->isOnceKeyDown(VK_F2))
	{
		_setWeapon = BEAM;
	}

	

	switch (_setWeapon)
	{
	case MISSILE:
		if (KEYMANAGER->isOnceKeyDown('E'))
		{
			_missileM1->fire(_x, _y - 60);
		}
		break;
	case BEAM:
		if (KEYMANAGER->isStayKeyDown('E'))
		{
			_beamIrradiation = true;
			_beam->fire(_x, _y - 430);
			
		}
		else _beamIrradiation = false; 
		break;
	default:
		break;
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
	if (KEYMANAGER->isOnceKeyDown(VK_SPACE))
	{
		fireAMissile();
	}

	_flame->update();
	_beam->update();
	_missileM1->update();

	_hpBar->setX(_x - (_rc.right - _rc.left) / 2);
	_hpBar->setY(_y -10- (_rc.bottom - _rc.top) / 2);
	_hpBar->update();

	if(_aMissile != nullptr) _aMissile->update();

}

void Rocket::render(void)
{
	_image->render(getMemDC(),_rc.left,_rc.top);
	_flame->render();
	_beam->render();
	_missileM1->render();

	_hpBar->render();
	if (_aMissile != nullptr) _aMissile->render();
}

void Rocket::removeMissile(int arrNum)
{
	_missileM1->removeBullet(arrNum);
}


//================================
// ### AMissile ###
//================================
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

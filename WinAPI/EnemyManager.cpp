#include "Stdafx.h"
#include "EnemyManager.h"
#include "Minion.h"

EnemyManager::EnemyManager(){
	//DO NOTTING
}

EnemyManager::~EnemyManager(){
	//DO NOTTING
}

HRESULT EnemyManager::init(void)
{
	IMAGEMANAGER->addFrameImage("해파리", "Resource/Images/Rocket/jelly.bmp", 0.0f, 0.0f, 1140, 47, 19, 1, true, RGB(255, 0, 255));

	//미니언 생성
	setMinion();

	return S_OK;
}

void EnemyManager::release(void)
{
	for (_viMinion = _vMinion.begin(); _viMinion != _vMinion.end(); ++_viMinion) 
	{
		//역참조하니까 되는 이유?
		(*_viMinion)->release();
		SAFE_DELETE(*_viMinion);
	}
}

void EnemyManager::update(void)
{
	_viMinion = _vMinion.begin();
	for (;_viMinion != _vMinion.end(); ++_viMinion) 
	{
		(*_viMinion)->update();
	}
}

void EnemyManager::render(void)
{
	_viMinion = _vMinion.begin();
	for (; _viMinion != _vMinion.end(); ++_viMinion)
	{
		(*_viMinion)->render();
	}
}

void EnemyManager::setMinion(void)
{
	for (int i = 0; i < 3; i++)
	{
		for (int  j = 0; j < 10; j++)
		{
			Enemy* jellyFish;
			jellyFish = new Minion;
			jellyFish->init("해파리", PointMake(250 + j * 50, 100 + i * 100));
			_vMinion.push_back(jellyFish);

		}
	}
}


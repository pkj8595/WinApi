#include "Stdafx.h" 
#include "MainGame.h"


HRESULT MainGame::init(void)
{	
	GameNode::init(TRUE);
	_isGameStop = false;
	//IMAGEMANAGER->addImage("½´ÆÃ¸Ê", "Resource/Images/Rocket/ShootingBG.bmp", WINSIZE_X, WINSIZE_Y);
	IMAGEMANAGER->addImage("½´ÆÃ¸Ê", "Resource/Images/Rocket/battlefield.bmp", 600, 1830);

	
	_rocket = new Rocket;
	_rocket->init();

	_em = new EnemyManager;
	_em->init();

	_ani = new AniTestScene;
	_ani->init();

	_x = _y = 0.0f;

	//_tileMap = new Tilemap;
	//_tileMap->init(TILE_MAP_SIZE);

	return S_OK;
}

void MainGame::release(void)
{
	GameNode::release();

	_rocket->release();
	SAFE_DELETE(_rocket);
	_em->release();
	SAFE_DELETE(_em);


	_ani->release();

	//_tileMap->release();
}

void MainGame::update(void)
{
	if (KEYMANAGER->isOnceKeyDown(VK_F10)) _isGameStop = !_isGameStop;
	if (_isGameStop) return;
	GameNode::update();
	_rocket->update();
	_em->update();
	_ani->update();

	RECTOBSERVERMANAGER->getRectFromObserved();

	_y -= 5;

	//_tileMap->update();
	collision();

}

void MainGame::render(void)
{
	PatBlt(getMemDC(), 0,0,WINSIZE_X,WINSIZE_Y,BLACKNESS);
	//IMAGEMANAGER->findImage("½´ÆÃ¸Ê")->render(getMemDC());
	RECT rc = { 0,0,WINSIZE_X,WINSIZE_Y };
	IMAGEMANAGER->findImage("½´ÆÃ¸Ê")->loopRender(getMemDC(),&rc,_x,_y);

	//_tileMap->render();
	_rocket->render();
	_em->render();
	_ani->render();


	TIMEMANAGER->render(getMemDC());

	this->getBackBuffer()->render(getHDC());
}



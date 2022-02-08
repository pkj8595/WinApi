#include "Stdafx.h" 
#include "MainGame.h"


HRESULT MainGame::init(void)
{	
	GameNode::init(TRUE);

	IMAGEMANAGER->addImage("½´ÆÃ¸Ê", "Resource/Images/Rocket/ShootingBG.bmp", WINSIZE_X, WINSIZE_Y);
	_rocket = new Rocket;
	_rocket->init();

	_em = new EnemyManager;
	_em->init();


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

	//_tileMap->release();
}

void MainGame::update(void)
{
	GameNode::update();

	_rocket->update();
	//_tileMap->update();
	_em->update();

}

void MainGame::render(void)
{
	PatBlt(getMemDC(), 0,0,WINSIZE_X,WINSIZE_Y,BLACKNESS);
	IMAGEMANAGER->findImage("½´ÆÃ¸Ê")->render(getMemDC());

	_rocket->render();
	//_tileMap->render();
	_em->render();


	this->getBackBuffer()->render(getHDC());
}


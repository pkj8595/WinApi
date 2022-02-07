#include "Stdafx.h" 
#include "MainGame.h"


HRESULT MainGame::init(void)
{	
	GameNode::init(TRUE);

	IMAGEMANAGER->addImage("½´ÆÃ¸Ê", "Resource/Images/Rocket/ShootingBG.bmp", WINSIZE_X, WINSIZE_Y);
	_rocket = new Rocket;
	_rocket->init();

	return S_OK;
}

void MainGame::release(void)
{
	GameNode::release();

	_rocket->release();
	SAFE_DELETE(_rocket);

}

void MainGame::update(void)
{
	GameNode::update();

	_rocket->update();

}

void MainGame::render(void)
{
	PatBlt(getMemDC(), 0,0,WINSIZE_X,WINSIZE_Y,BLACKNESS);
	IMAGEMANAGER->findImage("½´ÆÃ¸Ê")->render(getMemDC());
	_rocket->render();

	this->getBackBuffer()->render(getHDC());
}


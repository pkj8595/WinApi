#include "Stdafx.h" 
#include "MainGame.h"
#include "ShootingScene.h"
#include "StartScene.h"
#include "PixelScene.h"
#include "StartScene_0217.h"
#include "SecondScene_0217.h"
#include "ThirdScene_0217.h"


HRESULT MainGame::init(void)
{
	GameNode::init(TRUE);

	//SCENEMANAGER->addScene("½´ÆÃ", new ShootingScene);
	//SCENEMANAGER->addScene("½ÃÀÛ", new StartScene);
	//SCENEMANAGER->addScene("ÇÈ¼¿Ãæµ¹", new PixelScene);
	//SCENEMANAGER->changeScene("ÇÈ¼¿Ãæµ¹");

	SCENEMANAGER->addScene("StartScene_0217", new StartScene_0217);
	SCENEMANAGER->addScene("SecondScene_0217", new SecondScene_0217);
	SCENEMANAGER->addScene("ThirdScene_0217", new ThirdScene_0217);
	SCENEMANAGER->changeScene("StartScene_0217");


	return S_OK;
}

void MainGame::release(void)
{
	GameNode::release();
}

void MainGame::update(void)
{
	SCENEMANAGER->update();
}

void MainGame::render(void)
{
	PatBlt(getMemDC(), 0, 0, WINSIZE_X, WINSIZE_Y, BLACKNESS);

	SCENEMANAGER->render();
	TIMEMANAGER->render(getMemDC());

	this->getBackBuffer()->render(getHDC());
}

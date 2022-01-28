#include "Stdafx.h" 
#include "MainGame.h"

#include "GameClass_0103.h"
#include "HomeWork_0103_1.h"
#include "HomeWork_0103_2.h"
#include "GameClass_0104.h"
#include "HomeWork_0104.h"
#include "rotateRect.h"
#include "HomeWork_0107_1.h"
#include "HomeWork_0107_2.h"
#include "HomeWork_0107_3.h"
#include "HomeWork_0107_4.h"
#include "HomeWork_0111.h"


HRESULT MainGame::init(void)
{	
	//Resource/mycustom::Image/Background
	GameNode::init(TRUE);
	////push scene
	//_scene.push_back(new GameClass_0103());
	//_scene.push_back(new GameClass_0104());
	//_scene.push_back(new HomeWork_0103_1());
	//_scene.push_back(new HomeWork_0103_2());
	//_scene.push_back(new HomeWork_0104());
	//_scene.push_back(new rotateRect());		//사각형돌리기
	//_scene.push_back(new HomeWork_0107_1);	//자동포탑
	//_scene.push_back(new HomeWork_0107_2);	//원 충돌
	//_scene.push_back(new HomeWork_0107_3);	//중력
	//_scene.push_back(new HomeWork_0107_4);	//지렁이? // 미구현
	//_scene.push_back(new HomeWork_0111);	//사각형 원 충돌
	//_scene.at(SCENE_KEY)->init();

	/*_start = new StartScene;
	_start->init();

	_second = new SecondScene;
	_second->init();

	_homework_0120 = new HomeWork_0120;
	_homework_0120->init();*/

	_gditestScene = new GDIplusTest;
	_gditestScene->init();


	_currentScene = _gditestScene;
	assert(_currentScene != nullptr);
	

	return S_OK;
}


void MainGame::release(void)
{
	GameNode::release();
	SAFE_DELETE(_start);
	SAFE_DELETE(_second);
	SAFE_DELETE(_homework_0120);
	SAFE_DELETE(_gditestScene);
	//_scene.at(SCENE_KEY)->release();
}

void MainGame::update(void)
{
	GameNode::update();
	//_scene.at(SCENE_KEY)->update();

	_currentScene->update();

	/*if (KEYMANAGER->isOnceKeyDown(VK_RETURN))
	{
		cout << "_currentScene = _start" << endl;
		_currentScene = _homework_0120;
	}

	if (KEYMANAGER->isOnceKeyDown('1'))
	{
		cout << "_currentScene = _start" << endl;
		_currentScene = _start;
	}
	if (KEYMANAGER->isOnceKeyDown('2'))
	{
		cout << "_currentScene = _second" << endl;
		_currentScene = _second;
	}*/
	

}

void MainGame::render(HDC hdc)
{
	//_scene.at(SCENE_KEY)->render(hdc);
	PatBlt(getMemDC(), 0,0,WINSIZE_X,WINSIZE_Y,BLACKNESS);
	_currentScene->render(hdc);
	

	this->getBackBuffer()->render(getHDC());
}


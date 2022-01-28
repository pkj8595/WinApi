#pragma once
#include "GameNode.h"
//=========================
#include "StartScene.h"
#include "SecondScene.h"
#include "HomeWork_0120.h"
#include "GDIplusTest.h"
//============================

#define _USE_MATH_DEFINES // 메스 위에 잡아야함
#include "math.h"

//자동포탑			6
//원 충돌			7
//중력				8
//지렁이? // 미구현	9	
//사각형 원 충돌		10
#define SCENE_KEY	10

//class mycustom::Image;

//프로젝트의 대리자 
class MainGame : public GameNode
{
private:

	//vector<Scene_inter*> _scene;

	StartScene* _start;
	SecondScene* _second;
	HomeWork_0120* _homework_0120;


	GameNode* _currentScene;
	GDIplusTest* _gditestScene;


public:
	virtual HRESULT init(void);
	virtual void release(void);
	virtual void update(void);		
	virtual void render(HDC hdc);


	MainGame() :_currentScene(nullptr) {}
	virtual ~MainGame() {}
};
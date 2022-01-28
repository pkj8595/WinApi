#pragma once
#include "GameNode.h"
//=========================
#include "StartScene.h"
#include "SecondScene.h"
#include "HomeWork_0120.h"
#include "GDIplusTest.h"
//============================

#define _USE_MATH_DEFINES // �޽� ���� ��ƾ���
#include "math.h"

//�ڵ���ž			6
//�� �浹			7
//�߷�				8
//������? // �̱���	9	
//�簢�� �� �浹		10
#define SCENE_KEY	10

//class mycustom::Image;

//������Ʈ�� �븮�� 
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
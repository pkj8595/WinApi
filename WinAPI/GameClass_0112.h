#pragma once
#include "MainGame.h"
class GameClass_0112 : public MainGame
{
public:

	int _alphaA, _alphaNum;

public:
	virtual HRESULT init(void);
	virtual void release(void);
	virtual void update(void);	//�ﰢ�Լ��� update�� �߿�	

	virtual void render();
	GameClass_0112() {}
	~GameClass_0112() {}
};


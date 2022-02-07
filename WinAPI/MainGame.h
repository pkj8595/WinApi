#pragma once
#include "GameNode.h"
#include "Rocket.h"
#define _USE_MATH_DEFINES // 메스 위에 잡아야함
#include "math.h"


class MainGame : public GameNode
{
private:
	Rocket* _rocket;

public:
	virtual HRESULT init(void);
	virtual void release(void);
	virtual void update(void);		
	virtual void render(void);

	MainGame() {}
	virtual ~MainGame() {}
};
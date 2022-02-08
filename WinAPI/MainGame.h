#pragma once
#include "GameNode.h"
#include "Rocket.h"
#include "Tilemap.h"
#include "EnemyManager.h"

#define _USE_MATH_DEFINES
#include "math.h"

#define TILE_MAP_SIZE		25

class MainGame : public GameNode
{
private:
	Rocket* _rocket;
	EnemyManager* _em;
	//Tilemap* _tileMap;

public:
	virtual HRESULT init(void);
	virtual void release(void);
	virtual void update(void);		
	virtual void render(void);

	MainGame() {}
	virtual ~MainGame() {}
};
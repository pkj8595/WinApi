#pragma once
#include "GameNode.h"
#include "Flame.h"

#define ROCKET_SPEED	10
class Rocket : public GameNode
{
private:
	my::Image* _image;
	Flame _flame;
	RECT _rc;
	float _x, _y;

public :

	HRESULT init(void);
	void release(void);
	void update(void);
	void render(void);
	Rocket() {}
	~Rocket() {}
};


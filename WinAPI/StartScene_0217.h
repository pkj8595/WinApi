#pragma once
#include "GameNode.h"

class StartScene_0217 : public GameNode
{
private:
	my::Image* _img;

	int _x, _y;
	RECT _rc;
	bool _isRight;

public:
	HRESULT init(void);
	void release(void);
	void update(void);
	void render(void);

	StartScene_0217() {}
	~StartScene_0217() {}
};


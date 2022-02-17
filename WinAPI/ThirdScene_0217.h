#pragma once
#include "GameNode.h"
#include "ProgressBar.h"
class ThirdScene_0217 : public GameNode
{
private:
	my::Image* _img;
	ProgressBar* _hpBar;
	RECT _rc;
	int _x, _y;
	bool _isRight;

	int _hp;
	int _previousTime;

public:
	HRESULT init(void);
	void release(void);
	void update(void);
	void render(void);

	ThirdScene_0217() {}
	~ThirdScene_0217() {}
};


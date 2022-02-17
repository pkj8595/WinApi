#pragma once
#include "GameNode.h"
class SecondScene_0217 : public GameNode
{
private:
	my::Image* _img;
	int _x, _y;
	RECT _rc;
	bool _isRight;

	int _probeY;

	my::Image* _nimg;
	int _nx, _ny;
	RECT _nrc;

	RECT _temprc;

	RECT _dialogRc;
	bool _dialogCheck;
public:
	HRESULT init(void);
	void release(void);
	void update(void);
	void render(void);

	SecondScene_0217() {}
	~SecondScene_0217() {}
};


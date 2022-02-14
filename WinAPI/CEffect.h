#pragma once
#include "GameNode.h"
class CEffect : public GameNode
{
private:
	my::Image* _image;
	RECT _rc;
	int _currentFrameX;
	int _currentFrameY;

	float _x, _y;
	float _rndTimeCount;
	float _worldTimeCount;
	float _isActive;

public:
	HRESULT init(void);
	virtual HRESULT init(const char* imageName, POINT position);
	void release(void);
	void update(void);
	void render(void);
	void draw(void);
	void animation(void);

	bool getIsActive(void) { return _isActive; }

	static CEffect getInstance(const char * imageName, POINT position);

	CEffect(void);
	virtual~CEffect(void);
};


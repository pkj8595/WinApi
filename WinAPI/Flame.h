#pragma once
#include "GameNode.h"

/*
실습 겸 과제1. 로켁에 flame 이미지 추가
- flame 이미지는 프레임렌더 
- flame 클래스에는 로켓에 대한 정보가 있으면 안되며 maingame또한 flame을 알 필요없다.
*/

class Flame : public GameNode
{
private:
	RECT _rc;
	int _frameX;
	int _time;

public:
	HRESULT init(void);
	void release(void);
	void update(void);
	void render(void);

	RECT getRc() { return _rc; }
	void setRc(RECT rc) { _rc = rc; }

	Flame();
	~Flame();
};


#pragma once
#include "GameNode.h"

/*
�ǽ� �� ����1. ���ʿ� flame �̹��� �߰�
- flame �̹����� �����ӷ��� 
- flame Ŭ�������� ���Ͽ� ���� ������ ������ �ȵǸ� maingame���� flame�� �� �ʿ����.
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


#pragma once
#include "Scene_inter.h"


#define _USE_MATH_DEFINES // �޽� ���� ��ƾ���
#include "math.h"


class HomeWork_0107_4 :public Scene_inter
{

public:
	virtual HRESULT init(void);
	virtual void release(void);
	virtual void update(void);
	virtual void render(HDC hdc);
};


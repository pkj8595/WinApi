#pragma once
#include "MainGame.h"

enum CURRENTRECT {
	CURRENTRECT_0,
	CURRENTRECT_1,
	CURRENTRECT_2,
	CURRENTRECT_3,
	CURRENTRECT_4,
	CURRENTRECT_5,
	CURRENTRECT_6,
	CURRENTRECT_7,
	CURRENTRECT_NULL
};

class GameClass_0103 : public Scene_inter
{
private:
	int typeSize;


	CURRENTRECT _currentRect;
	RECT _rc[8];					//�δ��� �簢�� 8�� 

	int _index;					//�δ����� ���� �ε����� ����
	int _count;					//Ÿ�̸ӿ� ī��Ʈ
	int _time;					//Ÿ�̸ӿ� �����ð�
	int _score;					//����

	bool _isSelected;
	bool _isOnceCheck;
	//�ߺ�üũ ����
public:
	HRESULT init();
	void release();
	void update();
	void render(HDC hdc);
};


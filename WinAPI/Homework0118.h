#pragma once
#include "MainGame.h"

/*

���� �ѿ� 25��-> 20��
���� 1
���̽� ����
-�̹��� �ʼ� (���+�ڵ���+(�÷��̾�+��)+ �����)
- ������� �ݵ�� �־�� �Ѵ�.
-������� �� �ӷ¿� ���� ��ȭ�Ѵ�.
-�ӵ����� ����
-�÷��̾�� ���� �浹�ϸ� ���� ����Ʈ�� �����鼭 ��������

*/
#define ENEMY_COUNT		20

class Homework0118 : public MainGame
{
private:
	enum P_STATE
	{
		STATE_idle = 0,
		STATE_left,
		STATE_right,
		STATE_dead
	};

	struct Enemy 
	{
		RECT rc;
		bool isActive;
		int speed;
	};

	P_STATE _pState;
	RECT _rcPlayer;
	float _pSpeed;
	int _index;

	Enemy _enemy[ENEMY_COUNT];

	double _bgSpeed;
	bool _isLeft;
	bool _isA;
	int _sponTime;

	POINT _ptPannel;
	float _angle;

public:
	virtual HRESULT init(void);
	virtual void release(void);
	virtual void update(void);		
	virtual void render(HDC hdc);

	Homework0118() {}
	~Homework0118() {}

	void macroPlayFrameAnimation(mycustom::Image * image, bool isleft, int & index);

	bool macroPlayOnceFrameAnimation(mycustom::Image * image, bool isleft, int & index, bool & isAnimating);

};


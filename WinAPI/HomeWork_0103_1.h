#pragma once
#include "MainGame.h"
#include "StickMan.h"




class HomeWork_0103_1 : public Scene_inter
{
private:
	StickMan _man;
	RECT _rc[100];
	RECT _player;
	RECT _temp;

	int _rXPos;
	int _time;
	int	_timeCount;
	int _count;

	bool _isGameStart;
	bool _isGameStop;
public:
	virtual HRESULT init(void);
	virtual void release(void);
	virtual void update(void);
	virtual void render(HDC hdc);

	HomeWork_0103_1() {}
	~HomeWork_0103_1() {}
	
};

/*
�ǽ� �� ����1. �����ϱ�
- ���� ��ư�� �����鼭 ������ ���۵ȴ�.
-������ ���۵ǰ� �÷��̾ ���������� ��ƾ �ð��� ȭ�鿡 ���
-�ʼ���� : ����� + �ٽ��ϱ�

���� 2 : �Ѿ� �߻�

-�ϴܿ��� �¿�� ������ �� �ִ� �÷��̾�
-�����̽� �ٸ� ������ �÷��̾ �Ѿ��� �߻��Ѵ�.(B->T)

���� 3. �Ǿ� �̻�
-�Ǿ� �̻��� �ּ� 12�� �̻�
-�Ǿ� �̻��� ������ �� ���� �޾ƾ� �Ѵ�.

*/
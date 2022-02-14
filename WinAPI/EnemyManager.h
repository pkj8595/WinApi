#pragma once
#include "GameNode.h"
#include "Enemy.h"


class EnemyManager: public GameNode
{
private:
	//** ���������� ���ϰ� ���͸� ������
	//*** ������ ���������� �����Ѵ� >> ��üȭ�ı�..?
	typedef vector<Enemy*> vEnemy;
	typedef vector<Enemy*>::iterator viEnemy;

private:
	vEnemy _vMinion;
	viEnemy _viMinion;

public:
	HRESULT init(void);
	void release(void);
	void update(void);
	void render(void);

	void setMinion(void);
	void removeMinion(int arrNum);
	vector<Enemy*> getMinions(void) { return _vMinion; }
	void checkActive(void);



	EnemyManager();
	~EnemyManager();
};


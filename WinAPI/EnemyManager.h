#pragma once
#include "GameNode.h"
#include "Enemy.h"
#include "Bullets.h"

class Rocket;
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

	Bullet* _bullet;
	Rocket* _rocket;

public:
	HRESULT init(void);
	void release(void);
	void update(void);
	void render(void);

	void setMinion(void);
	void removeMinion(int arrNum);
	vector<Enemy*> getMinions(void) { return _vMinion; }
	void checkActive(void);

	void minionBulletFire(void);
	void collision(void);

	Bullet* getBullet(void) { return _bullet; }
	void setRoketMemoryAddress(Rocket* rk) { _rocket = rk; }

	EnemyManager();
	~EnemyManager();
};


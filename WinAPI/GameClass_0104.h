#pragma once
#include "MainGame.h"
#include "HPprogressBar.h"


//���� ���� [Base]

//�Ѿ��� �ִ� ����
#define BULLET_MAX	10
#define PLAYER_SPEED	3
#define ENEMY_MAX	60 //�� Ÿ�ӿ��� ������ ������ �ִ°�? ������ ������ �ִٸ� ���͸� ���� �ȵȴ�.

//�߻�ü ����
struct tagBullet0104
{
	RECT rc;
	bool isfire;
};

//���� ������ ����ü
struct  tagEnemy
{
	RECT rc;
	int speed;
	bool die;
	int damage;
};

struct tagPlayer
{
	RECT rc;
	int hp;
};

class GameClass_0104 : public Scene_inter
{
private:
	tagBullet0104 _bullet[BULLET_MAX];
	tagEnemy _enemy[ENEMY_MAX];
	tagPlayer _player; // �÷��̾ ���ٸ� �Ѿ��� ������ �ʿ䰡 ����.
	HPprogressBar _bar;

	bool isGameOver;

public:
	virtual HRESULT init(void);
	virtual void release(void);
	virtual void update(void);
	virtual void render(HDC hdc);

	void fire(void);

	bool RectIsCollider(RECT* rec1, RECT* rec2);

	GameClass_0104() {}
	virtual ~GameClass_0104() {}
};






#pragma once
#include "MainGame.h"


enum PLAYER_STATE_0114
{
	STATE_IDLE = 0,
	STATE_MOVE,
	STATE_ATTACK,
	STATE_M_ATTACK,
	STATE_CICLE,
	STATE_VICTORY
};

class Homework_0114_frameImg : public MainGame
{
private:

	PLAYER_STATE_0114 _state;

	mycustom::Image* _background;
	mycustom::Image* _playerIdle;
	mycustom::Image* _playerMove;
	mycustom::Image* _playerAttack;
	mycustom::Image* _playerMAttack;
	mycustom::Image* _playerCicleAttack;
	mycustom::Image* _playerVictory;

	RECT _rcPlayer;
	bool _isLeft;
	bool _isAnimating;

	int _count;
	int _index;


public:

	virtual HRESULT init(void);
	virtual void release(void);
	virtual void update(void);
	void PlayFrameAnimation(mycustom::Image * image,  bool isleft, int &index);
	bool PlayOnceAnimation(mycustom::Image * image, bool isleft, int &index, bool &isAnimating);


	virtual void render(HDC hdc);



	Homework_0114_frameImg() {}
	~Homework_0114_frameImg() {}
};


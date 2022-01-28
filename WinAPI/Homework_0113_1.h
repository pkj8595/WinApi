#pragma once
#include "MainGame.h"

/*
���� 1 �����̵� ����
-ġƮ�ʼ�
-ȭ����ʿ� ���� ��� <-->ȭ�� �����ʿ��� 9��� �� �̹��� ���
-9��е� �̹��� ���� �Ʒ� ������ ĭ�� ����ĭ
-������ �ϼ��Ǹ� ���ĺ��� ȿ���� �̹����� ��Ÿ����.
-�Է¹�� ���콺 Ű���� �Ѵ�

*/
#define PUZZLE_START_X		430
#define PUZZLE_START_Y		200

class Homework_0113_1 : public MainGame
{
private:
	struct ST_SLICE
	{
		//mycustom::Image *sliceImg;
		int index;
		int num;
		RECT rc;
		bool isEndPz;
	};

	mycustom::Image *_puzzleImg;
	ST_SLICE _rcPuzzle[3][3];


	mycustom::Image *_GameStartImg;
	mycustom::Image *_CheetImg;
	RECT _rcGameStart;
	RECT _rcCheet;

	bool _isGameStart;

public:
	virtual HRESULT init(void);
	virtual void release(void);
	virtual void update(void);	//�ﰢ�Լ��� update�� �߿�	
	virtual void render(HDC hdc);

	void RectShuffle(RECT* rc, int arrSize, int shuffleCount);

	Homework_0113_1() {}
	~Homework_0113_1() {}
};


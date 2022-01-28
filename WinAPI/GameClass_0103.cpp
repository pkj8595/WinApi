#include "Stdafx.h"
#include "GameClass_0103.h"

HRESULT GameClass_0103::init()
{
	_currentRect = CURRENTRECT_NULL;
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			_rc[i * 4 + j] = RectMakeCenter(100 + j * 200,
				200 + i * 200,
				100,
				100
			);
		}
	}

	_index = 0;
	_count = 0;
	_score = 0;
	_time = RND->getFromFloatTo(30, 60);

	_isSelected = false;
	_isOnceCheck = false;

	return S_OK;
}

void GameClass_0103::release()
{
}

void GameClass_0103::update()
{

	if (KEYMANAGER->isOnceKeyDown(VK_LBUTTON))
	{
		//PrInRect() : ��Ʈ�ȿ� POINT (x, y)�� �ִ��� �˻��Ͽ� ����Ʈ�� 
		//			   �簢�� �ȿ� ������ true�� ��ȯ�ϴ� API �Լ�
		//�簢���̶� ���콺�� �浹 �ƴ��� 
		if (PtInRect(&_rc[_index], _ptMouse) &&
			!_isOnceCheck)
		{
			_score += 100;
			_isOnceCheck = true;
		}
	}
	if (!_isSelected)
	{
		_count++;
		if (_count % _time == 0)
		{
			_count = 0;
			_index = RND->getInt(8);
			_currentRect = (CURRENTRECT)_index;
			_isSelected = true;
		}
	}
	else
	{
		_count++;
		if (_count % _time == 0)
		{
			_isOnceCheck = false;
			_isSelected = false;
			_currentRect = CURRENTRECT_NULL;
			_time = RND->getFromIntTo(30, 60);
			_index = 100;
		}

	}
}

void GameClass_0103::render(HDC hdc)
{
	for (int i = 0; i < 8; i++)
	{
		Rectangle(hdc, _rc[i].left, _rc[i].top, _rc[i].right, _rc[i].bottom);
	}
	char strScore[128];
	wsprintf(strScore, "Score : %d", _score);
	TextOut(hdc, 50, 100, strScore, strlen(strScore));

	if (_isSelected)
	{
		int r = RND->getInt(256);
		int g = RND->getInt(256);
		int b = RND->getInt(256);

		//�귯�� RGB ����
		HBRUSH brush = CreateSolidBrush(RGB(r, g, b));

		//��Ʈ�� �� ä���ֱ�
		FillRect(hdc, &_rc[_index], brush);

		//�귯�� ����(�귯���� ������ �ݵ�� ��������Ѵ�.)
		DeleteObject(brush);
	}
}


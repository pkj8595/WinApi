#include "Stdafx.h"
#include "GameClass_0112.h"

HRESULT GameClass_0112::init(void)
{
	MainGame::init();

	IMAGEMANAGER->addImage("���彺���̽�", "Resource/Images/Background/background4.bmp", WINSIZE_X, WINSIZE_Y);

	_alphaA =0, _alphaNum =1;
	return S_OK;
}

void GameClass_0112::release(void)
{
	MainGame::release();

}

void GameClass_0112::update(void)
{
	MainGame::update();

	if (KEYMANAGER->isOnceKeyDown('Q'))
	{
		if (MessageBox(_hWnd, "������ �����Ͻðڽ��ϱ�?", "���� Ȯ��", MB_OKCANCEL) == IDOK)
		{
			PostQuitMessage(0);
		}
	}
	_alphaA += _alphaNum;
	if (_alphaA <= 0 || _alphaA >= 255) _alphaNum = _alphaNum * -1;


}

void GameClass_0112::render()
{
	//������ �� ��Ʈ��
	//PatBlt() : �簢�� ������ �귯���� ä��� �Լ�
	PatBlt(getMemDC(), 0, 0, WINSIZE_X, WINSIZE_Y, BLACKNESS);
	//========================================================

	IMAGEMANAGER->alphaRender("���彺���̽�",getMemDC(),0,0,_alphaA);

	//========================================================
	//������� ������ hdc�� �׸���.
	this->getBackBuffer()->render(getHDC());
}

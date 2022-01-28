#include "Stdafx.h"
#include "StartScene.h"


HRESULT StartScene::init(void)
{
	IMAGEMANAGER->addImage("����ȭ��", "Resource/Images/Background/backgroundSample3.bmp", WINSIZE_X, WINSIZE_Y);
	//IMAGEMANAGER->addImage("�ؽ�Ʈ����", "Resource/Images/Object/startButton.bmp", 600, 100, true, RGB(255, 0, 255));
	_alpha = _bgAlpha = 0;
	_isAlphaIncrece = false;

	return S_OK;
}

void StartScene::release(void)
{
}

void StartScene::update(void)
{
	_bgAlpha += 0.5f;
	if (_bgAlpha >= 255)_bgAlpha = 255;

	if (_alpha == 0 || _alpha == 255) _isAlphaIncrece = !_isAlphaIncrece;
	if (_isAlphaIncrece) _alpha += 1.0f; else _alpha -= 1.5f;
}

void StartScene::render(HDC hdc)
{
	IMAGEMANAGER->alphaRender("������ӹ��", getMemDC(), 0, 0, _bgAlpha);

	if (_bgAlpha >= 160) 
	{
		//IMAGEMANAGER->alphaRender("�ؽ�Ʈ����", getMemDC(), 150, WINSIZE_Y / 2 + 100, _alpha);
	}
	LPCWSTR script = L"PLEASE PRESS ENTER";
	FONTMANAGER->drawText(getMemDC(), 55, 100, "Kostar", 25, 700, script, wcslen(script), RGB(255, 255, 255));
}

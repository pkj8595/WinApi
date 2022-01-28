#include "Stdafx.h"
#include "SecondScene.h"

HRESULT SecondScene::init(void)
{
	IMAGEMANAGER->addImage("���", "Resource/Images/1942/1942map.bmp", 1000, 2048 * 2);
	_tempSound = new TempSoundTest;
	_tempSound->init();

	_offsetX = 0;
	_offsetY = 0;
	_bgSpeed=0;
	_textBufferCnt = 0;

	return S_OK;
}

void SecondScene::release(void)
{
}

void SecondScene::update(void)
{
	_tempSound->update();
	_bgSpeed += 3;
	if (KEYMANAGER->isStayKeyDown(VK_SPACE))_textBufferCnt += 1;
}

void SecondScene::render(HDC hdc)
{
	IMAGEMANAGER->loopRender("���", getMemDC(), &RectMake(0, 0, WINSIZE_X, WINSIZE_Y), 0, _bgSpeed);
	//SetBkMode() :�����ϰ� �ϴ� �Լ�(���� �ڷ� ����� ���̰� �Ѵ�.)
	SetBkMode(getMemDC(), TRANSPARENT);
	char str[128];
	wsprintf(str,"������ ��Ʈ");
	TextOut(getMemDC(), 120, 350, str, strlen(str));


	
	// ��Ʈ ���ο� ���
	HFONT font;
	HFONT oldFont;
	font = CreateFont(
		70, 0, 0, 0, 600, 0, 0, 1,
		HANGUL_CHARSET, 0, 0, 0, 0, TEXT("�޸ձ���")
	);
	oldFont = (HFONT)SelectObject(getMemDC(), font);

	wsprintf(str, "���ο� ��Ʈ");
	TextOut(getMemDC(), 100, 400, str, strlen(str));

	SelectObject(getMemDC(), oldFont);
	DeleteObject(font);

	//=====================fontmanager===============
	LPCWSTR script = L"�������� �ʰ� �ϴٺ��� ���� ���� ���α׷��Ӱ� �� �� �����ž�! ������ �׸�����...";
	FONTMANAGER->drawText(getMemDC(), 30, 100, "Kostar", 25, 700, script, (((_textBufferCnt / 5) > wcslen(script)) ? wcslen(script) : (_textBufferCnt / 5)), RGB(255, 219, 50));
	
}

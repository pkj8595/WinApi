#include "Stdafx.h"
#include "SecondScene_0217.h"

HRESULT SecondScene_0217::init(void)
{
	_img = IMAGEMANAGER->addFrameImage("공룡1", "Resource/Images/Object/dino.bmp", 300, 110, 2, 1, true, RGB(255, 0, 255));
	_nimg = IMAGEMANAGER->addFrameImage("공룡2", "Resource/Images/Object/dino2.bmp", 300, 110, 2, 1, true, RGB(255, 0, 255));

	IMAGEMANAGER->addImage("배경2", "Resource/Images/Background/bk_0217_2.bmp", WINSIZE_X, WINSIZE_Y);
	IMAGEMANAGER->addImage("배경2마젠타", "Resource/Images/Background/bkmagenta_0217_2.bmp", WINSIZE_X, WINSIZE_Y);
	IMAGEMANAGER->addImage("대화상자", "Resource/Images/Object/dialog.bmp", 360, 165, true,RGB(255,0,255));
	_x = 0;
	_y = CENTER_Y + 400;
	_isRight = true;
	_rc = RectMakeCenter(_x, _y, _img->getFrameWidth(), _img->getFrameHeight());
	_probeY = _y + _img->getFrameHeight() / 2;

	_nx = CENTER_X + 140;
	_ny = CENTER_Y + 220;
	_nrc = RectMakeCenter(_nx, _ny, _nimg->getFrameWidth(), _nimg->getFrameHeight());

	_dialogRc = RECT{0,0,0,0};
	_dialogCheck = false;

	return S_OK;
}

void SecondScene_0217::release(void)
{
}

void SecondScene_0217::update(void)
{
	if (KEYMANAGER->isStayKeyDown(VK_LEFT) &&
		_x- _img->getFrameWidth() / 2 > 0)
	{
		_x -= 4;
		_isRight = false;
	}
	if (KEYMANAGER->isStayKeyDown(VK_RIGHT) && 
		_x+ _img->getFrameWidth() / 2 < WINSIZE_X)
	{
		_x += 4;
		_isRight = true;
	}
	_probeY = _y + _img->getFrameHeight() / 2;

	for (int i = _probeY - 30; i < _probeY + 30; i++)
	{
		COLORREF color = GetPixel(IMAGEMANAGER->findImage("배경2마젠타")->getMemDC(), _x, i);
		int r = GetRValue(color);
		int g = GetGValue(color);
		int b = GetBValue(color);
		if (!(r == 255 && g == 0 && b == 255))
		{
			_y = i - _img->getFrameHeight() / 2;
			break;
		}
	}

	_rc = RectMakeCenter(_x, _y, _img->getFrameWidth(), _img->getFrameHeight());
	
	if (IntersectRect(&_temprc,&_rc,&_nrc))
	{
		_dialogCheck = true;
		_dialogRc = RectMakeCenter(CENTER_X, CENTER_Y, 360, 165);
		if (KEYMANAGER->isOnceKeyDown(VK_LBUTTON)) 
		{
			if (PtInRect(&_dialogRc, _ptMouse)) 
			{
				if (_ptMouse.x < CENTER_X) 
				{
					SCENEMANAGER->changeScene("StartScene_0217");
				}
				else if(_ptMouse.x > CENTER_X)
				{
					SCENEMANAGER->changeScene("ThirdScene_0217");
				}
			}
		}
	}
	else 
	{
		_dialogCheck = false;
	}
	

}

void SecondScene_0217::render(void)
{
	IMAGEMANAGER->render("배경2", getMemDC());
	if (_dialogCheck) 
	{
		IMAGEMANAGER->render("대화상자", getMemDC(), _dialogRc.left, _dialogRc.top);
	}

	_img->frameRender(getMemDC(), _rc.left, _rc.top, _isRight, 0);
	_nimg->frameRender(getMemDC(), _nrc.left, _nrc.top, 0, 0);

	if (KEYMANAGER->isToggleKey(VK_F1))
	{
		Rectangle(getMemDC(), _x, _probeY, _x + 10, _probeY + 10);
	}
}

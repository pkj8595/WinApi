#include "Stdafx.h"
#include "CShapePlayer.h"

void CShapePlayer::update(int time)
{
	_isMove = false;
	if (KEYMANAGER->isStayKeyDown(VK_LEFT))
	{
		if (_pt.x - 10 < 0) return;
		_pt.x -= 1;
		_isMove = true;
	}
	if (KEYMANAGER->isStayKeyDown(VK_RIGHT))
	{
		if (_pt.x + 10 > WINSIZE_X) return;
		_pt.x += 1;
		_isMove = true;
	}
	if (KEYMANAGER->isStayKeyDown(VK_UP))
	{
		if (_pt.y - 10 < 0) return;
		_pt.y -= 1;
		_isMove = true;
	}
	if (KEYMANAGER->isStayKeyDown(VK_DOWN))
	{
		if (_pt.y + 10 > WINSIZE_Y) return;
		_pt.y += 1;
		_isMove = true;
	}

	if (KEYMANAGER->isOnceKeyDown(VK_SPACE))
	{
		_speed = 25;
		_dashTime = time;
		//_rc = RectF(-12.5f, -7.5f, 25, 15);
		_dashRc = RectF(-15, -10, 30, 20);
		_isDash = true;
	}

	//player 방향잡기
	_angle = atan2f(_pt.y - _previousPt.y, _pt.x - _previousPt.x);
	//cout << _angle *(180/PI) << endl;

	/*_angle += 0.005f;
	float x1 = ((cosf(_angle)* (_rc.left - _pt.x)) -
		(sinf(_angle) * (_rc.top - _pt.y))) + _pt.x;

	float y1 = ((sinf(_angle)* (_rc.left - _pt.x)) +
		(cosf(_angle)*(_rc.top - _pt.y))) + _pt.y;

	float x2 = ((cosf(_angle)* (_rc.right - _pt.x)) -
		(sinf(_angle)*(_rc.bottom - _pt.y))) + _pt.x;

	float y2 = ((sinf(_angle)* (_rc.right - _pt.x)) + (cosf(_angle)*(_rc.bottom - _pt.y))) + _pt.y;

	_rc.left = x1;
	_rc.top = y1;
	_rc.right = x2;
	_rc.bottom = y2;*/

	if (_isMove)
	{

		_pt.x += cosf(_angle)* _speed;
		_pt.y += sinf(_angle)* _speed;
		_rc = RectF(-12.5f, -7.5f, 25, 15);
	}
	else 
	{
		_rc = RectF(-10, -10, 20, 20);
	}

	//dash
	if (_dashTime + 150 < time)
	{
		_isDash = false;
		_dashRc = RectF(0, 0, 0, 0);
		_speed = 8;
	}

	_mPlayer.SetElements(cosf(_angle + PI), sinf(_angle + PI), -sinf(_angle + PI), cosf(_angle + PI), (_pt.x), (_pt.y));

	_previousPt = _pt;

}

void CShapePlayer::render(Gdiplus::Graphics &g)
{
	g.SetTransform(&_mPlayer);
	g.DrawRectangle(&Pen(Color(80, 80, 80)), _rc);

	if (_isDash) g.FillRectangle(&SolidBrush(Color(255, 255, 255)), _dashRc);

	switch (_hp)
	{
	case 0:
	{
		break;
	}
	case 1:
	{
		Gdiplus::Image p(L"Resource/Images/Popol/p1.png");
		if (_isMove) g.DrawImage(&p, RectF(-12.5f, -7.5f, 25, 15));
		else g.DrawImage(&p, -10, -10, 20, 20);
		break;
	}
	case 2:
	{
		Gdiplus::Image p(L"Resource/Images/Popol/p2.png");
		if (_isMove) g.DrawImage(&p, RectF(-12.5f, -7.5f, 25, 15));
		else g.DrawImage(&p, -10, -10, 20, 20);
		break;
	}
	case 3:
	{
		Gdiplus::Image p(L"Resource/Images/Popol/p3.png");
		if (_isMove) g.DrawImage(&p, RectF(-12.5f, -7.5f, 25, 15));
		else g.DrawImage(&p, -10, -10, 20, 20);
		break;
	}
	case 4:
	{
		Gdiplus::Image p(L"Resource/Images/Popol/p4.png");
		if (_isMove) g.DrawImage(&p, RectF(-12.5f, -7.5f, 25, 15));
		else g.DrawImage(&p, -10, -10, 20, 20);
		break;
	}
	case 5:
	{
		g.FillRectangle(&SolidBrush(Color(0, 255, 255)), _rc);
		break;
	}
	default:
		break;
	}
}

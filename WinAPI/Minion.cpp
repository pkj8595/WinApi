#include "Stdafx.h"
#include "Minion.h"

Minion::Minion(){
	//!Do Nothing
}

Minion::~Minion(){
	//!Do Nothing
}

HRESULT Minion::init(const char* imageName, POINT position)
{
	Enemy::init(imageName, position);
	_pattern = static_cast<MI_PATTERN>( RND->getInt(3));
	_point = position;
	_angle = 0;
	switch (_pattern)
	{
	case Minion::PATTERN_1:
		_angleSpeed = RND->getFromFloatTo(0.01f, 0.03f);
		//_speed = RND->getFromIntTo(150, 300);
		_speed = 250;
		break;
	case Minion::PATTERN_2:
		_angleSpeed = 0.03f;
		_speed = 400;
		break;
	case Minion::PATTERN_3:
		_angleSpeed = RND->getFromFloatTo(0.01f, 0.03f);
		_speed = 40;
		break;
	default:
		break;
	}

	return S_OK;
}

void Minion::move(void)
{
	switch (_pattern)
	{
	case Minion::PATTERN_1:
		pattern1();
		break;
	case Minion::PATTERN_2:
		pattern2();
		break;
	case Minion::PATTERN_3:
		pattern3();
		break;
	default:
		break;
	}
	

}

void Minion::pattern1(void)
{
	_angle += _angleSpeed;
	_x = cosf(_angle) * _speed + WINSIZE_X / 2;
	_y = sinf(_angle) * _speed + WINSIZE_Y / 2-200;
	_rc = RectMakeCenter(_x, _y, _image->getFrameWidth(), _image->getFrameHeight());
}

void Minion::pattern2(void)
{
	_angle += _angleSpeed;
	_x = cosf(_angle) * _speed + WINSIZE_X / 2;
	_y = _point.y;
	_rc = RectMakeCenter(_x, _y, _image->getFrameWidth(), _image->getFrameHeight());
}

void Minion::pattern3(void)
{
	_angle += _angleSpeed;
	_x = cosf(_angle) * _speed + _point.x;
	_y = -sinf(_angle) * _speed + _point.y;
	_rc = RectMakeCenter(_x, _y, _image->getFrameWidth(), _image->getFrameHeight());
}

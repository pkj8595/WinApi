#include "Stdafx.h"
#include "CEffect.h"

CEffect::CEffect(void):_rc(RectMake(0, 0, 0, 0)),
						_currentFrameX(0),
						_currentFrameY(0),
						_x(0.0f),
						_y(0.0f),
						_rndTimeCount(0.0f),
						_worldTimeCount(0.0f) 
{
}

CEffect::~CEffect(void){
}

HRESULT CEffect::init(void)
{
	return S_OK;
}

HRESULT CEffect::init(const char* imageName, POINT position)
{
	_worldTimeCount = TIMEMANAGER->getWorldTime();
	_rndTimeCount = RND->getFromFloatTo(100, 150);
	_image = IMAGEMANAGER->findImage(imageName);
	_rc = RectMakeCenter(position.x, position.y, _image->getFrameWidth(), _image->getFrameHeight());
	_isActive = true;

	return S_OK;
}

void CEffect::release(void)
{
}

void CEffect::update(void)
{
}

void CEffect::render(void)
{
	draw();
	animation();
}

void CEffect::draw(void)
{
	_image->frameRender(getMemDC(), _rc.left, _rc.top, _currentFrameX, _currentFrameY);
}

void CEffect::animation(void)
{
	if (_rndTimeCount + _worldTimeCount <= TIMEMANAGER->getWorldTime())
	{
		_worldTimeCount = TIMEMANAGER->getWorldTime();
		_currentFrameX++;
		if (_image->getMaxFrameX() < _currentFrameX)
		{
			_isActive = false;
		}
	}
}

CEffect CEffect::getInstance(const char* imageName, POINT position)
{
	CEffect temp;
	ZeroMemory(&temp, sizeof(&temp));
	temp.init(imageName, position);
	return temp;
}

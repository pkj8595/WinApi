#include "Stdafx.h"
#include "EffectManager.h"

HRESULT EffectManager::init(void)
{
	//effect
	IMAGEMANAGER->addFrameImage("Dvl5", "Resource/Images/Rocket/Dvl5.bmp", 0.0f, 0.0f, 250, 51, 5, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("effect2", "Resource/Images/Rocket/effect2.bmp", 0.0f, 0.0f, 250, 33, 5, 1, true, RGB(255, 0, 255));
	return S_OK;
}

void EffectManager::release(void)
{
	_viEffect = _vEffect.begin();
	for (; _viEffect != _vEffect.end(); ++_viEffect)
	{
		(*_viEffect)->release();
		SAFE_DELETE(*_viEffect);
	}
}

void EffectManager::update(void)
{
	_viEffect = _vEffect.begin();
	for (; _viEffect != _vEffect.end(); ++_viEffect)
	{
		(*_viEffect)->update();

		//CheckIsActive
		if (!(*_viEffect)->getIsActive()) 
		{
			(*_viEffect)->release();
			SAFE_DELETE(*_viEffect);
		}
	}
}

void EffectManager::render(void)
{
	_viEffect = _vEffect.begin();
	for (; _viEffect != _vEffect.end(); ++_viEffect)
	{
		(*_viEffect)->render();
	}
}

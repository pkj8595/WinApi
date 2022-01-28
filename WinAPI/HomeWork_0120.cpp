#include "Stdafx.h"
#include "HomeWork_0120.h"



HRESULT HomeWork_0120::init(void)
{
	IMAGEMANAGER->addImage("������ӹ��", "Resource/Images/RhythmGame/Mbackground.bmp", WINSIZE_X, WINSIZE_Y);
	IMAGEMANAGER->addImage("���̽�", "Resource/Images/RhythmGame/base2.bmp", 451,WINSIZE_Y,TRUE,RGB(255,0,255));
	IMAGEMANAGER->addImage("���1", "Resource/Images/RhythmGame/note1.bmp", 77, 20);
	IMAGEMANAGER->addImage("���2", "Resource/Images/RhythmGame/note2.bmp", 77, 20);

	TEMPSOUNDMANAGER->addMp3FileWithKey("�����������", "Resource/Sound/Got Me.mp3");
	//TEMPSOUNDMANAGER->addWaveFileWithKey("�巳", "Resource/Sound/bass_drum.wav");

	for (int i = 0; i < 4; i++)
	{
		_scoreLine[i].rc = RectMake(i * 77+68, 500+35, 77, 20);
		_scoreLine[i].isActive = false;
	}

	_isPlay = false;

	return S_OK;
}

void HomeWork_0120::release(void)
{
	for (size_t i = 0; i < _vnote.size(); i++) 
	{
		SAFE_DELETE(_vnote.at(i));
	}
	_vnote.clear();
	vector<STNote*>().swap(_vnote);
}

void HomeWork_0120::update(void)
{
	if (KEYMANAGER->isOnceKeyDown(VK_SPACE)) 
	{
		_isPlay = !_isPlay;
	}
	
	if (_isPlay) 
	{
		TEMPSOUNDMANAGER->playSoundWithKey("�����������");
	}
	else 
	{
		TEMPSOUNDMANAGER->stopMp3WithKey("�����������");
		return;
	}

	if(KEYMANAGER->isOnceKeyDown('A'))
	{
		TEMPSOUNDMANAGER->playEffectSoundWave("Resource/Sound/bass_drum.wav");
		_scoreLine[0].isActive = true;
		collisionNote(0);
	}
	if (KEYMANAGER->isOnceKeyDown('S'))
	{
		TEMPSOUNDMANAGER->playEffectSoundWave("Resource/Sound/bass_drum.wav");
		_scoreLine[1].isActive = true;
		collisionNote(1);
	}
	if (KEYMANAGER->isOnceKeyDown('D'))
	{
		TEMPSOUNDMANAGER->playEffectSoundWave("Resource/Sound/bass_drum.wav");
		_scoreLine[2].isActive = true;
		collisionNote(2);
	}
	if (KEYMANAGER->isOnceKeyDown('F'))
	{
		TEMPSOUNDMANAGER->playEffectSoundWave("Resource/Sound/bass_drum.wav");
		_scoreLine[3].isActive = true;
		collisionNote(3);
	}

	if (KEYMANAGER->isOnceKeyUp('A'))
	{
		_scoreLine[0].isActive = false;
	}
	if (KEYMANAGER->isOnceKeyUp('S'))
	{
		_scoreLine[1].isActive = false;
	}
	if (KEYMANAGER->isOnceKeyUp('D'))
	{
		_scoreLine[2].isActive = false;
	}
	if (KEYMANAGER->isOnceKeyUp('F'))
	{
		_scoreLine[3].isActive = false;
	}

	if (GetTickCount() % 100 ==0) 
	{
		_binaryNum = RND->getInt(16);
		for (int i = 4; i > 0; --i) 
		{ 
			_binaryResult = _binaryNum >> i & 1;
			if (_binaryResult == 1) 
			{
				_vnote.push_back(new STNote{ RectMake((RND->getInt(4)) * 77 + 68, 0, 77, 20),RND->getInt(2),true });
			}
		}
	}


	for (_iter = _vnote.begin(); _iter != _vnote.end(); ++_iter)
	{
		if ((*_iter)->isActive)
		{
			(*_iter)->rc.top += NOTE_SPEED;
			(*_iter)->rc.bottom += NOTE_SPEED;
		}
	}

}

void HomeWork_0120::render(HDC hdc)
{
	IMAGEMANAGER->render("������ӹ��", getMemDC());
	IMAGEMANAGER->render("���̽�", getMemDC(),0,0);

	if (!_isPlay) 
	{
		LPCWSTR script = L"PLEASE PRESS SPACEBAR";
		FONTMANAGER->drawText(getMemDC(), 55, 100, "Kostar", 25, 700, script, wcslen(script), RGB(255, 219, 50));
	}

	for (int i = 0; i < 4; i++)
	{
		if (_scoreLine[i].isActive) 
		{
			RectangleMakeToRECT(getMemDC(),_scoreLine[i].rc);
		}
	}

	for (_iter = _vnote.begin(); _iter != _vnote.end(); ++_iter)
	{
		if ((*_iter)->isActive) 
		{
			if ((*_iter)->color == 0)
			{
				IMAGEMANAGER->render("���1", getMemDC(), (*_iter)->rc.left, (*_iter)->rc.top);
			}
			else 
			{
				IMAGEMANAGER->render("���2", getMemDC(), (*_iter)->rc.left, (*_iter)->rc.top);
			}
		}
	}


}

inline void HomeWork_0120::collisionNote(int noteIndex)
{
	for (_iter = _vnote.begin(); _iter != _vnote.end(); ++_iter)
	{
		if ((*_iter)->isActive)
		{
			if (RectCollider2(_scoreLine[noteIndex].rc, (*_iter)->rc))
			{
				(*_iter)->isActive = false;
			}
		}
	}
}

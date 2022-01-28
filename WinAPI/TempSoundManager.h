#pragma once
#include "SingletonBase.h"

//윈도우 내장 재생 라이브러리
//PlaySound()를 사용하기위해
#include <mmsystem.h>

//미이어 컨트롤 인터페이스 api
//mciSendString()를 사용하기위해 사용
//mci : media Control Interface
#include <mciapi.h>

//win 멀티 미디어 (그래픽카드를 불러올때도 사용)
#pragma comment(lib,"Winmm.lib")

class TempSoundManager :public SingletonBase<TempSoundManager>
{


public :
	HRESULT init();
	void addMp3FileWithKey(string key, string fileName);
	void addWaveFileWithKey(string key, string fileName);
	void playEffectSoundWave(char* fileName);
	void playSoundWithKey(string key);
	void stopMp3WithKey(string key);

	TempSoundManager() {}
	~TempSoundManager() {}
};


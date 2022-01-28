#include "Stdafx.h"
#include "TempSoundTest.h"

HRESULT TempSoundTest::init(void)
{
	TEMPSOUNDMANAGER->addMp3FileWithKey("����", "Resource/Sound/Got Me.mp3");
	TEMPSOUNDMANAGER->addWaveFileWithKey("��ü��", "Resource/Sound/paper_slide.wav");

	return S_OK;
}

void TempSoundTest::update(void)
{
	if (KEYMANAGER->isOnceKeyDown(VK_RETURN)) 
	{
		cout << "input : P" << endl;
		TEMPSOUNDMANAGER->playSoundWithKey("����");
	}
	if (KEYMANAGER->isOnceKeyDown('A')) 
	{
		//TEMPSOUNDMANAGER->playSoundWithKey("��ü��");
		//cout<<"input : A" <<endl;
		TEMPSOUNDMANAGER->playEffectSoundWave("Resource/Sound/paper_slide.wav");
	}


}

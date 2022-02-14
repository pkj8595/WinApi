#include "Stdafx.h"
#include "AniTestScene.h"

HRESULT AniTestScene::init(void)
{
	//_image = IMAGEMANAGER->addImage("�ڳ���", "Resource/Images/Object/Ell.bmp", 660, 268, true, RGB(255, 0, 255));
	_image = IMAGEMANAGER->addImage("����", "Resource/Images/Object/Ell.bmp", 660, 268, true, RGB(255, 0, 255));

	_animationA = new Animation;
	//x:6 y:4 
	//�Լ� �Ű������� ������ ����
	//�̹����� ������ ���� ȣ��ɶ����� ������ ����.
	//���ҽ��� ������ ���� ���� �ſ� ��������. �����õ
	_animationA->init(_image->getWidth(), _image->getHeight(),110,67);
	_animationA->setDefPlayFrame(false, true);
	_animationA->setFPS(10);

	return S_OK;
}

void AniTestScene::release(void)
{
	_animationA->release();
	SAFE_DELETE(_animationA);
}

void AniTestScene::update(void)
{
	if (KEYMANAGER->isOnceKeyDown('B')) 
	{
		_animationA->AniStart();
	}
	_animationA->frameUpdate(TIMEMANAGER->getElapsedTime() * 1);

}

void AniTestScene::render(void)
{
	//_image->
	_image->aniRender(getMemDC(),CENTER_X-50,CENTER_Y,_animationA);
}
#include "Stdafx.h"
#include "EnemyManager.h"
#include "Minion.h"

EnemyManager::EnemyManager(){
	//DO NOTTING
}

EnemyManager::~EnemyManager(){
	//DO NOTTING
}

HRESULT EnemyManager::init(void)
{
	IMAGEMANAGER->addFrameImage("���ĸ�", "Resource/Images/Rocket/jelly.bmp", 0.0f, 0.0f, 1140, 47, 19, 1, true, RGB(255, 0, 255));

	//�̴Ͼ� ����
	setMinion();

	return S_OK;
}

void EnemyManager::release(void)
{
	_viMinion = _vMinion.begin();
	for (; _viMinion != _vMinion.end(); ++_viMinion) 
	{
		//�������ϴϱ� �Ǵ� ����?
		(*_viMinion)->release();
		SAFE_DELETE(*_viMinion);
	}
}

void EnemyManager::update(void)
{
	_viMinion = _vMinion.begin();
	for (;_viMinion != _vMinion.end(); ++_viMinion) 
	{
		(*_viMinion)->update();
	}
	checkActive();
}

void EnemyManager::render(void)
{
	_viMinion = _vMinion.begin();
	for (; _viMinion != _vMinion.end(); ++_viMinion)
	{
		(*_viMinion)->render();
	}
}

void EnemyManager::setMinion(void)
{
	for (int i = 0; i < 3; i++)
	{
		for (int  j = 0; j < 10; j++)
		{
			Enemy* jellyFish;
			jellyFish = new Minion;
			jellyFish->init("���ĸ�", PointMake(50 + j * 50, 100 + i * 100));
			_vMinion.push_back(jellyFish);

		}
	}
}

//at�� ��ȸ�ϰ� �ش� �ε����� ��ȯ
//[index]�� �迭�� ���ٰ� �ε����� �����ϸ� ��ȯ
void EnemyManager::removeMinion(int arrNum)
{
	_vMinion[arrNum]->release();
	SAFE_DELETE(_vMinion[arrNum]);
	_vMinion.erase(_vMinion.begin() + arrNum);
}

//�����ʸ� ����ϴ� ���� ���ƺ��̱��Ѵ�. 
void EnemyManager::checkActive(void)
{
	_viMinion = _vMinion.begin();
	for (; _viMinion != _vMinion.end(); ++_viMinion)
	{
		if (!(*_viMinion)->getIsActive()) 
		{
			(*_viMinion)->release();
			SAFE_DELETE(*_viMinion);
			_viMinion = _vMinion.erase(_viMinion);
			break;
		}
	}
}


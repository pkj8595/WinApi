#pragma once
#include "SingletonBase.h"

class RandomFunction : public SingletonBase<RandomFunction>
{
public:
	RandomFunction() 
	{
		//API �����Լ� : GetTickCount(���� Ÿ�̸ӻ� ������ �ȵǾ� �ִ� ȯ���̸� ������ �����ϴ� ��)
		//GetTickCount : OS�� ���õ� ���� ��� �ð��� üũ 
		//-�⺻������ �и����� ������ üũ�� �����ϸ� �и����� ������ �ð����� ��ȯ �ϱ⿡ ������ �����ϴ�.
		srand(GetTickCount());
	}
	~RandomFunction() {}

	HRESULT init() { return S_OK; }

	inline int getInt(int num) 
	{
		return rand() % num;
	}
	//���ǻ��� 0�� ������ ������.
	inline int getFromIntTo(int fromNum, int toNum) 
	{
		return rand() % (toNum - fromNum +1) +fromNum;
	}
	//1.00
	float getFloat(void) 
	{
		return (float)rand() / (float)RAND_MAX;
	}

	float getFloat(float num)
	{
		return (float)rand() / (float)RAND_MAX * num;
	}
	
	float getFromFloatTo(float fromNum, float toNum) 
	{
		float rnd = (float)rand() / (float)RAND_MAX;
		return (rnd * (toNum - fromNum) + fromNum);
	}



};


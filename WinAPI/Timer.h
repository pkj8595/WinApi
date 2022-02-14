#pragma once
/*
- ������ ����� API �����Լ� >> �������� ���� ����.
���ػ� Ÿ�̸�
GetTickCount();		>> 32bit >> �ֱ� 1/1000
GetTickCount64();	>> 64bit ����� 

Ÿ�̸Ӹ� ������ ���� Ÿ�̸����� Ȯ���ϴ¹��� ���ػ��̳� ���ػ��̳�

�ػ󵵿� ���� �������� �ٸ� 

*/

/*
���ػ� �ֱ� = 1/9000000 
Timer  
-�ð��� �����ϴ� �Լ����� ������ ���� �⺻������ �����찡 ���۵� ���� Milli Second������ ��ȯ

-���� Ÿ�̸Ӹ� �����Ҷ� �˾Ƶ־� �� ������ #�ػ�#�� #Ŭ��#
Ŭ���� �ػ󵵸� ����ؾ��Ѵ�.

�ػ� ? 
- �پ��� �ð� �Լ����� �ð��� �����ϱ� ���� Tick �������� �ִ�. 
	�� 1���� �������� �󸶳� ���� ���������� ���� �� �ִ����� ���Ѵ�.
-1�е��� �󸶳� ���� Tick���� ������ �ð��� ��Ȯ���� ���̴��Ŀ� ���� ���ػ󵵿� ���ػ󵵷� ������.

Clock(������)
-Ÿ�̸ӿ��� ����ϴ� Ŭ���� CPU Ŭ��(Clock)�� �ǹ��Ѵ�.
-Ŭ�� ��ü�� ������ ȸ���� ������ ���� �� �̸� Hz�� ǥ��
�� 1Hz : 1�ʶ�� �����Ͽ� ��ȣ(0 or 1)�� 1�� �ش�.
	�� 1��Ʈ�� �ѹ� �ű�ٴ� �ǹ� 

- 1GHz = 10^9  ���� -> 10��
- 3.00GHz -> 30���
	�� 1�ʿ� 30�ﰳ�� bit�� �ű� �� �ִ�.
	���پ��� ���Ѵ�. �ٸ� ���α׷����� �ֱ� ������

## ���� Ÿ�̸��� ��� ���� ����Ű�� ���ؼ��� ��ø�� �ʿ��ϴ�.
	���뷫 9�鸸���� 1�ʱ��� ����
	
-�⺻������ �����ϰ� ����� �� �鸸���� 1�ʱ��� ��������

923��...��ø�� ��ø���ؼ� cpu�� ������ �޸𸮿� �Ҵ�?

## �Լ��� Ŭ������ �ʹ� ������ OS�� �����Ű�� �ʴ´�.

*/

class Timer
{
private:
	float _timeScale;		//����ð�
	float _timeElapsed;		//������ �ð��� ����ð��� �����
	bool _isHardware;		//���� Ÿ�̸� ���� ����

	//INT64_MAX
	//32bit���� ����Ҷ� 4����Ʈ 
	//64bit���� ����Ҷ� 8����Ʈ
	__int64 _curTime;			//���� �ð�
	__int64 _lastTime;			//���� �ð�
	__int64 _periodFrequency;	//�ð��ֱ�

	unsigned long _frameRate;
	unsigned long _FPSFrameCount;
	float _FPSTimeElapsed;
	float _worldTime;

public:
	HRESULT init(void);
	//���� �ð��� ���
	void tick(float lockFPS = 0.0f);	//������ 60���� �ᱺ��.
	
	//���� FPS
	unsigned long getFrameRate(char* str = nullptr) const;
	//������ �ð��� ���� �ð��� ����� FPS����
	inline float getElapsedTime(void) const { return _timeElapsed; }
	//��ü ��� �ð�
	inline float getWorldTime(void) const { return _worldTime; }

	Timer() {}
	~Timer() {}
};


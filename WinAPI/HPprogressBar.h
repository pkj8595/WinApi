#pragma once


/*
	������ ���� 
	Render�� update�� �Լ� ����
*/
class HPprogressBar
{
private:
	float _nHp;

	RECT _rectMaxHp;
	RECT _rectHp;
	float _nMaxHp;
	float temp;
public:
	HPprogressBar() {}
	HPprogressBar(int hp);
	//���α׷����� ����
	void RenderHpbar(HDC hdc);

	//���α׷����� �������� ��ġ,ü��
	void UpdateHpBar(RECT * tager, int nHp);

};


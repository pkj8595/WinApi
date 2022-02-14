#pragma once

//����� �̹����� ��������
static my::Image* _backBuffer = IMAGEMANAGER->addImage("backBuffer", WINSIZE_X, WINSIZE_Y);

class GameNode
{
private:
	HDC _hdc;
	bool _managerInit;

public :
	GameNode() {}
	virtual ~GameNode() {}

	//HRESULT: �Լ��� ���������� ����Ǿ����� üũ 
	//�������� �ƴ� ������ ������ �ǹ��ϸ� ���������� ���и� �ǹ�
	virtual HRESULT init(void);
	virtual HRESULT init(bool managerInit);
	virtual void release(void);
	virtual void update(void);
	virtual void render(void);
	
	//����� �̹��� ���
	my::Image* getBackBuffer(void) { return _backBuffer; }
	HDC getMemDC() { return _backBuffer->getMemDC(); }
	HDC getHDC() { return _hdc; }

	//! �������ν���
	//LRESULT : �ݹ��Լ��� ��ȯ������ ���� ���ȴ�.
	// �޼��� ó���� ��ģ �� os ���� ��ȣ�� �ֱ����� ��
	LRESULT MainProc(HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM lParam);

};


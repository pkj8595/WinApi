#include "Stdafx.h"
#include "GameNode.h"



HRESULT GameNode::init(void)
{

	//�Լ��� ���������� ����Ǿ����� �˸��� S_OK ��ȯ
	//���� ������ 
	return S_OK;
}

HRESULT GameNode::init(bool managerInit)
{
	_hdc = GetDC(_hWnd);
	_managerInit = managerInit;

	if(managerInit)
	{
		//������ ����(#include "locale.h")
		//LC_ALL : ������ ī�װ�. os�� �ִ� ������ �����
		setlocale(LC_ALL, "Korean");
		//setTimer
		SetTimer(_hWnd, 1, 10, NULL);
		//Ű �Ŵ��� �ʱ�ȭ
		KEYMANAGER->init();
		RND->init();
		IMAGEMANAGER->init();
		TEMPSOUNDMANAGER->init();
		TIMEMANAGER->init();
		RECTOBSERVERMANAGER->init();

	}

	return S_OK;
}

void GameNode::release(void)
{
	if (_managerInit) 
	{
		//Ÿ�̸� ���� 
		KillTimer(_hWnd, 1);
		//Ű�Ŵ��� �̱��� ����
		KEYMANAGER->releaseSingleton();
		//������� �̱��� ����
		RND->releaseSingleton();
		IMAGEMANAGER->release();
		IMAGEMANAGER->releaseSingleton();
		FONTMANAGER->releaseSingleton();
		TEMPSOUNDMANAGER->releaseSingleton();
		TIMEMANAGER->releaseSingleton();

		RECTOBSERVERMANAGER->releaseSingleton();
	}


	ReleaseDC(_hWnd, _hdc);
}

void GameNode::update(void)
{
	//InvalidateRect(_hWnd, NULL, FALSE);		//�̹���
}

void GameNode::render(void)
{
}

LRESULT GameNode::MainProc(HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM lParam)
{
	
	HDC hdc;
	PAINTSTRUCT ps;

	switch (iMessage)
	{
	case WM_TIMER:
		//this->update();
		break;
	case WM_CREATE:		
		break;

	case WM_PAINT:	//��¿� ���� ������ ����Ѵ�.(ȭ�鿡 ���̴� �����)
		hdc = BeginPaint(hWnd, &ps);
		//this->render();
		EndPaint(hWnd, &ps);
		break;
	case WM_MOUSEMOVE:
		_ptMouse.x = LOWORD(lParam);
		_ptMouse.y = HIWORD(lParam);
		break;
	case WM_LBUTTONDOWN:	//���� ���콺�� �������� �޼��� �߻�

		break;
	case WM_RBUTTONDOWN:

		break;
	case WM_KEYDOWN:
		switch (wParam)
		{

		case VK_ESCAPE:		//esc�� ������ ȭ�� ����
			PostMessage(hWnd, WM_DESTROY, 0, 0);
			break;
		}
		break;
	case WM_DESTROY:	//�Ҹ���
		PostQuitMessage(0);
		return 0;
	}

	return( DefWindowProc(hWnd, iMessage, wParam, lParam));
}

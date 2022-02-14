#include "Stdafx.h"
#include "GameNode.h"



HRESULT GameNode::init(void)
{

	//함수가 성공적으로 실행되었음을 알리는 S_OK 반환
	//성공 오케이 
	return S_OK;
}

HRESULT GameNode::init(bool managerInit)
{
	_hdc = GetDC(_hWnd);
	_managerInit = managerInit;

	if(managerInit)
	{
		//로케일 설정(#include "locale.h")
		//LC_ALL : 로케일 카테고리. os에 있는 정보를 끌고옴
		setlocale(LC_ALL, "Korean");
		//setTimer
		SetTimer(_hWnd, 1, 10, NULL);
		//키 매니저 초기화
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
		//타이머 해제 
		KillTimer(_hWnd, 1);
		//키매니저 싱글톤 해제
		KEYMANAGER->releaseSingleton();
		//랜덤펑션 싱글톤 해제
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
	//InvalidateRect(_hWnd, NULL, FALSE);		//이미지
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

	case WM_PAINT:	//출력에 관한 모든것을 담당한다.(화면에 보이는 보든것)
		hdc = BeginPaint(hWnd, &ps);
		//this->render();
		EndPaint(hWnd, &ps);
		break;
	case WM_MOUSEMOVE:
		_ptMouse.x = LOWORD(lParam);
		_ptMouse.y = HIWORD(lParam);
		break;
	case WM_LBUTTONDOWN:	//왼쪽 마우스가 눌렸을때 메세지 발생

		break;
	case WM_RBUTTONDOWN:

		break;
	case WM_KEYDOWN:
		switch (wParam)
		{

		case VK_ESCAPE:		//esc를 누르면 화면 종료
			PostMessage(hWnd, WM_DESTROY, 0, 0);
			break;
		}
		break;
	case WM_DESTROY:	//소멸자
		PostQuitMessage(0);
		return 0;
	}

	return( DefWindowProc(hWnd, iMessage, wParam, lParam));
}

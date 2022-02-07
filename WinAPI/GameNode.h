#pragma once

//백버퍼 이미지를 정적으로
static my::Image* _backBuffer = IMAGEMANAGER->addImage("backBuffer", WINSIZE_X, WINSIZE_Y);

class GameNode
{
private:
	HDC _hdc;
	bool _managerInit;
	


public :
	GameNode() {}
	virtual ~GameNode() {}

	//HRESULT: 함수가 성공적으로 실행되었는지 체크 
	//ㄴ음수가 아닌 값들은 성공을 의미하며 음수값들은 실패를 의미
	virtual HRESULT init(void);
	virtual HRESULT init(bool managerInit);
	virtual void release(void);
	virtual void update(void);
	virtual void render(void);
	
	//백버퍼 이미지 얻기
	my::Image* getBackBuffer(void) { return _backBuffer; }
	HDC getMemDC() { return _backBuffer->getMemDC(); }
	HDC getHDC() { return _hdc; }

	//! 메인프로시저
	//LRESULT : 콜백함수의 반환형으로 많이 사용된다.
	// 메세지 처리를 마친 후 os 에게 신호를 주기위한 값
	LRESULT MainProc(HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM lParam);

};


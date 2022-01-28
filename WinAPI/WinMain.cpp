#include "Stdafx.h"
#include "MainGame.h"

//
//#include "GameClass_0112.h"
//#include "HomeWork_0112_1.h"
//#include "Homework_0113_1.h"
//#include "Homework_0114_frameImg.h"

#include "GameClass0117.h"
#include "Homework0118.h"

/*
	API : �ü���� �������α׷� ������ ���� �����ϴ� �Լ��� ����(���ø����̼� ���α׷��� �������̽�)
	�ϵ���� <-------------> �ü�� (W,L) <--------------> �������α׷�
	(API)��ġ

	-why? : �ü���� ������ ���� ����� ������ ����� �� �ֱ� ������ Ȯ�强 �� ������, �׸��� ���������� ���ϴ�.(����)

	API�ϸ� �˾ƾ� �� 3����  >> ��������
	-ũ�� �������� �޼��� ����, �׸��� Window Procedure�� ������.

	2���� -> �б� api 
				 dx

*/
/*
	API ���ڼ�
	��Ƽ����Ʈ / �����ڵ� 

	TCHAR ���� ������Ʈ�� ���ڼ� ������ ���� �ڵ������� char�Ǵ�  wchar_t �� ��ȯ�Ǵ� �߰� ��ũ�� �ڷ����̴�.
	��Ƽ����Ʈ�� �����ڵ� ȯ�濡�� ������ ���� �۾� ���� ���α׷�
*/


//!���� ����
//!�ν��Ͻ� : ������ os�� ���� ����ǰ� �ִ� ���α׷��� Ȯ���ϱ� ���� ��
//���� ���α׷��̸� ���� �ν��Ͻ� ���� ������.
//��Ŭ������ �޸𸮿� ������ ������ ��ü
//������ǰ� �ִ� ������ ���α׷��� ��� ������ �ν��Ͻ��� ������.


//=======================
// # �������� #
//=======================
HINSTANCE _hInstance;     
//������ �ڵ�
HWND _hWnd;
POINT _ptMouse = { 0,0 };
MainGame* _mg;

//������ Ÿ��Ʋ  �̸� �߷�>>��� ��Ʈ�� >> const char*

//�����ڵ�� ��Ƽ����Ʈ�� ��ȯ���ش�. 
//TCHAR* _lpszClass = _T("WindowAPI");


//================
//#�Լ� ���� ����#
//================
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
void SetWindowSize(int x, int y, int width, int height);


//�̷��� �� �� �ִ�.
//int WINAPI _tWinMain(HINSTANCE hInstance,
//					HINSTANCE hPrevInstance,
//					TCHAR*   lpszCmdParam,
//					int       nCmdShow) {}

//! window main �Լ� 
int APIENTRY WinMain( HINSTANCE hInstance,
						HINSTANCE hPrevInstance,
						LPSTR    lpszCmdParam,
						int       nCmdShow)
{
	_mg = new MainGame();
	//_mg = new HomeWork_0112_1();
	//_mg = new Homework_0113_1();
	//_mg = new Homework_0114_frameImg();
	//_mg = new GameClass0117();	
	//_mg = new Homework0118();

	_hInstance = hInstance;

	//GDI+
	ULONG_PTR m_gdiplusToken;
	Gdiplus::GdiplusStartupInput gdiplusStartupInput;
	if (GdiplusStartup(&m_gdiplusToken, &gdiplusStartupInput, NULL) != Gdiplus::Ok)
	{
		MessageBox(NULL, TEXT("GDI+ ���̺귯���� �ʱ�ȭ�� �� �����ϴ�."),
		TEXT("�˸�"), MB_OK);
		return 0;
	}


	/*
		winmain�� ����
		1. ������ â�� ���� �� ȭ�鿡 ����
			�� ���� (4����)�� ��� ó���ؾ� ȭ�鿡 â�� ���.
		2. �޼��� ���� 
	
	*/
	//EX�� ������ Ȯ��� ��

	//WNDCLASS : �ȵ��� â�� ������ �����ϱ� ���� ����ü
	// - Ŀ����-> �������� �ü���� ������ ������ ��Ź�ϱ� ���ؼ� Ŀ���Ҹ� �����츦 �ĺ��� �� �մ� �������� ����ϴ� �������Ѵ�.

	//1-1 ������â ����ü ���� �� �ʱ�ȭ
	WNDCLASS wndClass;
	wndClass.cbClsExtra = 0;										//Ŭ���� ���� �޸�
	wndClass.cbWndExtra = 0;										//������ ���� �޸�
	wndClass.hbrBackground = (HBRUSH)(GetStockObject(WHITE_BRUSH));	//��׶���
	wndClass.hCursor = LoadCursor(NULL, IDC_ARROW);					//���콺 Ŀ��
	wndClass.hIcon = LoadIcon(NULL, IDI_APPLICATION);				//������
	wndClass.hInstance = hInstance;									//�����츦 ������ �ĺ��� ����
	wndClass.lpfnWndProc = (WNDPROC)WndProc;						//������ ���ν���
	wndClass.lpszClassName = WINNAME;							//Ŭ��������
	wndClass.lpszMenuName = NULL;									//�޴��̸�
	wndClass.style = CS_HREDRAW | CS_VREDRAW;						//������ ��Ÿ��

	//1-2. ������ Ŭ���� ���
	RegisterClass(&wndClass);

#ifdef FULLSCREEN
	//����̽� ��� ����ü (ȭ�� ���÷��� ���� ���)
	DEVMODE dm;
	ZeroMemory(&dm, sizeof(DEVMODE));

	dm.dmBitsPerPel = 32;		//32��Ʈ Ʈ���÷�
	dm.dmPelsWidth = 1980;		//�����ػ�
	dm.dmPelsHeight = 1020;		//�����ػ�
	dm.dmDisplayFrequency = 60;	//�����

	//Fields : �پ��� ���÷��� ������ �츮�� ����� �������� �Ѱ��ְڴ�.
	dm.dmFields = DM_BITSPERPEL | DM_PELSWIDTH | DM_PELSHEIGHT | DM_DISPLAYFREQUENCY;

	//ȭ���� ����Ǹ� �ڵ����� ���� ȭ���� �ػ󵵷� ����
	if (ChangeDisplaySettings(&dm, CDS_FULLSCREEN) != DISP_CHANGE_SUCCESSFUL) 
	{
		ChangeDisplaySettings(&dm, 0);
	}

	_hWnd = CreateWindow
	(
		WINNAME,				//������ Ŭ���� �ĺ���
		WINNAME,				//������ Ÿ��Ʋ �� �̸�
		WINSTYLE,				//������ ��Ÿ��
		WINSTART_X,					//������ ȭ�� x��ǥ
		WINSTART_Y,					//������ ȭ�� Y��ǥ
		WINSIZE_X,					//������ ȭ�� ����ũ��
		WINSIZE_Y,					//������ ȭ�� ����ũ��
		NULL,					//�θ� ������ GetDesktopWindow,
		(HMENU)NULL,			//�޴��ڵ�
		hInstance,				//�ν��Ͻ� ����
		NULL					//�������� �ڽ� �����츦 �����ϸ� ����, �׷��������� null
								// �� �ʿ信 ���ؼ� ��������� ������ NULL
	);
	SetWindowSize(WINSTART_X, WINSTART_Y, WINSIZE_X, WINSIZE_Y);


#else

	//1-3. ȭ�鿡 ������ ������ â ����
	_hWnd = CreateWindow
	(
		WINNAME,				//������ Ŭ���� �ĺ���
		WINNAME,				//������ Ÿ��Ʋ �� �̸�
		WINSTYLE,				//������ ��Ÿ��
		WINSTART_X,					//������ ȭ�� x��ǥ
		WINSTART_Y,					//������ ȭ�� Y��ǥ
		WINSIZE_X,					//������ ȭ�� ����ũ��
		WINSIZE_Y,					//������ ȭ�� ����ũ��
		NULL,					//�θ� ������ GetDesktopWindow,
		(HMENU)NULL,			//�޴��ڵ�
		hInstance,				//�ν��Ͻ� ����
		NULL					//�������� �ڽ� �����츦 �����ϸ� ����, �׷��������� null
								// �� �ʿ信 ���ؼ� ��������� ������ NULL
	);
	SetWindowSize(WINSTART_X, WINSTART_Y, WINSIZE_X, WINSIZE_Y);

#endif

	
	//1-4. ȭ�鿡 ������ â �����ֱ�
	ShowWindow(_hWnd, nCmdShow);

	//**1.�Ϲ��� or �����Ѱ� ���鶧
	//UpdateWindow(_hwnd);

	//���ΰ��� Ŭ���� �ʱ�ȭ ���н� ����
	//�������� �����ÿ��� ������ ������ ���Ѵ�.
	if (FAILED(_mg->init())) 
	{
		return 0;
	}

	//2. MSG : �ü������ �߻��ϴ� �޼��� ������ �����ϱ� ���� ����ü
	MSG message;

	//**2.�޸𸮸� �׼� ����ְ� ����Ѵ�.
	//ZeroMemory(&message, sizeof(message)); // �޸𸮸� ����ִ� �Լ�?

	/*
		GetMessage : �޼����� ������ �� ���������� �����ִ� �Լ�
		�� GetMessage�Լ��� �޼��� ť�κ��� �ϳ��� �޼����� �������� ������ �Ѵ�.
		����, �޼����� ť�� ������� ���(�߻��� �޼��� x) �޼����� ���ö����� ����Ѵ�.

		PeekMessage : �޼����� ������ ��ȯ�Ǵ� �Լ�(���� ����ȭ)

	*/
	//2.
	//! �޽��� ���� :


	/*
	while (true) 
	{
		�ڵ鿡 NULL�� �ִ� ���� 
		������ �츮 ���α׷��� �� while���ȿ� ���ӵȴ�.
		if (PeekMessage(&message, NULL, 0, 0, PM_REMOVE)) 
		{
			if (message.message == WM_QUIT) break;
			TranslateMessage(&message);
			DispatchMessage(&message);
		}
	}
	*/

	while (GetMessage(&message, 0, 0, 0))
	{
		TranslateMessage(&message);
		DispatchMessage(&message);
	}
	/*
		updateó�� ��� �޼����� ���� �޴´�.
		TranslateMessage	: Ű������ �Է�ó���� ���
								�Էµ� Ű�� ���� Ű���� Ȯ�� �� �빮�� Ȥ�� �ҹ���, �ѱ�, ���������� ���� WM_CHAR �޼����� �߻���Ų��.
		DispatchMessage		:������ ���ν������� ���޵� �޼����� ���� ������� ����(�е��� �߿�) 
	*/

	Gdiplus::GdiplusShutdown(m_gdiplusToken);
	_mg->release();
	//!������ Ŭ���� ��� ����
	UnregisterClass(WINNAME, hInstance);

	return message.wParam;
}


//  �Լ�: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  �뵵: �� â�� �޽����� ó���մϴ�.
//
//  WM_COMMAND  - ���ø����̼� �޴��� ó���մϴ�.
//  WM_PAINT    - �� â�� �׸��ϴ�.
//  WM_DESTROY  - ���� �޽����� �Խ��ϰ� ��ȯ�մϴ�.

//API ��
//! ������ ���ν���  ���ν����� �߸��ǵ��̸� window�� ����? 
LRESULT CALLBACK WndProc(HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM lParam)
{
	/*
		Window Procedure : �޼����� �ü���� ���� -> ������ �ü���� ȣ�����ش�.
				�� �����츦 ������ �� �ݵ�� ������ ����Ѵ�.
				��WinMain�� �ƴ� , �ü�翡 ���� ȣ��Ǵ� �ݹ� �Լ� 


		api�� o/s�� ���� �޼��� ó���� �����ϴ�.
			o/s�� ���������� �ʴ� 
			�������ε� ������ �۵����� �ʴ´�.
			���ν����� �־�� �ϴ� ����
			���ÿ� ó�� �ؾ��ϴ� ����� ������ �ָܼ� �������� ����

		hWnd : ��� �����쿡�� �߻��� �޼������� ���� 
		iMessage : �޼��� ���� ��ȣ
		wParam : unsigned int ���콺 ��ư�� ����, Ű���� ���� Ű�� ���¸� ����
		lParam : unsigned long ���콺 Ŭ�� ��ǥ ����

	*/
	//GDI -> HDC -> Handle to a Device Context 

	

	//������ ���ν������� ó������ ���� ������ �޼����� ó�����ش�.
	return _mg->MainProc(hWnd, iMessage, wParam, lParam);

}

//������ ȭ�� ���߱�
void SetWindowSize(int x, int y, int width, int height)
{
	//Ŭ���̾�Ʈ ������
	RECT rc = { 0,0,width,height };
	//���� ������ ũ�� ����
	AdjustWindowRect(&rc, WINSTYLE, false);

	//���� ��Ʈ�� ������ ������ ������ ����
	SetWindowPos(_hWnd, NULL, x, y, 
				(rc.right - rc.left),
				(rc.bottom - rc.top),
				SWP_NOZORDER | SWP_NOMOVE);// ZORDER�� ���� �ʰڴ�. �������� �ʰڴ�.

}

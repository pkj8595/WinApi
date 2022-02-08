#pragma once
#pragma comment(lib,"gdiplus")

/*
PreCompiled Header (PCH)
 - �ʿ��� ������ cpp �ϳ��� �����Ϸ��� �������Ͽ� .obj ������ �����, obj ���ϸ��� �ڵ� ����ȭ�� �Ź� �ϱ� ����� ������ ���ϸ��� �Ľ��� ����� �Ѵ�.
												�������� �� ������

-����ȭ�� ���ؼ�, ����ӵ� ����� ���ؼ� ����Ѵ�.
-������ �Ҷ����� �ø���� ����ӵ��� ������ ������ �޸𸮿� �̸� �÷����� ���ڴ�.
-���� ��������� ���� �ٲ��� �ʴ� ������ �ִ°� ����.
*/

//#include "targetver.h" // ������ os ȣȯ�� �� �ٵ� api������ 
// ���� ������ �ʴ� ������ Windows ������� �����մϴ�.

//���α׷����� ������ os�� ���� windows ������� 
//�ڵ忡 ���Ե� �Լ� ����� �����ϴµ� ���ȴ�.
#include <SDKDDKVer.h>	//os���� api�������� �������� �Լ����� �ٲ��ش�. ���?

//���� ������ �ʴ� ������ windows������� ����
//��GDI+�� ����ϸ� ������� �������� 
//<ole.h>	GDI+ �� ���� �ʿ�

//===================================
//! Windows ��� ����
//===================================
#define WIN32_LEAN_AND_MEAN             
#include <windows.h>

//!������ �ܼ�â
#pragma comment(linker, "/entry:WinMainCRTStartup /subsystem:console")

//===================================
//! C ��Ÿ�� ��� ����
//===================================
//stdlib c��� ǥ�� ���̺귯�� �Լ� ��� 
#include <stdlib.h>
#include <time.h>
#include <tchar.h>


//===================================
//! GDI+ connection
//===================================
#include <Ole2.h>//��ü ���� ����
#include <gdiplus.h>
using namespace Gdiplus;


//stdio ����� 
//#include <stdio.h>
//�޸� ���� ->C��� >> C++���� Ŭ������ ��������ʰ� ��������ֱ⶧���� �����ʴ�.
//#include <malloc.h>
//#include <memory.h>memset,mecpy,memmove

//�⺻������ �����ڵ� (���ڿ� ��� ��� ����)
/*
���ڿ� :
�����ڵ�(WBCS)  vs ��Ƽ����Ʈ(MBCS) 
�����̵� ����Ʈ ĳ���� ��		����Ƽ����Ʈ ĳ���ͼ�
���ڵ� ��Ģ:
��ǻ�� �ʱ⿡�� �ƽ�Ű OR EBCDIC �� �ΰ����� ���ؼ� ǥ���� �ߴ�.->��ǻ�Ϳ��� �ǻ�����
->�ǻ������� �Ҷ� ����� ���޵ǰ� ����� �� -> ����� 1����Ʈ �ѱ��� 2����Ʈ 

�̸� �ذ��ϱ� ���� ���°� ->�����ڵ� 
-> ����ǥ������ �������� -> ����+���ڿ�->��ǻ�Ϳ��� �ϰ��ǰ� ó���� �� �ְ�

*/

//===================================
//! C++ ��Ÿ�� ���
//===================================
#include <iostream>
#include <random>
//bitset: ��Ʈ������ ���� ���� �������ִ� �Լ��� �����Ѵ�.->STL
//-reset(),set(),flip(),all(),any()
#include <bitset>
#include <vector>
#include <map>
#include <cassert>
#include <typeinfo>

using namespace std;
//using namespace mycustom;

//===================================
//# ���� ���� ��������� �̰��� �߰� #
//===================================
#include "CommonMacroFunction.h"
#include "RandomFunction.h"
#include "KeyManager.h"
#include "ImageManager.h"
#include "FontManager.h"
#include "TempSoundManager.h"
#include "Utils.h"

using namespace MY_UTIL;
//===================================
//# custom #
//===================================
#include "Scene_inter.h"

//===================================
//# SingleTon #
//===================================
#define RND RandomFunction::getSingleton()
#define KEYMANAGER KeyManager::getSingleton()
#define IMAGEMANAGER ImageManager::getSingleton()
#define FONTMANAGER	FontManager::getSingleton()
#define TEMPSOUNDMANAGER TempSoundManager::getSingleton()


//===================================
//# ��ũ�� # (������ �ʱ�ȭ)
//===================================

#define WINNAME			(LPSTR)(TEXT("WindowAPI"))

//#define FULLSCREEN

#ifdef FULLSCREEN

//#ifdef FULLSCREEN
#define WINSTART_X		0
#define WINSTART_Y		0
//GetSystemMetrics() : ���ڷ� ���޵Ǵ� �ý��� �������� ��ȯ
//�� SM_CXSCREEN : ���� ȭ�� �ػ� X���ȯ
//�� SM_CYSCREEN : ���� ȭ�� �ػ� Y���ȯ
#define WINSIZE_X		GetSystemMetrics(SM_CXSCREEN)
#define WINSIZE_Y		GetSystemMetrics(SM_CYSCREEN)
#define WINSTYLE		WS_POPUPWINDOW | WS_MAXIMIZE

#else

#define WINSTART_X		350
#define WINSTART_Y		0
#define WINSIZE_X		1000
#define WINSIZE_Y		850
//#define WINSIZE_Y		700
//WS SYSMENU >> ������ ��� ��Ʈ�� �ڽ� 
//WINSTYLE WS_CAPTION ? 
#define WINSTYLE WS_CAPTION | WS_SYSMENU

#endif 

//===================================
//# ��ũ�� # (��� �� ȿ��)
//===================================
#define CENTER_X	WINSIZE_X/2
#define CENTER_Y	WINSIZE_Y/2


//===================================
//# ��ũ�� �Լ� # (Ŭ�������� ���� �Ҵ�� �κ� ����)
//===================================

#define SAFE_DELETE(p)			{if(p){delete (p); (p) = nullptr;}}
#define SAFE_DELETE_ARRAY(p)	{if(p){delete[](p); (p) = nullptr;}}
#define SAFE_RELEASE(p)			{if(p){(p)->release(); (p) = nullptr;} }


//����ǥ�� -> ���� ǥ�� ��ȯ
#define PI	3.141592653f
#define DEGREE_RADIAN(_deg)			(M_PI * (_deg)/180.0f)
//===================================
//# �������� #
//===================================
//��� cpp ���� ������ �����ؼ� ���� ����

extern HINSTANCE	_hInstance;
extern HWND			_hWnd;
extern POINT		_ptMouse;	// ���콺 ���� xy
//extern mycustom::Image _CImage;  //�����ε�

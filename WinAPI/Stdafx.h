#pragma once
#pragma comment(lib,"gdiplus")

/*
PreCompiled Header (PCH)
 - 필요한 이유는 cpp 하나당 컴파일러가 컴파일하여 .obj 파일을 만들고, obj 파일마다 코드 최적화를 매번 하기 힘들기 때문에 파일마다 파싱을 해줘야 한다.
												ㄴ컴파일 된 파일을

-최적화를 위해서, 실행속도 향상을 위해서 사용한다.
-컴파일 할때마다 올리기는 실행속도가 느리기 때문에 메모리에 미리 올려놓고 쓰겠다.
-자주 사용하지만 자주 바뀌지 않는 파일을 넣는게 좋다.
*/

//#include "targetver.h" // 윈도우 os 호환시 씀 근데 api에서는 
// 거의 사용되지 않는 내용을 Windows 헤더에서 제외합니다.

//프로그램에서 지원할 os에 따라 windows 헤더에서 
//코드에 포함될 함수 상수를 제어하는데 사용된다.
#include <SDKDDKVer.h>	//os마다 api한정으로 공통적인 함수들을 바꿔준다. 어뎁터?

//거의 사용되지 않는 내용은 windows헤더에서 제외
//ㄴGDI+를 사용하면 헤더파일 봉인해제 
//<ole.h>	GDI+ 를 쓸때 필요

//===================================
//! Windows 헤더 파일
//===================================
#define WIN32_LEAN_AND_MEAN             
#include <windows.h>

//!디버깅용 콘솔창
#pragma comment(linker, "/entry:WinMainCRTStartup /subsystem:console")

//===================================
//! C 런타임 헤더 파일
//===================================
//stdlib c언어 표준 라이브러리 함수 헤더 
#include <stdlib.h>
#include <time.h>
#include <tchar.h>


//===================================
//! GDI+ connection
//===================================
#include <Ole2.h>//객체 연결 삽입
#include <gdiplus.h>
using namespace Gdiplus;


//stdio 입출력 
//#include <stdio.h>
//메모리 관리 ->C언어 >> C++에선 클래스를 고려하지않고 만들어져있기때문에 좋지않다.
//#include <malloc.h>
//#include <memory.h>memset,mecpy,memmove

//기본적으로 유니코드 (문자열 출력 헤더 포함)
/*
문자열 :
유니코드(WBCS)  vs 멀티바이트(MBCS) 
ㄴ와이드 바이트 캐릭터 셋		ㄴ멀티바이트 캐릭터셋
인코딩 규칙:
컴퓨터 초기에는 아스키 OR EBCDIC 이 두가지를 통해서 표현을 했다.->컴퓨터에게 의사전달
->의사전달을 할때 영어로 전달되게 만들어 짐 -> 영어는 1바이트 한글은 2바이트 

이를 해결하기 위해 나온게 ->유니코드 
-> 국제표준으로 관리하자 -> 문자+문자열->컴퓨터에게 일관되게 처리할 수 있게

*/

//===================================
//! C++ 런타임 헤더
//===================================
#include <iostream>
#include <random>
//bitset: 비트연산을 좀더 쉽게 관리해주는 함수를 지원한다.->STL
//-reset(),set(),flip(),all(),any()
#include <bitset>
#include <vector>
#include <map>
#include <cassert>
#include <typeinfo>

using namespace std;
//using namespace mycustom;

//===================================
//# 내가 만든 헤더파일을 이곳에 추가 #
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
//# 매크로 # (윈도우 초기화)
//===================================

#define WINNAME			(LPSTR)(TEXT("WindowAPI"))

//#define FULLSCREEN

#ifdef FULLSCREEN

//#ifdef FULLSCREEN
#define WINSTART_X		0
#define WINSTART_Y		0
//GetSystemMetrics() : 인자로 전달되는 시스템 설정정보 반환
//ㄴ SM_CXSCREEN : 현재 화면 해상도 X축반환
//ㄴ SM_CYSCREEN : 현재 화면 해상도 Y축반환
#define WINSIZE_X		GetSystemMetrics(SM_CXSCREEN)
#define WINSIZE_Y		GetSystemMetrics(SM_CYSCREEN)
#define WINSTYLE		WS_POPUPWINDOW | WS_MAXIMIZE

#else

#define WINSTART_X		350
#define WINSTART_Y		0
#define WINSIZE_X		1000
#define WINSIZE_Y		850
//#define WINSIZE_Y		700
//WS SYSMENU >> 오른쪽 상단 컨트롤 박스 
//WINSTYLE WS_CAPTION ? 
#define WINSTYLE WS_CAPTION | WS_SYSMENU

#endif 

//===================================
//# 매크로 # (기능 및 효율)
//===================================
#define CENTER_X	WINSIZE_X/2
#define CENTER_Y	WINSIZE_Y/2


//===================================
//# 매크로 함수 # (클래스에서 동적 할당된 부분 해제)
//===================================

#define SAFE_DELETE(p)			{if(p){delete (p); (p) = nullptr;}}
#define SAFE_DELETE_ARRAY(p)	{if(p){delete[](p); (p) = nullptr;}}
#define SAFE_RELEASE(p)			{if(p){(p)->release(); (p) = nullptr;} }


//각도표기 -> 라디안 표기 변환
#define PI	3.141592653f
#define DEGREE_RADIAN(_deg)			(M_PI * (_deg)/180.0f)
//===================================
//# 전역변수 #
//===================================
//헤더 cpp 에서 변수를 공유해서 쓰기 위함

extern HINSTANCE	_hInstance;
extern HWND			_hWnd;
extern POINT		_ptMouse;	// 마우스 사용시 xy
//extern mycustom::Image _CImage;  //깡통인데

#pragma once
#include "SimpleTranslate.h"
enum blockType 
{

};

class CBlock :public SimpleTranslate 
{
private:
	WCHAR* _imgStr;
	Gdiplus::RectF _rc;
	int _time;
	bool _isActive;
	float _size;

public:
	
	Gdiplus::RectF getRect() { return _rc; }
	WCHAR* getImageStr() { return _imgStr; }
	int getTime() { return _time; }
	float getSize() { return _size; }
	bool getIsActive() { return _isActive; }

	void setRect(Gdiplus::RectF rc) { _rc = rc; }
	void setImageStr(WCHAR* img) { _imgStr = img; }
	void setTime(int time) { _time = time; }
	void setSize(float size) { _size = size; }
	void setIsActive(bool isActive) { _isActive = isActive; }

	void update(int time);
	void render(Gdiplus::Graphics &g);

	CBlock() :_rc(RectF{ 0,0,0,0 }), _imgStr(NULL),_time(5000),_isActive(false),_size(4){}
	CBlock(WCHAR* imgStr, int time, float size=4) {
		_imgStr = imgStr;
		_size = size;
		_time = time;
	}
	~CBlock() {}
};


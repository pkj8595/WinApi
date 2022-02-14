#pragma once
class HpImgBar
{
private:
	my::Image* _baseImage;
	my::Image* _valImage;

	RECT _rc;
	float* _x;
	float* _y;
	float _maxHp;
	int* _hp;
	int _offsetX;
	int _offsetY;


public:
	HpImgBar() {}
	~HpImgBar() {}

	HRESULT init(float* x,float* y,int* hp,int offsetX,int offsetY );
	void release(void);
	void update(void);
	void render(HDC hdc);

};


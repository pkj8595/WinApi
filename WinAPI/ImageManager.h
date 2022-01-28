#pragma once
#include "SingletonBase.h"
#include "Image.h"

/*
STL ���� �ٽ�
- Ű , ���� ��������
- ù��° first -> Ű
- �ι�° second ->��
- �߰��ϴ� �����  insert�� ����ϰ� Ű�� ��� �ΰ��� ���ÿ� �߰��ؾ��ϴ�
  pair or make_pair�� ����Ͽ� �߰��Ѵ�.

-pair() : �ΰ��� �ڷ����� �ϳ��� ���� ����ü (���ø� ����ü�̱⿡ ��ڷ����� �͵� OK)
-make_pair() : �� �׷��� pair�� ����� �ִ� �Լ�
	�� p.first = x, p.seconcd= y; �̷� ���¸� 
	��p = make_pair(x,y): ���·� 
-�ϳ��� Ű�� �������� ���� �����ϰ� ������ <multimap>
- pair ��ü�� Ȯ����� ����ϰ� ������ <tuple>�� �������
*/

//_CImage ;
//class mycustom::mycustom::Image;
//typeid(_CImage);
//using mycustom::Image;
//::�� �������� ����� �ڷ����̳� ������ �켱������ �����´�.

class ImageManager : public SingletonBase<ImageManager>
{
	//typeid(_CImage);
private:
	//������ ���� �̹��� ���
	typedef map<string, mycustom::Image*> mapImageList;
	//������ ���� �̹��� ����� �ݺ���
	typedef map<string, mycustom::Image*>::iterator mapImageIter;

private:
	mapImageList _mImageList;


public:
	HRESULT init(void);
	void release(void);


	mycustom::Image* addImage(string strKey, int width, int height);
	mycustom::Image* addImage(string strKey, const char* fileName, int width, int height, BOOL isTrans = FALSE, COLORREF transColor = RGB(0, 0, 0));
	mycustom::Image* addImage(string strKey, const char* fileName, float x, float y, int width, int height, BOOL isTrans = FALSE, COLORREF transColor = RGB(0, 0, 0));
	mycustom::Image* addFrameImage(string strKey, const char* fileName, int width, int height, int maxFrameX, int maxFrameY, BOOL isTrans = FALSE, COLORREF transColor = RGB(0, 0, 0));		 
	mycustom::Image* addFrameImage(string strKey, const char* fileName, float x, float y, int width, int height, int maxFrameX, int maxFrameY, BOOL isTrans = FALSE, COLORREF transColor = RGB(0, 0, 0));

	mycustom::Image* findImage(string strKey);
	bool deleteImage(string strKey);
	bool deleteAll();

	void render(string strKey,HDC hdc);
	void render(string strKey,HDC hdc, int destX, int destY);
	void render(string strKey,HDC hdc, int destX, int destY, int sourX, int sourY, int sourWidth, int sourHeight);

	void alphaRender(string strKey, HDC hdc, BYTE alpha);
	void alphaRender(string strKey, HDC hdc, int destX, int destY, BYTE alpha);
	void alphaRender(string strKey, HDC hdc, int destX, int destY, int sourX, int sourY, int sourWidth, int sourHeight, BYTE alpha);

	void frameRender(string strKey, HDC hdc, int destX, int destY);
	void frameRender(string strKey, HDC hdc, int destX, int destY, int currentFrameX, int currentFrameY);

	void loopRender(string strKey, HDC hdc, const LPRECT drawArea, int offsetX, int offsetY);
	void loopAlphaRender(string strKey, HDC hdc, const LPRECT drawArea, int offsetX, int offsetY, BYTE alpha);

	ImageManager() {}
	~ImageManager() {}
};


#include "Stdafx.h"
#include "Image.h"

//���ĺ��带 ����ϱ����� ���̺귯�� �߰�
#pragma comment (lib, "msimg32.lib")


namespace my {

	//��� �̴ϼȶ���� ������ ��Ӱ� ��������.
	//����� ���� Ŭ������ ������ ȣ���� �߻��� �ʰ� ���ÿ� �ʱ�ȭ

	Image::Image() : _imageInfo(NULL),
		_fileName(NULL),
		_isTrans(FALSE),
		_transColor(RGB(0, 0, 0)),
		_blendImage(NULL)
	{
	}

	HRESULT Image::init(int width, int height)
	{
		// ���ʱ�ȭ ���� -> �̹��� ������ ���� ��� �ִٸ� ��������� �ϰڴ�. (�����Ͱ� �ִٸ� if������ �����)
		if (_imageInfo != NULL) this->release();

		//��Ÿ��	(���Ʈ�� false���� ������) >> ����x �ɸ��� ã���� ���
		//assert(_imageInfo != NULL);
		//������ �ܰ迡�� ���Ʈ�ɸ��� ���� -> ������ ������ ���Ÿ�Ե� ������ ���
		//static_assert

		// DC ��������
		HDC hdc = GetDC(_hWnd);

		//�̹��� ���� ���� ���� �� �ʱ�ȭ
		_imageInfo = new IMAGE_INFO;
		_imageInfo->loadType = LOAD_EMPTY;
		_imageInfo->resID = 0;
		_imageInfo->hMemDc = CreateCompatibleDC(hdc);
		_imageInfo->hBit = (HBITMAP)CreateCompatibleBitmap(hdc, width, height);
		_imageInfo->hOBit = (HBITMAP)SelectObject(_imageInfo->hMemDc, _imageInfo->hBit);
		_imageInfo->width = width;
		_imageInfo->height = height;

		//���� �̸�
		_fileName = NULL;
		_isTrans = FALSE;
		_transColor = RGB(0, 0, 0);

		if (_imageInfo->hBit == 0)
		{
			release();
			return E_FAIL;
		}

		//DC ����
		ReleaseDC(_hWnd, hdc);

		//��Ÿ��
		//assert(_imageInfo != NULL); (���� ���ִٸ� �ڵ尡 �׾������
		//������
		//static_assert
		return S_OK;
	}

	HRESULT Image::init(const DWORD resID, int width, int height, BOOL isTrans, COLORREF transColor)
	{
		if (_imageInfo != NULL) this->release();

		HDC hdc = GetDC(_hWnd);

		//�̹��� ���� ���� ���� �� �ʱ�ȭ
		_imageInfo = new IMAGE_INFO;
		_imageInfo->loadType = LOAD_RESOURCE;
		_imageInfo->resID = resID;
		_imageInfo->hMemDc = CreateCompatibleDC(hdc);
		_imageInfo->hBit = (HBITMAP)LoadBitmap(_hInstance, MAKEINTRESOURCE(_imageInfo->resID));
		_imageInfo->hOBit = (HBITMAP)SelectObject(_imageInfo->hMemDc, _imageInfo->hBit);
		_imageInfo->width = width;
		_imageInfo->height = height;

		//���� �̸�
		_fileName = NULL;
		_isTrans = isTrans;
		_transColor = transColor;

		if (_imageInfo->hBit == 0)
		{
			release();
			return E_FAIL;
		}
		//DC ����
		ReleaseDC(_hWnd, hdc);

		return S_OK;
	}

	HRESULT Image::init(const char *fileName, int width, int height, BOOL isTrans, COLORREF transColor)
	{
		if (_imageInfo != NULL) this->release();

		HDC hdc = GetDC(_hWnd);

		//�̹��� ���� ���� ���� �� �ʱ�ȭ
		_imageInfo = new IMAGE_INFO;
		_imageInfo->loadType = LOAD_FILE;
		_imageInfo->resID = 0;
		_imageInfo->hMemDc = CreateCompatibleDC(hdc);

		_imageInfo->hBit = (HBITMAP)LoadImage(_hInstance, fileName, IMAGE_BITMAP, width, height, LR_LOADFROMFILE); //LR_LOADFROMFILE : �ε� ���ҽ�
		_imageInfo->hOBit = (HBITMAP)SelectObject(_imageInfo->hMemDc, _imageInfo->hBit);
		_imageInfo->width = width;
		_imageInfo->height = height;


		int len = strlen(fileName);
		//������ +1�ϴ� ���� ���� �Ǽ� ����
		_fileName = new CHAR[len + 1];//ũ�� �Ҵ�(����)
		strcpy_s(_fileName, len + 1, fileName);

		//���� �̸�
		_isTrans = isTrans;
		_transColor = transColor;

		// ���ҽ� �����µ� �����ߴ�.
		if (_imageInfo->hBit == 0)
		{
			release();
			return E_FAIL;
		}
		//DC ����
		ReleaseDC(_hWnd, hdc);

		return S_OK;
	}

	HRESULT Image::init(const char* fileName, float x, float y, int width, int height, BOOL isTrans, COLORREF transColor)
	{
		if (_imageInfo != NULL) this->release();

		HDC hdc = GetDC(_hWnd);

		//�̹��� ���� ���� ���� �� �ʱ�ȭ
		_imageInfo = new IMAGE_INFO;
		_imageInfo->loadType = LOAD_FILE;
		_imageInfo->resID = 0;
		_imageInfo->hMemDc = CreateCompatibleDC(hdc);

		_imageInfo->hBit = (HBITMAP)LoadImage(_hInstance, fileName, IMAGE_BITMAP, width, height, LR_LOADFROMFILE); //LR_LOADFROMFILE : �ε� ���ҽ�
		_imageInfo->hOBit = (HBITMAP)SelectObject(_imageInfo->hMemDc, _imageInfo->hBit);
		_imageInfo->x = x;
		_imageInfo->y = y;
		_imageInfo->width = width;
		_imageInfo->height = height;


		int len = strlen(fileName);
		//������ +1�ϴ� ���� ���� �Ǽ� ����
		_fileName = new CHAR[len + 1];//ũ�� �Ҵ�(����)
		strcpy_s(_fileName, len + 1, fileName);

		//���� �̸�
		_isTrans = isTrans;
		_transColor = transColor;

		// ���ҽ� �����µ� �����ߴ�.
		if (_imageInfo->hBit == 0)
		{
			release();
			return E_FAIL;
		}
		//DC ����
		ReleaseDC(_hWnd, hdc);

		return S_OK;
	}

	HRESULT Image::init(const char* fileName, int width, int height, int maxFrameX, int maxFrameY, BOOL isTrans, COLORREF transColor)
	{
		if (_imageInfo != NULL) this->release();

		HDC hdc = GetDC(_hWnd);

		//�̹��� ���� ���� ���� �� �ʱ�ȭ
		_imageInfo = new IMAGE_INFO;
		_imageInfo->loadType = LOAD_FILE;
		_imageInfo->resID = 0;
		_imageInfo->hMemDc = CreateCompatibleDC(hdc);

		_imageInfo->hBit = (HBITMAP)LoadImage(_hInstance, fileName, IMAGE_BITMAP, width, height, LR_LOADFROMFILE); //LR_LOADFROMFILE : �ε� ���ҽ�
		_imageInfo->hOBit = (HBITMAP)SelectObject(_imageInfo->hMemDc, _imageInfo->hBit);
		_imageInfo->width = width;
		_imageInfo->height = height;
		_imageInfo->currentFrameX = 0;
		_imageInfo->currentFrameY = 0;
		_imageInfo->maxFrameX = maxFrameX - 1;
		_imageInfo->maxFrameY = maxFrameY - 1;
		_imageInfo->frameWidth = width / maxFrameX;
		_imageInfo->frameHeight = height / maxFrameY;


		int len = strlen(fileName);
		//������ +1�ϴ� ���� ���� �Ǽ� ����
		_fileName = new CHAR[len + 1];//ũ�� �Ҵ�(����)
		strcpy_s(_fileName, len + 1, fileName);

		//���� �̸�
		_isTrans = isTrans;
		_transColor = transColor;

		// ���ҽ� �����µ� �����ߴ�.
		if (_imageInfo->hBit == 0)
		{
			release();
			return E_FAIL;
		}
		//DC ����
		ReleaseDC(_hWnd, hdc);

		return S_OK;
	}

	HRESULT Image::init(const char* fileName, float x, float y, int width, int height, int maxFrameX, int maxFrameY, BOOL isTrans, COLORREF transColor)
	{
		if (_imageInfo != NULL) this->release();

		HDC hdc = GetDC(_hWnd);

		//�̹��� ���� ���� ���� �� �ʱ�ȭ
		_imageInfo = new IMAGE_INFO;
		_imageInfo->loadType = LOAD_FILE;
		_imageInfo->resID = 0;
		_imageInfo->hMemDc = CreateCompatibleDC(hdc);

		_imageInfo->hBit = (HBITMAP)LoadImage(_hInstance, fileName, IMAGE_BITMAP, width, height, LR_LOADFROMFILE); //LR_LOADFROMFILE : �ε� ���ҽ�
		_imageInfo->hOBit = (HBITMAP)SelectObject(_imageInfo->hMemDc, _imageInfo->hBit);
		_imageInfo->x = x;
		_imageInfo->y = y;
		_imageInfo->width = width;
		_imageInfo->height = height;
		_imageInfo->currentFrameX = 0;
		_imageInfo->currentFrameY = 0;
		_imageInfo->maxFrameX = maxFrameX - 1;
		_imageInfo->maxFrameY = maxFrameY - 1;
		_imageInfo->frameWidth = width / maxFrameX;
		_imageInfo->frameHeight = height / maxFrameY;


		int len = strlen(fileName);
		//������ +1�ϴ� ���� ���� �Ǽ� ����
		_fileName = new CHAR[len + 1];//ũ�� �Ҵ�(����)
		strcpy_s(_fileName, len + 1, fileName);

		//���� �̸�
		_isTrans = isTrans;
		_transColor = transColor;

		// ���ҽ� �����µ� �����ߴ�.
		if (_imageInfo->hBit == 0)
		{
			release();
			return E_FAIL;
		}
		//DC ����
		ReleaseDC(_hWnd, hdc);

		return S_OK;
	}

	HRESULT Image::initForAlphaBlend(void)
	{
		// DC ��������
		HDC hdc = GetDC(_hWnd);

		_blendFunc.BlendFlags = 0;			//ȥ�� ���İ��� ������� �ʰڴ�. 
		_blendFunc.AlphaFormat = 0;			//�ҽ��� ��Ʈ���� ȥ�ս�ų����
		_blendFunc.BlendOp = AC_SRC_OVER;	//��Ʈ���� 24bit or 32bit�� ������


		//�̹��� ���� ���� ���� �� �ʱ�ȭ
		_blendImage = new IMAGE_INFO;
		_blendImage->loadType = LOAD_FILE;
		_blendImage->resID = 0;
		_blendImage->hMemDc = CreateCompatibleDC(hdc);
		_blendImage->hBit = (HBITMAP)CreateCompatibleBitmap(hdc, _imageInfo->width, _imageInfo->height);
		_blendImage->hOBit = (HBITMAP)SelectObject(_blendImage->hMemDc, _blendImage->hBit);
		_blendImage->width = WINSIZE_X;
		_blendImage->height = WINSIZE_Y;

		//DC ����
		ReleaseDC(_hWnd, hdc);

		return S_OK;
	}

	void Image::setTransColor(BOOL isTrans, COLORREF transColor)
	{
		_isTrans = isTrans;
		_transColor = transColor;
	}

	void Image::release(void)
	{
		if (_imageInfo)
		{
			//�̹��� ����
			SelectObject(_imageInfo->hMemDc, _imageInfo->hOBit);
			DeleteObject(_imageInfo->hBit);
			DeleteDC(_imageInfo->hMemDc);

			SAFE_DELETE(_imageInfo);
			SAFE_DELETE_ARRAY(_fileName);

			_isTrans = FALSE;
			_transColor = RGB(0, 0, 0);
		}

		if (_blendImage)
		{
			SelectObject(_blendImage->hMemDc, _blendImage->hOBit);
			DeleteObject(_blendImage->hBit);
			DeleteDC(_blendImage->hMemDc);

			SAFE_DELETE(_blendImage);
		}
	}

	//���� (0, 0 ������ ����)
	void Image::render(HDC hdc)
	{

		if (_isTrans)
		{	//�׷����� ������ ������.
			//�̹��� ���� GDI translate >> ���簡 �� >> ���� 
			//�޸𸮿� ��� �����ϱ� ������ ���������� �Ͼ�� �ְڴ�.
			//�����̸� ��Ű��ó (���������� �Ͼ�....��)
			//GdiTransparentBlt(): ��Ʈ���� �ҷ��ö� Ư�� ������ �����ϰ� �������ִ� �Լ�
			GdiTransparentBlt
			(
				hdc,					//������ ����� DC(ȭ�鿡 ������))
				0,						//����� ���� ��ǥ X
				0,						//����� ���� ��ǥ Y
				_imageInfo->width,		//����� �̹��� ���� ũ��
				_imageInfo->height,		//����� �̹��� ���� ũ��
				_imageInfo->hMemDc,		//����� ��� �޸� DC
				0, 0,					//���� ���� ����
				_imageInfo->width,		//���� ���� ���� ũ��
				_imageInfo->height,		//���� ���� ���� ũ��
				_transColor				//������ �� ������ ����

			);
		}

		else
		{
			BitBlt(hdc, 0, 0, _imageInfo->width, _imageInfo->height, _imageInfo->hMemDc, 0, 0, SRCCOPY);
		}
	}

	void Image::render(HDC hdc, int destX, int destY)
	{
		if (_isTrans)
		{
			//GdiTransparentBlt(): ��Ʈ���� �ҷ��ö� Ư�� ������ �����ϰ� �������ִ� �Լ�
			GdiTransparentBlt
			(
				hdc,					//������ ����� DC (ȭ�� DC (ȭ�鿡 ������))
				destX,					//����� ���� ��ǥ X
				destY,					//����� ���� ��ǥ Y
				_imageInfo->width,		//����� �̹��� ���� ũ��
				_imageInfo->height,		//����� �̹��� ���� ũ��
				_imageInfo->hMemDc,		//����� ��� �޸� DC
				0, 0,					//���� ���� ����
				_imageInfo->width,		//���� ���� ���� ũ��
				_imageInfo->height,		//���� ���� ���� ũ��
				_transColor				//������ �� ������ ����

			);
		}

		else
		{
			//BitBit() : DC���� �������� ���� ��Ӻ������ִ� �Լ�
			//SRCCOPY : �ҽ� ������ ��� ������ �����Ѵ�.
			BitBlt(hdc, destX, destY, _imageInfo->width, _imageInfo->height, _imageInfo->hMemDc, 0, 0, SRCCOPY);
		}
	}

	//Ŭ����
	void Image::render(HDC hdc, int destX, int destY, int sourX, int sourY, int sourWidth, int sourHeight)
	{
		if (_isTrans)
		{
			//GdiTransparentBlt(): ��Ʈ���� �ҷ��ö� Ư�� ������ �����ϰ� �������ִ� �Լ�
			GdiTransparentBlt
			(
				hdc,					//������ ����� DC (ȭ�� DC (ȭ�鿡 ������))
				destX,					//����� ���� ��ǥ X
				destY,					//����� ���� ��ǥ Y
				sourWidth,				//����� �̹��� ���� ũ��
				sourHeight,				//����� �̹��� ���� ũ��
				_imageInfo->hMemDc,		//����� ��� �޸� DC
				sourX,					//�ڸ� ��ǥ x
				sourY,					//�ڸ� ��ǥ y
				sourWidth,				//�ڸ�ũ��
				sourHeight,				//�ڸ�ũ��
				_transColor				//������ �� ������ ����
			);
		}

		else
		{
			BitBlt(hdc, destX, destY, sourWidth, sourHeight, _imageInfo->hMemDc, sourX, sourY, SRCCOPY);
		}
	}

	void Image::alphaRender(HDC hdc, BYTE alpha)
	{
		//���� ���带 ó�� ����ϴ���?
		if (!_blendImage) initForAlphaBlend();

		_blendFunc.SourceConstantAlpha = alpha;

		if (_isTrans)
		{
			//1. ����ؾ��� DC�� �׷����ִ� ������ ���� �̹����� �׸���.

			BitBlt
			(
				_blendImage->hMemDc,
				0, 0,
				_imageInfo->width,
				_imageInfo->height,
				hdc,
				0, 0,
				SRCCOPY
			);
			//2. ���� �̹����� ����� ���� �� ���� �̹����� �׸���.

			GdiTransparentBlt
			(
				_blendImage->hMemDc,
				0, 0,
				_imageInfo->width,
				_imageInfo->height,
				_imageInfo->hMemDc,
				0, 0,
				_imageInfo->width,
				_imageInfo->height,
				_transColor
			);
			//3. ���� �̹����� ȭ�鿡 �׸���.
			AlphaBlend
			(
				hdc,
				0, 0,
				_imageInfo->width,
				_imageInfo->height,
				_blendImage->hMemDc,
				0, 0,
				_imageInfo->width,
				_imageInfo->height,
				_blendFunc
			);
		}
		else
		{
			// 3�� ���� �̹����� ȭ�鿡 �׸���.
			AlphaBlend
			(
				hdc,
				0, 0,
				_imageInfo->width,
				_imageInfo->height,
				_imageInfo->hMemDc,
				0, 0,
				_imageInfo->width,
				_imageInfo->height,
				_blendFunc
			);
		}
	}

	void Image::alphaRender(HDC hdc, int destX, int destY, BYTE alpha)
	{
		if (!_blendImage) initForAlphaBlend();

		_blendFunc.SourceConstantAlpha = alpha;

		if (_isTrans)
		{
			//1. ����ؾ��� DC�� �׷����ִ� ������ ���� �̹����� �׸���.
			BitBlt
			(
				_blendImage->hMemDc,
				0, 0,
				_imageInfo->width,
				_imageInfo->height,
				hdc,
				destX, destY,
				SRCCOPY
			);
			//2. ���� �̹����� ����� ���� �� ���� �̹����� �׸���.
			GdiTransparentBlt
			(
				_blendImage->hMemDc,
				0, 0,
				_imageInfo->width,
				_imageInfo->height,
				_imageInfo->hMemDc,
				0, 0,
				_imageInfo->width,
				_imageInfo->height,
				_transColor
			);

			AlphaBlend
			(
				hdc,
				destX, destY,
				_imageInfo->width,
				_imageInfo->height,
				_blendImage->hMemDc,
				0, 0,
				_imageInfo->width,
				_imageInfo->height,
				_blendFunc
			);
			//3. ���� �̹����� ȭ�鿡 �׸���.
		}
		else
		{
			AlphaBlend
			(
				hdc,
				destX, destY,
				_imageInfo->width,
				_imageInfo->height,
				_imageInfo->hMemDc,
				0, 0,
				_imageInfo->width,
				_imageInfo->height,
				_blendFunc
			);
		}
	}

	void Image::alphaRender(HDC hdc, int destX, int destY, int sourX, int sourY, int sourWidth, int sourHeight, BYTE alpha)
	{
	}

	void Image::frameRender(HDC hdc, int destX, int destY)
	{
		if (_isTrans)
		{
			//GdiTransparentBlt(): ��Ʈ���� �ҷ��ö� Ư�� ������ �����ϰ� �������ִ� �Լ�
			GdiTransparentBlt
			(
				hdc,					//������ ����� DC (ȭ�� DC (ȭ�鿡 ������))
				destX,					//����� ���� ��ǥ X
				destY,					//����� ���� ��ǥ Y
				_imageInfo->frameWidth,		//����� �̹��� ���� ũ��
				_imageInfo->frameHeight,		//����� �̹��� ���� ũ��
				_imageInfo->hMemDc,		//����� ��� �޸� DC
				_imageInfo->currentFrameX * _imageInfo->frameWidth,
				_imageInfo->currentFrameY * _imageInfo->frameHeight,
				_imageInfo->frameWidth,	//���� ���� ���� ũ��
				_imageInfo->frameHeight,		//���� ���� ���� ũ��
				_transColor				//������ �� ������ ����

			);
		}

		else
		{
			//BitBit() : DC���� �������� ���� ��Ӻ������ִ� �Լ�
			//SRCCOPY : �ҽ� ������ ��� ������ �����Ѵ�.
			BitBlt(hdc, destX, destY,
				_imageInfo->frameWidth,
				_imageInfo->frameHeight,
				_imageInfo->hMemDc,
				_imageInfo->currentFrameX * _imageInfo->frameWidth,
				_imageInfo->currentFrameY * _imageInfo->frameHeight, SRCCOPY);
		}
	}

	void Image::frameRender(HDC hdc, int destX, int destY, int currentFrameX, int currentFrameY)
	{
		//�̹��� ����ó��
		_imageInfo->currentFrameX = currentFrameX;
		_imageInfo->currentFrameY = currentFrameY;
		if (currentFrameX > _imageInfo->maxFrameX)
		{
			_imageInfo->currentFrameX = _imageInfo->maxFrameX;
		}
		if (currentFrameY > _imageInfo->maxFrameY)
		{
			_imageInfo->currentFrameY = _imageInfo->maxFrameY;
		}

		if (_isTrans)
		{
			//GdiTransparentBlt(): ��Ʈ���� �ҷ��ö� Ư�� ������ �����ϰ� �������ִ� �Լ�
			GdiTransparentBlt
			(
				hdc,
				destX,
				destY,
				_imageInfo->frameWidth,
				_imageInfo->frameHeight,
				_imageInfo->hMemDc,
				_imageInfo->currentFrameX * _imageInfo->frameWidth,
				_imageInfo->currentFrameY * _imageInfo->frameHeight,
				_imageInfo->frameWidth,	//���� ���� ���� ũ��
				_imageInfo->frameHeight,		//���� ���� ���� ũ��
				_transColor				//������ �� ������ ����

			);
		}

		else
		{
			BitBlt(hdc, destX, destY,
				_imageInfo->frameWidth,
				_imageInfo->frameHeight,
				_imageInfo->hMemDc,
				_imageInfo->currentFrameX * _imageInfo->frameWidth,
				_imageInfo->currentFrameY * _imageInfo->frameHeight, SRCCOPY);
		}
	}

	void Image::loopRender(HDC hdc, const LPRECT drawArea, int offsetX, int offsetY)
	{
		//offset ���� ������ ��� ������ �ϰڴ�.
		if (offsetX < 0) offsetX = _imageInfo->width + (offsetX % _imageInfo->width);
		if (offsetY < 0) offsetY = _imageInfo->height + (offsetY % _imageInfo->height);

		//�׷����� ���� ����
		RECT rcSour;
		int sourWidth;
		int sourHeight;

		//�׷����� DC ���� (ȭ��ũ��)
		RECT rcDest;

		//�׷��� �� ��ü ����
		int drawAreaX = drawArea->left;
		int drawAreaY = drawArea->top;
		int drawAreaW = drawArea->right - drawArea->left;
		int drawAreaH = drawArea->bottom - drawArea->top;


		//���� ��������
		for (int y = 0; y < drawAreaH; y += sourHeight)
		{
			//�ҽ� ������ ���̰��
			rcSour.top = (y + offsetY) % _imageInfo->height;
			rcSour.bottom = _imageInfo->height;
			sourHeight = rcSour.bottom - rcSour.top;

			//�ҽ������� �׸��� ȭ���� �Ѿ�ٸ�(ȭ������� ��������)
			if (y + sourHeight > drawAreaH)
			{
				//�Ѿ �׸��� ����ŭ �÷��ְڴ�.
				rcSour.bottom -= (y + sourHeight) - drawAreaH;
				sourHeight = rcSour.bottom - rcSour.top;
			}

			//�׷����� ���� 
			rcDest.top = y + drawAreaY;
			rcDest.bottom = rcDest.top + sourHeight;

			for (int x = 0; x < drawAreaW; x += sourWidth)
			{
				rcSour.left = (x + offsetX) % _imageInfo->width;
				rcSour.right = _imageInfo->width;
				sourWidth = rcSour.right - rcSour.left;

				if (x + sourWidth > drawAreaW)
				{
					rcSour.right -= (x + sourWidth) - drawAreaW;
					sourWidth = rcSour.right - rcSour.left;
				}
				rcDest.left = x + drawAreaX;
				rcDest.right = rcDest.left + sourWidth;

				render(hdc, rcDest.left, rcDest.top, rcSour.left, rcSour.top, sourWidth, sourHeight);

			}
		}


	}

	void Image::loopAlphaRender(HDC hdc, const LPRECT drawArea, int offsetX, int offsetY, BYTE alpha)
	{

	}
}
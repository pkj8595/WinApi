#pragma once

// �ʿ��� �Լ��� ���� ����� �߰�

inline POINT PointMake(int  x, int y)
{
	POINT pt = {x, y};
	return pt;
}

inline void LineMake(HDC hdc,int startX,int startY,int endX,int endY)
{
	MoveToEx(hdc, startX, startY, NULL);
	LineTo(hdc, endX, endY);
}
	
inline RECT RectMake(int x, int y, int width, int height) 
{
	//todo
	RECT rc = { x, y,x + width,y + height };
	return rc;
}

//RECT �߽����� �����
inline RECT RectMakeCenter(int x, int y, int width, int height)
{
	RECT rc = { x - width / 2 , y - height / 2,x + width / 2 , y + height / 2, };
	return rc;

}

//�簢�� �׸��� 

inline void RectangleMake(HDC hdc, int x, int y, int width, int height) 
{
	Rectangle(hdc,x, y, x + width, y + height);
}

inline void RectangleMakeToRECT(HDC hdc, RECT rc)
{
	Rectangle(hdc, rc.left, rc.top, rc.right, rc.bottom);
}


inline void EllipsMake(HDC hdc, int x, int y, int width, int height) 
{
	Ellipse(hdc, x, y, x + width, y + width);
}

inline void EllipseMakeCenter(HDC hdc, int x, int y, int width, int height) 
{
	Ellipse(hdc, x - width / 2, y - height / 2, x + width / 2, y + height / 2);
}



inline int ChangeAlpha(int& alpha, int size)
{
	if (alpha < 0)
	{
		return 0;
	}
	else if (alpha > 255)
	{
		return 255;
	}
	alpha += size;

	return alpha;
}

inline bool RectCollider(RECT rcA, RECT rcB)
{
	if (rcA.left <= rcB.right  &&
		rcA.top <= rcB.bottom &&
		rcA.right >= rcB.left &&
		rcA.bottom >= rcB.top)
	{
		return true;
	}
	return false;
}


inline bool RectCollider2(RECT rcA, RECT rcB)
{
	if (rcA.left < rcB.right  &&
		rcA.top < rcB.bottom &&
		rcA.right > rcB.left &&
		rcA.bottom > rcB.top)
	{
		return true;
	}
	return false;
}


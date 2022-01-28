#pragma once
#include "MainGame.h"

#define _USE_MATH_DEFINES // �޽� ���� ��ƾ���
#include "math.h"

//�ﰢ�Լ�


	//point ����ϴ°� ����
struct STAR
{
	float x;
	float y;
};

struct ROTATE_RECT
{
	POINT p11;
	POINT p12;
	POINT p21;
	POINT p22;
};


class rotateRect : public Scene_inter
{


	//������Ʈ�� �븮�� 
	private:
		float _radian;
		float _degree;

		SYSTEMTIME _st;
		//��Ÿ
		HPEN	_currentPen;
		STAR _star[5];
		//�ð�
		POINT _h;
		POINT _m;
		POINT _s;
		POINT _clockText[12];

		POINT _rcPoint;
		RECT _rc;

		POINT _roRcPoint;
		ROTATE_RECT _roRc;
		float _rcDegree;

		POINT directionVector;
		POINT directionVector2;

		float x1;
		float y1;
		float x2;
		float y2;
		float z1;
		float z2;
		float r1;
		float r2;

		RECT _roRect;
		POINT rP;

		int _count;

		bool xDir;
		bool yDir;

		RECT _roRect0111;
		POINT _roPt0111;
		float _angle0111;

	public:
		virtual HRESULT init(void);
		virtual void release(void);
		virtual void update(void);	//�ﰢ�Լ��� update�� �߿�	
		virtual void render(HDC hdc);

		void RotateLineMake(POINT point, float radius, float degree);

		rotateRect() {}
		virtual ~rotateRect() {}
};


/*
�������� Ư¡ ������ ���� ������ ����ִ�.
�׷��ٸ� ���������� �Ÿ��� ����
���� �� �� �ִٸ� ���ϰ� �׸��� ������?
*/

/*
���� : ���п����� �ﰢ�Լ��� ���� �ﰢ���� ���� ���� �ﰢ�� ������ ���� ��� ��Ÿ���� �Լ� (���� �ﰢ���϶��� ����)

-���ӿ��� : ������ �̿��Ҷ� �ʿ��ϴ�.
	��	�߻�ü�� ������ ĳ������ �밢�� �̵� ���...

-����(sin)
: sin�� ���� �� ������ ����(�뺯)�� ������ �����ִ� �Լ�

-�ڻ���(cos)
:������ �غ��� ������ ������ִ� �Լ�

-ź��Ʈ(tan)
:���� �ﰢ������ ��� ������ �־��� �� �غ��� �뺯�� ������ �����ش�.

=============================================================

 - API ������ ������ ��ǥ�踦 ����Ѵ�. ->�Ϲ������� ����ϴ� ��ī��Ʈ ��ǥ��ʹ� �޸� Y���� �ݴ�� �Ǿ��ֱ� ������ Y�� ��ǥ�� ���Ҷ��� sin�տ� "���̳ʽ�"�� �ٿ��� �Ѵ�.

 ============================================================

 - ȣ���� : ��ǻ�ʹ� ������ �ν��� �� ���� ����� �� ����.
	��	������ ��Ÿ���� ǥ�� ��� �� �ϳ��� ȣ�� ���̷� ������ ��Ÿ����.
	��	PI�� ����� 180�� ������ ǥ���ϴ� �� -> ȣ����
	��	�������� ���̿� ���� ȣ�� ���� �߽ɰ��� 1ȣ��(����)��� �θ���.

 - Radian : ȣ������ ǥ���� �� ����ϴ� ����
	��	�������� ȣ�� ���̰� ���� ���� 1�������� �����Ѵ�.
	��	1 ���� = 57.3..��

 - Degree : �Ϲ������� ����ϴ� ���� ����(����)
	��	������ / ���� ǥ���� �Ҹ���.
	��	�ѹ����� 360���� �����Ѵ�.

 - 60�й� : ���� �ѷ��� 360����Ͽ� ���� ũ�⸦ ��Ÿ���� ���

 PI (������ : 3.14)
 ���� �ѷ� : 2* PI * ������
 ���� ���� : ������ * ������ * PI

 ## PI�� ���� ���� 180��

 180 Degree	=	PI Radian
 1 Degree	=	PI /180 radian
 x Degree	=	x * PI / 180 Radian

 PI Radian	=	180 Degree
 1 Radian	=	180 / PI Degree
 x Radian	=	x * 180 / PI Degree


 ## ��ä�� ��翡�� ������ , ȣ , �߽ɰ� 3������ 2������ �˸� �ٸ� �Ѱ����� ���� �� �ִ�.

 - �� �� ����� �Ÿ�
 -> ������ �ȴ�. -> ������ �Ÿ��� �ȴ�. -> ��ǥ�������� ���������� ����.
	�� End -> Start = �� �� ������ �Ÿ�

- �� �������� ���� (X,Y)������ ���̷��� ���Ѵ�.
	�� DeltaX, DeltaY

- �밢�� (����)�� �Ÿ�(��Ÿ����� ����)
	�� Distance = sqrt (DeltaX * Delta X + DeltaY * DeltaY)
	�� sqrt() : X�� �������� �����ִ� �Լ�

- ���� ���Ѵ�.
- float angle = acos(DeltaX / Distance); //��ũ -> ���ﰢ�Լ�
	�� ���ﰢ �Լ� : �ﰢ �Լ��� ��� ���� �־ ���� ���
		�� a or arc ������ ���ﰢ �Լ��� �ǹ��Ѵ�.
	�� �ﰢ �Լ� : ������ �־ ���

- ������ ���� �������� ���Ѵ�.
	�� float DeltaX = cos(radian) * Distance (�̵���(������));
	�� float DeltaY = -sin(radian) * Distance (�̵���(������));

- x �� ��ǥ ���ϱ�
-> x = cos(���� * PI / 180) * �ӵ�;

-y �� ��ǥ ���ϱ�
-> y�� = -sin(���� * PI / 180) * �ӵ�;



*/


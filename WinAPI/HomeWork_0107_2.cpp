#include "Stdafx.h"
#include "HomeWork_0107_2.h"

HRESULT HomeWork_0107_2::init(void)
{
	_cannon.angle = 90;		
	_cannon.length = 80;
	_cannon.radius = 50;
	_cannon.center.x = WINSIZE_X / 2;
	_cannon.center.y = WINSIZE_Y;

	for (int i = 0; i < 30;i++) 
	{
		_bullet[i].isFire = false;
	}

	return S_OK;
}

void HomeWork_0107_2::release(void)
{
}

void HomeWork_0107_2::update(void)
{
	if (KEYMANAGER->isStayKeyDown(VK_RIGHT)) 
		_cannon.angle -= 3;

	if (KEYMANAGER->isStayKeyDown(VK_LEFT)) 
		_cannon.angle += 3;

	if (KEYMANAGER->isOnceKeyDown(VK_SPACE)) 
	{
		Fire();
	}

	//���� ������ xy��ǥ
	_cannon.cannonEnd.x = cosf(_cannon.angle*(M_PI/180))*_cannon.length + _cannon.center.x;
	_cannon.cannonEnd.y = -sinf(_cannon.angle*(M_PI / 180))*_cannon.length + _cannon.center.y;


	//�浹����
	for (int i = 0; i < 30; i++)
	{
		if (!_bullet[i].isFire) continue;

		//y�� ������â�� ����������
		if (_bullet[i].rc.bottom >= WINSIZE_Y ||
			_bullet[i].rc.top <= 0)
		{
			_bullet[i].yDir++;
		}

		//x�� ������â�� ����������
		if (_bullet[i].rc.right >= WINSIZE_X ||
			_bullet[i].rc.left <= 0)
		{
			_bullet[i].xDir++;
		}

		float aX =0;
		float aY =0;
		float bX =0;
		float bY =0;
		float distance =0;
		for (int j = 0; j < 30; j++)
		{
			if (!_bullet[j].isFire || i == j) continue;
			//�߽��� ���
			aX = (_bullet[i].rc.left + _bullet[i].rc.right) / 2;
			aY = (_bullet[i].rc.top + _bullet[i].rc.bottom) / 2;
			bX = (_bullet[j].rc.left + _bullet[j].rc.right) / 2;
			bY = (_bullet[j].rc.top + _bullet[j].rc.bottom) / 2;
			distance = sqrt(((aX - bX) *(aX - bX)) + ((aY - bY) *(aY - bY)));
			//�������� �浹��
			if ((BULLET_RADIUS + BULLET_RADIUS) >= distance)
			{
				float intersectionDistance = (BULLET_RADIUS + BULLET_RADIUS) - distance;
				if (intersectionDistance >0)
				{
					_bullet[i].rc.left -= cosf( ((_bullet[i].xDir * M_PI) + (_bullet[i].angle)*(PI / 180)) ) * intersectionDistance/2;
					_bullet[i].rc.top -= -sinf(((_bullet[i].yDir * M_PI) + (_bullet[i].angle)*(PI / 180))) * intersectionDistance/2;
					_bullet[i].rc.right -= cosf(((_bullet[i].xDir * M_PI) + (_bullet[i].angle)*(PI / 180))) * intersectionDistance/2;
					_bullet[i].rc.bottom -= -sinf(((_bullet[i].yDir * M_PI) + (_bullet[i].angle)*(PI / 180))) * intersectionDistance/2;
				}

				//���� �ݻ簢 �Ի簢 ���
				ReflectionCircle( i, aY, bY, aX, bX);

				//���� �ʱ�ȭ
				_bullet[i].xDir = 0;
				_bullet[i].yDir = 0;
			}
		}
	}

	//�Ѿ� �̵�����
	for (int i = 0; i < 30; i++)
	{
		if (!_bullet[i].isFire) continue;
		/*
		_bullet[i].rc.left += 10 * cosf(_bullet[i].angle);
		_bullet[i].rc.top += 10 * -sinf(_bullet[i].angle);
		_bullet[i].rc.right += 10 * cosf(_bullet[i].angle);
		_bullet[i].rc.bottom += 10 * -sinf(_bullet[i].angle);
		*/

		/*
		//���� ��� �۾�����. ���� ����ĥ������ x�� y�� ������ ���̰� ���� �׷����ϴ�. 
		>>ȸ������� ���� ������ �̷��� �ʿ��Ѱ� �ʹ�.
		>>Ȥ�ó� �; ������ �����ϰ� ��ƺôµ� ��� ��׷� ����.
		>> ���̰� �������̱⶧���� �Ҽ��� �Ʒ��� ���� �߷������� �׷��ɱ�? 
		>>angle ���� 0 ~ 360 ������ ������ ������ָ� ��׷����� ������� ������? -> ���� ������ �ޱ۰��� �õ� �ٵ� 1~-1������ ���̴�.
		>>ANGLE ���� ���縻�� ���� ���������� ��׷�����. ??�� ��׷�����?
			�� RECT�� ����� LONG �������̶� �Ҽ��� ������ �������� ����.
			�� FLOAT RECT Ÿ���� ���� ����ϴ� ��׷����� �����
		*/

		//��ⷯ ������ ������������ �����ϴ�. 
		//_bullet[i].angle %= (M_PI * 2);


		_bullet[i].rc.left += BULLET_SPEED * cosf( ((_bullet[i].xDir * M_PI) + (_bullet[i].angle)*(PI/180)) );
		_bullet[i].rc.top += BULLET_SPEED * -sinf( ((_bullet[i].yDir * M_PI) + (_bullet[i].angle)*(PI / 180)) );
		_bullet[i].rc.right += BULLET_SPEED * cosf( ((_bullet[i].xDir * M_PI) + (_bullet[i].angle)*(PI / 180)) );
		_bullet[i].rc.bottom += BULLET_SPEED * -sinf( ((_bullet[i].yDir * M_PI) + (_bullet[i].angle)*(PI / 180)) );
	}
	
}



void HomeWork_0107_2::render(HDC hdc)
{
	//���� �׸��� 
	LineMake(hdc, _cannon.center.x, _cannon.center.y, _cannon.cannonEnd.x, _cannon.cannonEnd.y);

	EllipseMakeCenter(hdc, _cannon.center.x, _cannon.center.y, _cannon.radius, _cannon.radius);

	for (int i = 0; i < 30; i++)
	{
		if (!_bullet[i].isFire) continue;
		Ellipse(hdc, _bullet[i].rc.left,
			_bullet[i].rc.top,
			_bullet[i].rc.right,
			_bullet[i].rc.bottom);

		//debug
		_stprintf_s(_bullet[i].teststr, "degree : %.0f x : %d y : %d" , _bullet[i].angle, _bullet[i].xDir%2 , _bullet[i].yDir % 2);
		TextOut(hdc, _bullet[i].rc.left-20, _bullet[i].rc.top + 20, _bullet[i].teststr, strlen(_bullet[i].teststr));

	}
}

void HomeWork_0107_2::ReflectionCircle(int index, float aY, float bY, float aX, float bX)
{
	float currentAngle;
	float seta;

	//���� �����̴� ���� ���ϱ�
	currentAngle = atan2f(
		sinf(((_bullet[index].yDir * M_PI) + (_bullet[index].angle))),
		cosf(((_bullet[index].xDir * M_PI) + (_bullet[index].angle)))
	);

	currentAngle *= (180 / M_PI);	//��׸���ȯ
	seta = atan2f((aY - bY), (aX - bX))* (180 / M_PI);//��׸���ȯ
	
	//�Ի簢�� �ݻ簢�� �հ踦 ���� �������� ���ֱ�
	_bullet[index].angle = currentAngle - (2 * (90 - ( seta- currentAngle )));
	
}

void HomeWork_0107_2::Fire(void)
{
	for (int i = 0; i < 30; i++)
	{
		if (_bullet[i].isFire) continue; 
		_bullet[i].isFire = true;
		_bullet[i].yDir = 0;
		_bullet[i].xDir = 0;
		_bullet[i].angle = _cannon.angle;
		_bullet[i].rc = FLOAT_RECT{ 
							_cannon.cannonEnd.x - BULLET_RADIUS,
							_cannon.cannonEnd.y - BULLET_RADIUS,
							_cannon.cannonEnd.x + BULLET_RADIUS,
							_cannon.cannonEnd.y + BULLET_RADIUS 
							};
		break;
	}
}


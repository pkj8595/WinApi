#pragma once
//===================================
//# Utils # (����ȭ ��Ű�� ���� ����,������ ��ɵ��� ��Ƶ� ��)
//===================================

//�ݿø�(6�ڸ������ۿ� �ȵ�)�� ������ ����� ����. 
#define DEG_TO_RAD		0.017453f
#define PI				3.141592653f
#define PI_2			6.283185308f

//���а� ������ ������
#define FLOAT_EPSILON	0.001f
//�Ǽ��� ���������� ��ȯ
#define FLOAT_TO_INT	static_cast<int>(f1+FLOAT_EPSILON)
//�� �Ǽ��� ������ ��
//�� fabs�� �Ҽ��� ���� ���밪 ��ȯ (abs->int)
#define FLOAT_EQUAL(f1,f2) (fabs(f1-f2)<= FLOAT_EPSILON)

/*
�ε��Ҽ��� -> �ε��Ҽ����� �Ǽ��� ��Ȯ�ϰ� ǥ���� �� ����.
 why -> �Ǽ��� ���������� �����ϴ�. -> ������ �Ǽ��� ������ ��Ʈ�� ǥ���Ϸ��� ���ϱ�
�� ��ǻ�ʹ� ��¿������ �ٻ簪���� ǥ���Ѵ�.
2d ���� ����� ũ�� �ν��� �������� 3d��ǥ�迡�� ���� �ٸ� ����� �߻��Ѵ�.
�� �ٻ簪�� �� ���� ���� - Rounding Error 
�ݿø� ���� 0.0009��ŭ �����̸� ���ڴ�. 
��ǻ�ʹ� �ٻ簪���� ǥ���ؼ� 0.001�� �ȴ�. 
�ٻ簪�� �����ϰ��� ���°� �۽Ƿи� ����.

���ʹϾ� 
���Ϸ� �ޱ�

*/

namespace MY_UTIL 
{
	float getDistance(float startX,float startY, float endX,float endY);
	float getAngle(float startX, float startY, float endX, float endY);
}

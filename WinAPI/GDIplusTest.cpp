#include "Stdafx.h"
#include "GDIplusTest.h"

HRESULT GDIplusTest::init(void)
{
	/*_rc.Width = 20;
	_rc.Height = 20;
	_rc.X = -1*(_rc.Width /2);
	_rc.Y = -1 * (_rc.Height / 2);
	_m.SetElements(1, 0, 0, 1, 300, 300);*/

	/*WCHAR* playerImg= L"Resource/Images/Popol/p2.png";
	WCHAR* bossface_s = L"Resource/Images/Popol/bossface_s.png";*/
	_time = 0;
	_timeStart = GetTickCount();
	_pt = PointF{ 400,400 };
	_angle = 0;

	for(int i =0; i<BLOCK_SIZE; i++)
	{
		_block[i].setImageStr(L"Resource/Images/Popol/arm2.png");
		_block[i].setPosition(PointF{0,0 });
		_block[i].setTime(RND->getFromIntTo(2000, 10000));
		_block[i].setSize(RND->getFromIntTo(1,4));
	}
	_count = 10;

	_topRc = RectF(0, 0, WINSIZE_X, 100);
	_downRc = RectF(0, WINSIZE_Y - 100, WINSIZE_X, 100);
	_gameStop = false;
	

	return S_OK;
}

void GDIplusTest::release(void)
{
}

void GDIplusTest::update(void)
{
	if (KEYMANAGER->isOnceKeyDown(VK_F1)) _gameStop = !_gameStop;
	if (_gameStop) return;

	_time = GetTickCount() - _timeStart;
	_cplayer.update(_time);
	//_m.RotateAt(_angle,_pt);
	_angle += 0.03f;

	_m.SetElements(cosf(_angle), sinf(_angle), -sinf(_angle), cosf(_angle), _pt.X, _pt.Y);


	_count -= 0.1f;
	for (int i = 0; i < BLOCK_SIZE; i++) 
	{
		
		if (_block[i].getIsActive())
		{
			/*cout << "블록생성 "<<i << endl;
			cout << "좌표 " << _block[i].getPosition().X <<", "<< _block[i].getPosition().Y << endl;*/
			_block[i].setAngle(_count);
			_block[i].setPosition(PointF(_block[i].getPosition().X-20, _block[i].getPosition().Y));
			_block[i].update(_time);

			if (_block[i].getPosition().X < -200)
			{
				_block[i].setTime(RND->getFromIntTo(_time, _time + 10000));
				_block[i].setIsActive(false);
			}
		}
		else 
		{
			cout << "time : " <<_time << "_blockTime : " << _block[i].getTime() << endl;
			if (_time >= _block[i].getTime())
			{
				PointF temp;
				temp.X = WINSIZE_X+200;
				temp.Y = (REAL)RND->getFromIntTo(150, WINSIZE_Y - 150);
				_block[i].setPosition(temp);
				_block[i].setSize(RND->getFromIntTo(1, 4));
				_block[i].setIsActive(true);
			}
		}

	}

	
}

void GDIplusTest::render(HDC hdc)
{
	Gdiplus::Graphics _g(getMemDC());

	_g.FillRectangle(&SolidBrush(Color(255, 32, 113)), _topRc);
	_g.FillRectangle(&SolidBrush(Color(255, 32, 113)), _downRc);

	//페이지 좌표계?
	//_g.SetPageUnit(UnitWorld);
	_g.SetTransform(&_m);
	Gdiplus::Image i(L"Resource/Images/Popol/NBbossFace_s.png");
	_g.DrawImage(&i,-200,-200,400,400);
	//_g.DrawImage(&i,-400,-400,800,800);
	_g.SetInterpolationMode(Gdiplus::InterpolationMode::InterpolationModeNearestNeighbor);

	//Graphics.InterpolationMode = InterpolationMode.NearestNeighbor;
	//_g.DrawImage(
	//	image,
	//	new Rectangle(10, 250, (int)(0.6 * width), (int)(0.6 * height)),
	//	// destination rectangle
	//	0,
	//	0,           // upper-left corner of source rectangle
	//	width,       // width of source rectangle
	//	height,      // height of source rectangle
	//	GraphicsUnit.Pixel);
	//block
	for(int i=0;i<BLOCK_SIZE; i++)
	{
		if(_block[i].getIsActive())
		{
			_block[i].render(_g);
		}
	}
	
	//player
	_cplayer.render(_g);
	



}

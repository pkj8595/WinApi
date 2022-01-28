#include "Stdafx.h"
#include "CBlock.h"

void CBlock::update(int time)
{

	matrixUpdate();
}

void CBlock::render(Gdiplus::Graphics& g)
{
	//// Load png from disc
	//Image png = Image.FromFile("x.png");
	//// Create a Bitmap of same size as png with the right PixelFormat
	//Bitmap bmp = new Bitmap(png.Width, png.Height, PixelFormat.Format32bppPArgb);
	//// Create a graphics object which draws to the bitmap
	//Graphics g = Graphics.FromImage(bmp);
	//// Draw the png to the bmp
	//g.DrawImageUnscaled(png, 0, 0);

	g.SetTransform(&getMatrix());
	if (_imgStr != NULL)
	{
		//cout << " CBlock::render >> "<< *_imgStr << endl;
		Gdiplus::Image img(_imgStr);
		INT x = static_cast<INT>((-1 * (img.GetWidth() / 2))) / _size;
		INT y = static_cast<INT>((-1 * (img.GetHeight() / 2))) / _size;
		INT w = static_cast<INT>(img.GetWidth()) / _size;
		INT h = static_cast<INT> (img.GetHeight()) / _size;

		g.DrawImage(&img, x, y, w, h);
	}

	
}

#include "paperengine/paperengine.hpp"

using namespace myun2::paperengine;

struct renderer
{
public:
	d3ddev &d;
	kb_input &kb;
	sprite img1;
	inertia<-3, 3> ix;
	inertia<0, 14>  iy;
	float x;
	limited<float, 0, 440> y;

	renderer(d3ddev &d_in, kb_input &kb_in)
		: d(d_in), kb(kb_in),
		  img1(d, "point.bmp")
	{
		x = y = 0;
	}

	void render()
	{
		ix.attenuate(0.05f);
		if ( kb.test(DIK_LEFT) )
			ix.increase(-0.1f);
		if ( kb.test(DIK_RIGHT) )
			ix.increase(0.1f);
		x += ix;

		iy.attenuate(0.1f);
		if ( kb.test(DIK_UP) ) {
			if ( iy < 8 )
				iy = 8;
			iy.increase(0.3f);
		}
		y -= (8 - iy);
		if ( y == 440 )
			iy = 8;

		d.clear(0xff000033);
		img1.render(x, 440 - y);
	}
};

RUN_PAPERENGINE("Paperengine", 640, 480, renderer)

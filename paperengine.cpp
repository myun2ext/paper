#include "paperengine/paperengine.hpp"

using namespace myun2::paperengine;

struct renderer
{
public:
	d3ddev &d;
	kb_input &kb;
	sprite img1;
	inertia ix, iy;
	float x, y;

	renderer(d3ddev &d_in, kb_input &kb_in)
		: d(d_in), kb(kb_in),
		  img1(d, "nagato.bmp") { x = y = 0; }

	void render()
	{
		ix.attenuate(); iy.attenuate();

		if ( kb.test(DIK_LEFT) )
			ix.increase();
		if ( kb.test(DIK_RIGHT) )
			ix.increase();
		x -= ix;
		if ( kb.test(DIK_UP) )
			y -= 1;
		if ( kb.test(DIK_DOWN) )
			y += 1;

		d.clear(0xff000033);
		img1.render(x, y);
	}
};

RUN_PAPERENGINE("Paperengine", 640, 480, renderer)

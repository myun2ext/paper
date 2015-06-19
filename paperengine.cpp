#include "paperengine/paperengine.hpp"

using namespace myun2::paperengine;

struct renderer
{
public:
	d3ddev &d;
	kb_input &kb;
	sprite img1;
	int x;

	renderer(d3ddev &d_in, kb_input &kb_in)
		: d(d_in), kb(kb_in),
		  img1(d, "nagato.bmp") { x = 0; }

	void render()
	{
		if ( kb.test(DIK_LEFT) )
			x -= 1;
		if ( kb.test(DIK_RIGHT) )
			x += 1;
		
		d.clear(0xff000033);
		img1.render(x);
	}
};

RUN_PAPERENGINE("Paperengine", 640, 480, renderer)

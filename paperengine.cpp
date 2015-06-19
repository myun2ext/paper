#include "paperengine/paperengine.hpp"

using namespace myun2::paperengine;

struct renderer
{
public:
	d3ddev &d;
	sprite img1;

	renderer(d3ddev &d_in)
		: d(d_in),
		  img1(d, "nagato.bmp") {}

	void render()
	{
		d.clear(0xff000033);
		img1.render();
	}
};

RUN_PAPERENGINE("Paperengine", 640, 480, renderer)

#include "paperengine/paperengine.hpp"

using namespace myun2::paperengine;

struct renderer
{
	void render(d3ddev &d)
	{
		d.clear(0xff000033);
	}
};

RUN_PAPERENGINE("Paperengine", 640, 480, renderer)

#include "paperengine/paperengine.hpp"
#include <vector>
#include <stdlib.h>

using namespace myun2::paperengine;
using namespace std;

struct renderer
{
	struct enemy {
		inertia<-3, 3> ix;
		inertia<0, 12> iy;
		limited<float, -20, 640> x;
		limited<float, -20, 480> y;
		enemy(int x_, int y_) : x(x_), y(y_) {}
		void next() {
		//	ix.attenuate(0.05f);
			iy.increase(0.1f);
			x += ix;
			y += iy;
		}
	};
	d3ddev &d;
	kb_input &kb;
	mouse_input &mouse;
	sprite point1;
	sprite point2;
	text   txt1;
	inertia<-3, 3> ix;
	inertia<0, 12>  iy;
	limited<float, 0, 608> x;
	limited<float, 0, 446> y;
	vector<enemy> enemies;
//	list<enemy>::iterator enemy_iterator;
	int time;
	int level;

	renderer(d3ddev &d_in, kb_input &kb_in, mouse_input &mouse_in)
		: d(d_in), kb(kb_in), mouse(mouse_in),
		  point1(d, "point.png"),
		  point2(d, "point2.png"),
		  txt1(d, 26, "Meiryo")
	{
		x = 0; y = 0;
		txt1 = "W/A/S/D で移動, クリックで何かが出る";
		time = 0;
		level = 0;
	}
	void render()
	{
    	ix.attenuate(0.05f);
		if ( kb.test(DIK_LEFT) || kb.test(DIK_A) )
			ix.increase(-0.12f);
		if ( kb.test(DIK_RIGHT) || kb.test(DIK_D) )
			ix.increase(0.12f);
		x += ix;

		iy.attenuate(0.1f);
		if ( kb.test(DIK_UP) || kb.test(DIK_W) ) {
			if ( y == 0 )
				iy = 6;
			iy.increase(0.3f);
		}
		if ( kb.test(DIK_DOWN) || kb.test(DIK_S) )
			iy.increase(-0.1f);
		y -= (6 - iy);
		if ( y == 446 )
			iy = 6;

		if ( time == 0 )
			enemies.push_back(enemy(rand() % 620, 0));
		time = (time + 1) % (2 - level);

		//	Render enemies
		for(int ei=0; ei<enemies.size(); ei++)
		{
			enemy &e = enemies[ei];
			point2.render(e.x, e.y);
			e.next();
		}
		point1.render(x, 446 - y);
		txt1.render();
	}
	void on_clicked(int x, int y){}
};

RUN_PAPERENGINE("Test", 640, 480, renderer)

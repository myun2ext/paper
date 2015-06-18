#include "paperengine/window_class.hpp"
#include "paperengine/window.hpp"
#include "paperengine/d3ddev.hpp"
#include "paperengine/input.hpp"
#include "paperengine/game/value.hpp"
#include <math.h>

using namespace myun2::paperengine;

int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPTSTR lpCmdLine, int nCmdShow)
{
	window_class wc("Paperengine");
	window w(wc.atom, "Paperengine", 640, 480);
	HWND hwnd = w.hWnd;

	direct3d d3d;
	d3ddev d(d3d, hwnd, 640, 480);
	w.show();
	dinput di(hInstance);
	kb_input kb(di, hwnd);

	inertia i = 0;
	MSG msg;
	do
	{
		if ( PeekMessage(&msg, NULL, 0, 0, PM_REMOVE) ) {
			TranslateMessage( &msg );
			DispatchMessage( &msg );
		}
		else
		{
			kb.update();
			if (kb.test(DIK_UP))
				i.up();
			else
				i.down();
			d.clear(0xff000000 + ease(i) * 255);
			d.begin();

			d.end();
			d.present();
		}
	}while(msg.message != WM_QUIT);

	return 0;
}

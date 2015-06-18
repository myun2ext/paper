#include "paperengine/window_class.hpp"
#include "paperengine/window.hpp"
#include "paperengine/direct3d.hpp"
#include "paperengine/d3ddev.hpp"

using namespace myun2::paperengine;

int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPTSTR lpCmdLine, int nCmdShow)
{
	window_class wc("Paperengine");
	window w(wc.atom, "Paperengine", 640, 480);
	HWND hWnd = w.hWnd;

	direct3d d3d;
	d3ddev d(d3d, hWnd, 640, 480);
	w.show();

	MSG msg;
	do
	{
		if ( PeekMessage(&msg, NULL, 0, 0, PM_REMOVE) ) {
			TranslateMessage( &msg );
			DispatchMessage( &msg );
		}
		else
		{
			d.clear(0xff0000ff);
			d.begin();

			d.end();
			d.present();
		}
	}while(msg.message != WM_QUIT);

	return 0;
}

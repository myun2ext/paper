#include "paperengine/window_class.hpp"
#include "paperengine/window.hpp"
#include "paperengine/direct3d.hpp"
#include "paperengine/d3ddev.hpp"
#include "paperengine/d3dfont.hpp"

#pragma comment(lib, "dxguid.lib")
#pragma comment(lib, "d3dx9.lib")
#include <tchar.h>
#include <d3dx9.h>

using namespace myun2::paperengine;

int APIENTRY _tWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPTSTR lpCmdLine, int nCmdShow)
{
	window_class wc("Paperengine");
	window w(wc.atom, "Paperengine", 640, 480);
	HWND hWnd = w.hWnd;

	direct3d d3d;
	d3ddev d(d3d, hWnd, 640, 480);
	w.show();

	d3dfont text(d);

	MSG msg;
	do
	{
		if ( PeekMessage(&msg, NULL, 0, 0, PM_REMOVE) ) {
			TranslateMessage( &msg );
			DispatchMessage( &msg );
		}
		else
		{
			d.clear();
			d.begin();

			text.render("Hello world.");

			d.end();
			d.present();
		}
	}while(msg.message != WM_QUIT);

	return 0;
}

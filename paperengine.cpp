#include "paperengine/window_class.hpp"
#include "paperengine/window.hpp"
#include "paperengine/direct3d.hpp"
#include "paperengine/d3ddev.hpp"

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

	int fontsize = 24;
	D3DXFONT_DESC lf = {fontsize, 0, 0, 1, 0, SHIFTJIS_CHARSET, OUT_TT_ONLY_PRECIS,
								PROOF_QUALITY, FIXED_PITCH | FF_MODERN, _T("MS Gothic")};

	LPD3DXFONT pD3DFont;
	if(FAILED(D3DXCreateFontIndirect(d.ptr, &lf, &pD3DFont))){
		return 0;
	}

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

			RECT r={0,0,0,0};
			pD3DFont->DrawText(NULL, _T("Hello World !"), -1, &r, DT_LEFT | DT_SINGLELINE | DT_NOCLIP, 0xffffffff);

			d.end();
			d.present();
		}
	}while(msg.message != WM_QUIT);

	return 0;
}

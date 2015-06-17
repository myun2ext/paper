#include "paperengine/window_class.hpp"
#include "paperengine/window.hpp"

#pragma comment(lib, "dxguid.lib")
#pragma comment(lib, "d3d9.lib")
#pragma comment(lib, "d3dx9.lib")

#include <tchar.h>
#include <d3d9.h>
#include <d3dx9.h>

using namespace myun2::paperengine;

int APIENTRY _tWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPTSTR lpCmdLine, int nCmdShow)
{
	window_class wc("Paperengine");
	window w(wc.atom, "Paperengine", 640, 480);
	HWND hWnd = w.hWnd;

	LPDIRECT3D9 g_pD3D;
	LPDIRECT3DDEVICE9 g_pD3DDev;
	if( !(g_pD3D = Direct3DCreate9( D3D_SDK_VERSION )) ) return 0;

	D3DPRESENT_PARAMETERS d3dpp = {640,480,D3DFMT_UNKNOWN,0,D3DMULTISAMPLE_NONE,0,
											D3DSWAPEFFECT_DISCARD,NULL,TRUE,TRUE,D3DFMT_D24S8,0,0}; 

	if( FAILED( g_pD3D->CreateDevice( D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL, hWnd, D3DCREATE_HARDWARE_VERTEXPROCESSING, &d3dpp, &g_pD3DDev ) ) )
	if( FAILED( g_pD3D->CreateDevice( D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL, hWnd, D3DCREATE_SOFTWARE_VERTEXPROCESSING, &d3dpp, &g_pD3DDev ) ) )
	if( FAILED( g_pD3D->CreateDevice( D3DADAPTER_DEFAULT, D3DDEVTYPE_REF, hWnd, D3DCREATE_HARDWARE_VERTEXPROCESSING, &d3dpp, &g_pD3DDev ) ) )
	if( FAILED( g_pD3D->CreateDevice( D3DADAPTER_DEFAULT, D3DDEVTYPE_REF, hWnd, D3DCREATE_SOFTWARE_VERTEXPROCESSING, &d3dpp, &g_pD3DDev ) ) )
	{
		g_pD3D->Release();
		return 0;
	}
	w.show();

	int fontsize = 24;
	D3DXFONT_DESC lf = {fontsize, 0, 0, 1, 0, SHIFTJIS_CHARSET, OUT_TT_ONLY_PRECIS,
								PROOF_QUALITY, FIXED_PITCH | FF_MODERN, _T("MS Gothic")};

	LPD3DXFONT pD3DFont;
	if(FAILED(D3DXCreateFontIndirect(g_pD3DDev, &lf, &pD3DFont))){
		g_pD3DDev->Release();  g_pD3D->Release();
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
			g_pD3DDev->Clear( 0, NULL, D3DCLEAR_TARGET | D3DCLEAR_STENCIL | D3DCLEAR_ZBUFFER, D3DCOLOR_XRGB(0,0,255), 1.0f, 0 );
			g_pD3DDev->BeginScene();

			RECT r={0,0,0,0};
			pD3DFont->DrawText(NULL, _T("Hello World !"), -1, &r, DT_LEFT | DT_SINGLELINE | DT_NOCLIP, 0xffffffff);

			g_pD3DDev->EndScene();
			g_pD3DDev->Present( NULL, NULL, NULL, NULL );
		}
	}while(msg.message != WM_QUIT);

	pD3DFont->Release();
	g_pD3DDev->Release();
	g_pD3D->Release();

	return 0;
}

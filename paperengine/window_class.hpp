#ifndef __MYUN2_GITHUB_COM__PAPER_ENGINE__WINDOW_CLASS_HPP__
#define __MYUN2_GITHUB_COM__PAPER_ENGINE__WINDOW_CLASS_HPP__

#include <windows.h>

namespace myun2
{
	namespace paperengine
	{
		class window_class
		{
		public:
			struct failed_register{};
			LRESULT CALLBACK static window_proc(HWND hWnd, UINT mes, WPARAM wParam, LPARAM lParam)
			{
				if(mes == WM_DESTROY) {
					PostQuitMessage(0);
					return 0;
				}
				return DefWindowProc(hWnd, mes, wParam, lParam);
			}
			WNDCLASSEX wc;
			ATOM atom;

			window_class(const char* class_name, HINSTANCE hInstance=NULL)
			{
				ZeroMemory(&wc, sizeof(wc));
				wc.cbSize 			= sizeof(WNDCLASSEX);
				wc.style 			= CS_HREDRAW | CS_VREDRAW;
				wc.lpfnWndProc 		= window_proc;
				wc.hInstance 		= hInstance;
				wc.hbrBackground	= (HBRUSH)(COLOR_WINDOW+1);
				wc.lpszClassName	= class_name;

				if(!(atom = RegisterClassEx(&wc)))
					throw failed_register();
			}
		};
	}
}

#endif///__MYUN2_GITHUB_COM__PAPER_ENGINE__WINDOW_CLASS_HPP__

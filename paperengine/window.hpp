#ifndef __MYUN2_GITHUB_COM__PAPER_ENGINE__WINDOW_HPP__
#define __MYUN2_GITHUB_COM__PAPER_ENGINE__WINDOW_HPP__

#include <windows.h>

namespace myun2
{
	namespace paperengine
	{
		class window
		{
		public:
			HWND hWnd;
			struct failed_create{};
			window(ATOM wndcls, const char* title, unsigned int width, unsigned int height, HINSTANCE hInstance=NULL)
			{
				if(!(hWnd = CreateWindow(
					(LPCTSTR)MAKELONG(wndcls, 0), title,
					WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, 0,
					width, height, NULL, NULL, hInstance, NULL)))
					throw failed_create();
			}
			void show() {
				ShowWindow(hWnd, SW_SHOWDEFAULT);
			}
		};
	}
}

#endif///__MYUN2_GITHUB_COM__PAPER_ENGINE__WINDOW_HPP__

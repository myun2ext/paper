#ifndef __MYUN2_GITHUB_COM__PAPER_ENGINE__DINPUT_HPP__
#define __MYUN2_GITHUB_COM__PAPER_ENGINE__DINPUT_HPP__

#include <dinput.h>
#pragma comment(lib, "dinput8.lib")
#include "auto_interface.hpp"

namespace myun2
{
	namespace paperengine
	{
		class dinput : public auto_interface<LPDIRECTINPUT8>
		{
		public:
			dinput(HINSTANCE hInstance = NULL)
			{
				if ( FAILED(DirectInput8Create(hInstance,
					DIRECTINPUT_VERSION, IID_IDirectInput8, (LPVOID*)&ptr, NULL)) )
					throw create_failed();
			}
		};
	}
}

#endif///__MYUN2_GITHUB_COM__PAPER_ENGINE__DINPUT_HPP__

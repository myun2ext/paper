#ifndef __MYUN2_GITHUB_COM__PAPER_ENGINE__D3DTEXTURE_HPP__
#define __MYUN2_GITHUB_COM__PAPER_ENGINE__D3DTEXTURE_HPP__

#pragma comment(lib, "d3dx9.lib")
#include <d3dx9.h>

#include "auto_interface.hpp"

namespace myun2
{
	namespace paperengine
	{
		class texture : public auto_interface<LPDIRECT3DTEXTURE9>
		{
		public:
			texture(d3ddev& d, const char* file_name)
			{
				if ( FAILED(D3DXCreateTextureFromFile(d.ptr, file_name, &ptr)) )
					throw create_failed();
			}
		};
	}
}

#endif///__MYUN2_GITHUB_COM__PAPER_ENGINE__D3DTEXTURE_HPP__

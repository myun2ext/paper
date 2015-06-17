#ifndef __MYUN2_GITHUB_COM__PAPER_ENGINE__DIRECT3D_HPP__
#define __MYUN2_GITHUB_COM__PAPER_ENGINE__DIRECT3D_HPP__

#include "auto_interface.hpp"
#pragma comment(lib, "d3d9.lib")
#include <d3d9.h>

namespace myun2
{
	namespace paperengine
	{
		class direct3d : public auto_interface<LPDIRECT3D9>
		{
		public:
			direct3d() {
				if( !(ptr = Direct3DCreate9( D3D_SDK_VERSION )) )
					throw create_failed();
			}
		};
	}
}

#endif///__MYUN2_GITHUB_COM__PAPER_ENGINE__DIRECT3D_HPP__

#ifndef __MYUN2_GITHUB_COM__PAPER_ENGINE__DIRECT3D_HPP__
#define __MYUN2_GITHUB_COM__PAPER_ENGINE__DIRECT3D_HPP__

#pragma comment(lib, "d3d9.lib")
#include <d3d9.h>

namespace myun2
{
	namespace paperengine
	{
		class direct3d
		{
		public:
			struct create_failed {};
			LPDIRECT3D9 ptr;
			direct3d() {
				if( !(ptr = Direct3DCreate9( D3D_SDK_VERSION )) )
					throw create_failed();
			}
			void release() {
				if ( ptr )
					if ( ptr->Release() )
						ptr = NULL;
			}
			virtual ~direct3d() { release(); }
		};
	}
}


#endif///__MYUN2_GITHUB_COM__PAPER_ENGINE__WINDOW_HPP__

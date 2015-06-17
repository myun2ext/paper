#ifndef __MYUN2_GITHUB_COM__PAPER_ENGINE__D3DDEV_HPP__
#define __MYUN2_GITHUB_COM__PAPER_ENGINE__D3DDEV_HPP__

#include "direct3d.hpp"

namespace myun2
{
	namespace paperengine
	{
		class d3ddev : public auto_interface<LPDIRECT3DDEVICE9>
		{
		public:
			d3ddev(direct3d &d3d, HWND hwnd, unsigned int width, unsigned int height)
			{
				D3DPRESENT_PARAMETERS d3dpp = {
					width, height ,D3DFMT_UNKNOWN, 0, D3DMULTISAMPLE_NONE, 0,
					D3DSWAPEFFECT_DISCARD, NULL, TRUE, TRUE, D3DFMT_D24S8, 0, 0
				}; 

				if( FAILED( d3d.ptr->CreateDevice( D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL, hwnd, D3DCREATE_HARDWARE_VERTEXPROCESSING, &d3dpp, &ptr ) ) )
				if( FAILED( d3d.ptr->CreateDevice( D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL, hwnd, D3DCREATE_SOFTWARE_VERTEXPROCESSING, &d3dpp, &ptr ) ) )
				if( FAILED( d3d.ptr->CreateDevice( D3DADAPTER_DEFAULT, D3DDEVTYPE_REF, hwnd, D3DCREATE_HARDWARE_VERTEXPROCESSING, &d3dpp, &ptr ) ) )
				if( FAILED( d3d.ptr->CreateDevice( D3DADAPTER_DEFAULT, D3DDEVTYPE_REF, hwnd, D3DCREATE_SOFTWARE_VERTEXPROCESSING, &d3dpp, &ptr ) ) )
				{
					throw create_failed();
				}
			}

			void clear(D3DCOLOR color = 0, const D3DRECT *rect = NULL)
			{
				ptr->Clear(0, rect,
					D3DCLEAR_TARGET | D3DCLEAR_STENCIL | D3DCLEAR_ZBUFFER,
					color, 1.0f, 0);
			}
			void begin() {
				ptr->BeginScene();
			}
			void end() {
				ptr->EndScene();
			}
			void present() {
				ptr->Present(0,0,0,0);
			}
		};
	}
}


#endif//__MYUN2_GITHUB_COM__PAPER_ENGINE__D3DDEV_HPP__

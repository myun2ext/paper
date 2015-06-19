#ifndef __MYUN2_GITHUB_COM__PAPER_ENGINE__SPRITE_HPP__
#define __MYUN2_GITHUB_COM__PAPER_ENGINE__SPRITE_HPP__

#include "texture.hpp"
#include "auto_interface.hpp"

namespace myun2
{
	namespace paperengine
	{
		class sprite : public auto_interface<LPD3DXSPRITE>
		{
			texture tex;
		public:
			/*sprite(d3ddev& d, texture& tex_in) : tex(tex_in)
			{
				D3DXCreateSprite(d.ptr, &ptr);
			}*/
			sprite(d3ddev& d, const char* file_name)
				: tex(d, file_name)
			{
				if ( FAILED(D3DXCreateSprite(d.ptr, &ptr)) )
					throw create_failed();;
			}
			void render(int left = 0, int top = 0, D3DCOLOR color = 0xFFFFFFFF)
			{
				RECT rc;
				D3DXVECTOR3 center , position;

				rc.left    = 0;
				rc.top     = 0;
				rc.right   = 9999;
				rc.bottom  = 9999;
				center.x   = 0;
				center.y   = 0;
				position.x = left;
				position.y = top;

				ptr->Begin(0);
				ptr->Draw(tex.ptr, &rc, &center, &position, color);
				ptr->End();
			}
		};
	}
}

#endif///__MYUN2_GITHUB_COM__PAPER_ENGINE__SPRITE_HPP__

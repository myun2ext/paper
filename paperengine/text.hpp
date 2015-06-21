#ifndef __MYUN2_GITHUB_COM__PAPER_ENGINE__D3DFONT_HPP__
#define __MYUN2_GITHUB_COM__PAPER_ENGINE__D3DFONT_HPP__

#pragma comment(lib, "d3dx9.lib")
#include <d3dx9.h>
#include "auto_interface.hpp"
#include <string>

namespace myun2
{
	namespace paperengine
	{
		class d3dfont : public auto_interface<LPD3DXFONT>
		{
		public:
			::std::string str;
			d3dfont(d3ddev& d, unsigned int font_size=16, const char* font_name = "MS Gothic")
			{
				D3DXFONT_DESC fd = {
					font_size, 0, 0, 0, 0, SHIFTJIS_CHARSET, OUT_TT_ONLY_PRECIS,
					PROOF_QUALITY, FIXED_PITCH | FF_MODERN, ""};
				memcpy(fd.FaceName, font_name, strlen(font_name));

				if(FAILED(D3DXCreateFontIndirect(d.ptr, &fd, &ptr)))
					throw create_failed();
			}
			void render(const char* text, D3DCOLOR color =  0xffffffff) {
				RECT r={0,0,0,0};
				ptr->DrawText(NULL, text, -1, &r, DT_LEFT | DT_NOCLIP, color);
			}
			void render(D3DCOLOR color =  0xffffffff) {
				render(str.c_str(), color);
			}
			void set_text(const char* s) { str = s; }
			void operator =(const char* s) { str = s; }
			void operator =(const ::std::string& s) { str = s; }
		};
		typedef d3dfont text;
	}
}

#endif///__MYUN2_GITHUB_COM__PAPER_ENGINE__D3DFONT_HPP__

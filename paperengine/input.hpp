#ifndef __MYUN2_GITHUB_COM__PAPER_ENGINE__INPUT_HPP__
#define __MYUN2_GITHUB_COM__PAPER_ENGINE__INPUT_HPP__

#include "dinput.hpp"

namespace myun2
{
	namespace paperengine
	{
		class dinput_device : public auto_interface<LPDIRECTINPUTDEVICE8>
		{
		public:
			struct set_data_format_failed {};
			struct set_cooperative_level_failed {};

			dinput_device(dinput& di, REFGUID device_guid)
			{
				if ( FAILED(di.ptr->CreateDevice(device_guid, &ptr, NULL)) )
					throw create_failed();
			}
			void set_data_format(LPCDIDATAFORMAT fmt) {
				if ( FAILED(ptr->SetDataFormat(&c_dfDIKeyboard)) )
					throw set_data_format_failed();
			}
			void set_cooperative_level(HWND hwnd, DWORD level_flags) {
				if ( FAILED(ptr->SetCooperativeLevel(hwnd, level_flags)) )
					throw set_data_format_failed();
			}
		};

		class kb_input : public dinput_device
		{
		public:
			kb_input(dinput& di, HWND hwnd) : dinput_device(di, GUID_SysKeyboard)
			{
				set_data_format(&c_dfDIKeyboard);
				set_cooperative_level(hwnd, DISCL_FOREGROUND | DISCL_NONEXCLUSIVE | DISCL_NOWINKEY);
			}
		};
	}
}

#endif///__MYUN2_GITHUB_COM__PAPER_ENGINE__INPUT_HPP__

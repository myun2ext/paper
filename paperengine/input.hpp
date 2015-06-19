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
			void acquire() { ptr->Acquire(); }
			HRESULT get_status(void* buffer, unsigned int buf_size)
			{
				return ptr->GetDeviceState(buf_size, buffer);
			}
		};

		class kb_input : public dinput_device
		{
		private:
			unsigned char state_buff[256];
		public:
			kb_input(dinput& di, HWND hwnd) : dinput_device(di, GUID_SysKeyboard)
			{
				set_data_format(&c_dfDIKeyboard);
				set_cooperative_level(hwnd, DISCL_FOREGROUND | DISCL_NONEXCLUSIVE | DISCL_NOWINKEY);
			}
			void update()
			{
				if (FAILED(get_status(state_buff, sizeof(state_buff))) )
				{
					acquire();
					get_status(state_buff, sizeof(state_buff));
				}
			}
			bool test(unsigned char dik_code)
			{
				return state_buff[dik_code] & 0x80;
			}
		};

		class mouse_input : public dinput_device
		{
		public:
			DIMOUSESTATE2 states;
			mouse_input(dinput& di, HWND hwnd) : dinput_device(di, GUID_SysMouse)
			{
				set_data_format(&c_dfDIMouse2);
				set_cooperative_level(hwnd, DISCL_FOREGROUND | DISCL_NONEXCLUSIVE | DISCL_NOWINKEY);
				
				DIPROPDWORD diprop;
				diprop.diph.dwSize = sizeof(diprop);
				diprop.diph.dwHeaderSize = sizeof(diprop.diph);
				diprop.diph.dwObj = 0;
				diprop.diph.dwHow = DIPH_DEVICE;
				diprop.dwData = DIPROPAXISMODE_REL;
				ptr->SetProperty(DIPROP_AXISMODE, &diprop.diph);
			}
			void update()
			{
				if (FAILED(get_status(&states, sizeof(states))) )
				{
					acquire();
					get_status(&states, sizeof(states));
				}
			}
			long x() const { return states.lX; }
			long y() const { return states.lY; }
			long scroll() const { return states.lZ; }
			bool clicked() const { return states.rgbButtons[0] & 0x80; }
			bool rclicked() const { return states.rgbButtons[1] & 0x80; }
			bool wheel_clicked() const { return states.rgbButtons[2] & 0x80; }
		};
	}
}

#endif///__MYUN2_GITHUB_COM__PAPER_ENGINE__INPUT_HPP__

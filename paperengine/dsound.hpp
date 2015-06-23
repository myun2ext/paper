#ifndef __MYUN2_GITHUB_COM__PAPER_ENGINE__DSOUND_HPP__
#define __MYUN2_GITHUB_COM__PAPER_ENGINE__DSOUND_HPP__

#include <dsound.h>
#pragma comment(lib, "dsound.lib")
#include "auto_interface.hpp"

namespace myun2
{
	namespace paperengine
	{
		class dsound : public auto_interface<LPDIRECTSOUND8>
		{
		public:
			struct set_cooperative_level_failed {};
			dsound()
			{
				if ( FAILED(DirectSoundCreate8(NULL, &ptr, NULL)) )
					throw create_failed();
			}
		};
	}
}

#endif//__MYUN2_GITHUB_COM__PAPER_ENGINE__DSOUND_HPP__

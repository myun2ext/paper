#ifndef __MYUN2_GITHUB_COM__PAPER_ENGINE__VALUE_HPP__
#define __MYUN2_GITHUB_COM__PAPER_ENGINE__VALUE_HPP__

#include <math.h>

namespace myun2
{
	namespace paperengine
	{
		template <typename T, long Min, long Max>
		struct limited
		{
			T v;
			limited() : v(Min){}
			limited(const T& v_in) : v(v_in){}

/*			limited& operator ++(T){ v++; l(); return *this; }
			limited& operator --(T){ v--; l(); return *this; }
			limited& operator ++(){ limited work=*this; v++; l(); return work; }
			limited& operator --(){ limited work=*this; v--; l(); return work; }*/
			limited& operator +=(const T& v_in){ v+=v_in; l(); return *this; }
			limited& operator -=(const T& v_in){ v-=v_in; l(); return *this; }
			limited& operator +(const T& v_in){ limited work=*this; work+=v_in; l(); return work; }
			limited& operator -(const T& v_in){ limited work=*this; work-=v_in; l(); return work; }
			void l() {
				if (v<Min) v = Min;
				if (v>Max) v = Max;
			}
			operator const T&() const { return v; }
		};
		typedef limited<int, 0, 255> limited_uchar;
		typedef limited<float, 0, 1> limited_float;

		template <typename T>
		T ease(const T& v, double max = 1) { return sin(v * M_PI / 2 / max) * max; }

		/////////////////////////////////

		template <long Min = -1, long Max = 1>
		struct inertia : limited<float, Min, Max> //limited_float
		{
			typedef limited<float, Min, Max> _Super;
			inertia():_Super(0){}
			inertia(const float& v_in) : _Super(v_in){}

			void increase(float value = 0.05f) {
				_Super::operator +=(value);
			}
			void attenuate(float value = 0.01f) {
				if ( _Super::v < 0 )
					_Super::operator +=(value);
				else
					_Super::operator -=(value);
			}
		};
	}
}

#endif///__MYUN2_GITHUB_COM__PAPER_ENGINE__VALUE_HPP__

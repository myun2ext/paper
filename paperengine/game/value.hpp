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

			limited& operator ++(int){ v++; l(); return *this; }
			limited& operator --(int){ v--; l(); return *this; }
			limited& operator ++(){ limited work=*this; v++; l(); return work; }
			limited& operator --(){ limited work=*this; v--; l(); return work; }
			limited& operator +=(int n){ v+=n; l(); return *this; }
			limited& operator -=(int n){ v-=n; l(); return *this; }
			limited& operator +(int n){ limited work=*this; work+=n; l(); return work; }
			limited& operator -(int n){ limited work=*this; work-=n; l(); return work; }
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

		struct inertia : limited_float
		{
			inertia(){}
			inertia(const float& v_in) : limited_float(v_in){}

			void up(float acceleration = 0.05f) {
				operator +=(acceleration);
			}
			void down(float attenuation = 0.01f) {
				operator -=(attenuation);
			}
		};
	}
}

#endif///__MYUN2_GITHUB_COM__PAPER_ENGINE__VALUE_HPP__

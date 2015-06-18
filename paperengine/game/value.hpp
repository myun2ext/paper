#ifndef __MYUN2_GITHUB_COM__PAPER_ENGINE__VALUE_HPP__
#define __MYUN2_GITHUB_COM__PAPER_ENGINE__VALUE_HPP__

namespace myun2
{
	namespace paperengine
	{
		template <typename T, T Min, T Max>
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
	}
}

#endif///__MYUN2_GITHUB_COM__PAPER_ENGINE__VALUE_HPP__

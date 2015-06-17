#ifndef __MYUN2_GITHUB_COM__PAPER_ENGINE__AUTO_INTERFACE_HPP__
#define __MYUN2_GITHUB_COM__PAPER_ENGINE__AUTO_INTERFACE_HPP__

namespace myun2
{
	namespace paperengine
	{
		template <typename T>
		class auto_interface
		{
		public:
			struct create_failed {};
			T ptr;
			void release() {
				if ( ptr )
					if ( ptr->Release() )
						ptr = NULL;
			}
			virtual ~auto_interface() { release(); }
		};
	}
}


#endif//__MYUN2_GITHUB_COM__PAPER_ENGINE__AUTO_INTERFACE_HPP__

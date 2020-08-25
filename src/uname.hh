#ifndef UNAME_HH
#define UNAME_HH

#include <sys/utsname.h>

namespace coreutils
{
	class uname
	{
	private:
		utsname buffer;
	public:
		uname();
		const char* get_kernel_name()const;
		const char* get_nodename()const;
		const char* get_kernel_release()const;
		const char* get_kernel_version()const;
		const char* get_machine()const;
		//const char* get_processor()const;
		//const char* get_hardware()const;
	};

}

#endif 

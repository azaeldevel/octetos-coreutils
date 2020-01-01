#ifndef COREUTILS_UNAME_HH
#define COREUTILS_UNAME_HH

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <sys/utsname.h>
#include <string>

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




#include "uname.hh"

namespace coreutils
{
	uname::uname()
	{
		::uname(&buffer);
	}
	const char* uname::get_kernel_name()const
	{
		return buffer.sysname;
	}
	const char* uname::get_nodename()const
	{
		return buffer.nodename;
	}
	const char* uname::get_kernel_release()const
	{
		return buffer.release;
	}
	const char* uname::get_kernel_version()const
	{
		return buffer.version;
	}
	const char* uname::get_machine()const
	{
		return buffer.machine;
	}
	/*const char* uname::get_processor()const
	{

	}
	const char* uname::get_hardware()const
	{

	}*/

}

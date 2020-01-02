#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>


#include "Apishell.hh"

namespace coreutils
{
	bool Apishell::mkdir(const std::string& name, int mode)
	{
		struct stat st = {0};

		if (stat(name.c_str(), &st) == -1) 
		{
			int retMkdir = ::mkdir(name.c_str(), mode);
			if( retMkdir == 0)
			{
				return true;
			}
			else if( retMkdir == -1)
			{
				return false;
			}
			else
			{
				return false;
			}
		}
		else
		{
			return false;
		}
	}
	
	bool Apishell::mkdir(const std::string& name)
	{
		return mkdir(name,0700);
	}
}

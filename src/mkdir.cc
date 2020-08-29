#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>


#include "Apishell.hh"

namespace coreutils
{
	bool Apishell::mkdir(const std::string& name, int mode)
	{
		struct stat st = {0};
		int retMkdir = -1;
		
		if(mode == 0)
		{
			retMkdir = ::mkdirat(fdcwd,name.c_str(),0644);
		}
		else if (stat(name.c_str(), &st) == -1) 
		{
			retMkdir = ::mkdirat(fdcwd,name.c_str(), mode);
		}
		else
		{
			std::string msg = "Fallo al crear el archivo '";
			msg += name + "'";
#if DEBUG
			octetos::core::Error::write(octetos::core::Error(msg,errno,__FILE__,__LINE__));
#else
			octetos::core::Error::write(octetos::core::Error(msg,errno));
#endif
			return false;
		}
		if( retMkdir == 0)
		{
			return true;
		}
		else
		{
			std::string msg = "Fallo al crear el archivo '";
			msg += name + "' \n\t";
			switch(errno)
			{
				case EACCES:
					msg += "Search permission is denied on a component of the path prefix, or write permission is denied on the parent directory of the directory to be created";
					break;
				case EEXIST:
					msg += "The named file exists";
					break;
				case ELOOP:
					msg += "A loop exists in symbolic links encountered during resolution of the path argument";
					break;
				case EMLINK:
					msg += "The link count of the parent directory would exceed {LINK_MAX}";
					break;
				case ENAMETOOLONG:
					msg += "The length of the path argument exceeds {PATH_MAX} or a pathname component is longer than {NAME_MAX}";
					break;
				case ENOENT:
					msg += "A component of the path prefix specified by path does not name an existing directory or path is an empty string";
					break;
				case ENOSPC:
					msg += "The file system does not contain enough space to hold the contents of the new directory or to extend the parent directory of the new directory";
					break;
				case ENOTDIR:
					msg += "A component of the path prefix is not a directory";
					break;
				case EROFS:
					msg += "The parent directory resides on a read-only file system";
					break;
			}
#if DEBUG
			octetos::core::Error::write(octetos::core::Error(msg,errno,__FILE__,__LINE__));
#else
			octetos::core::Error::write(octetos::core::Error(msg,errno));
#endif
			return false;
		}
	}
	
}

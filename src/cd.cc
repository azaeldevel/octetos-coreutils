#include <sys/types.h>
#include <dirent.h>

#include "Apishell.hh"

namespace coreutils
{

	bool Apishell::cd(const std::string& dir)
	{
		if(actualDir)
		{
			closedir(actualDir);
		}

		actualDir = opendir(dir.c_str());

		if(actualDir) 
		{
			return true;
		}
		else 
		{
			std::string msg = "Fallo de cambio de directorio '";
			msg += dir + "' \n\t";
			switch(errno)
			{
				case EACCES:
					msg += "Permission denied";
					break;
				case EBADF:
					msg += "fd is not a valid file descriptor opened for reading";
					break;
				case EMFILE:
					msg += "The per-process limit on the number of open file descriptors has been reached";
					break;
				case ENFILE:
					msg += "The system-wide limit on the total number of open files has been reached";
					break;
				case ENOENT:
					msg += "Directory does not exist, or name is an empty string";
					break;
				case ENOMEM:
					msg += "Insufficient memory to complete the operation";
					break;
				case ENOTDIR:
					msg += "name is not a directory";
					break;
			}
#if DEBUG
			core::Error::write(core::Error(msg,errno,__FILE__,__LINE__));
#else
			octetos::core::Error::write(octetos::core::Error(msg,errno));
#endif
			return false;
		}
	}
}

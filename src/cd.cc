/**
 * 
 *  This file is part of octetos-coreutils.
 *  octetos-coreutils is a library C++ for coreuitls funtions.
 *  Copyright (C) 2020  Azael Reyes
 * 
 *  This program is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program.  If not, see <http://www.gnu.org/licenses/>.
 * 
 * */

#include <sys/types.h>
#include <dirent.h>

#include "shell.hh"

namespace coreutils
{

	bool Shell::cd(const std::string& dir)
	{		
		if(!cwd(dir))
		{
			std::string msg = "Fallo de cambio de directorio '";
			msg += dir + "'";			
#if DEBUG
			msg += "\n\t";
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
			octetos::core::Error::write(octetos::core::Error(msg,errno,__FILE__,__LINE__));
#else
			octetos::core::Error::write(octetos::core::Error(msg,errno));
#endif
			return false;
		}
		
	return true;
	}


	
}

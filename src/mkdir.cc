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
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h> 

#include "shell.hh"

namespace coreutils
{
	trilean Shell::mkdir(const std::string& name, int recursive)
	{				
		//Precessing	
		std::string stractual;
		if(recursive)
		{
		   	std::vector<std::string> result;
		   	std::stringstream s_stream(name); //create string stream from the string
		   	while(s_stream.good()) 
		   	{
			  	std::string substr;
			  	getline(s_stream, substr, '/'); //get first string delimited by /
			  	result.push_back(substr);
		   	}
		   	
		   	std::string newpath ;
		   	for(const std::string& s : result)
		   	{
		   		newpath += s;
		   		//std::cout << newpath << "\n";
		   		stractual = newpath;
		   		//std::cout << "\tcomponent :" << s << "\n"; 
		   		if(exists(newpath) == TFALSE) 
		   		{
		   			if(::mkdir(newpath.c_str(),0777) == -1)
		   			{
			   			std::string msg = "Fail on calling mkdir : '";
				   		msg += newpath + "'";
						octetos::core::Error::write(octetos::core::Error(msg,0,__FILE__,__LINE__));
						return TFALSE;
		   			}
		   		}
		   		else
		   		{
		   			std::string msg = "File already exists : '";
			   		msg += newpath + "'";
					octetos::core::Error::write(octetos::core::Error(msg,0,__FILE__,__LINE__));
					return TFALSE;
		   		}
		   		newpath += "/";
		   	}
		   	return TTRUE;
	   	}
	   	else
	   	{
	   		//std::cout << "Step 1\n";
	   		std::vector<std::string> result;
		   	std::stringstream s_stream(name); //create string stream from the string
		   	//std::cout << "Step 2\n";
		   	while(s_stream.good()) 
		   	{
			  	std::string substr;
			  	getline(s_stream, substr, '/'); //get first string delimited by /
			  	result.push_back(substr);
		   	}
		   	
		   	//std::cout << "Step 3\n";
		   	std::string newpath ;
		   	for(int i = 0; i < result.size() - 1 ; i++)
		   	{   		
		   		newpath += result[i] + "/";
			   	//std::cout << "Step 4\n";
			   	if(!exists(newpath)) 
			   	{
			   		std::string msg = "No existe el archivo ";
			   		msg += newpath;
					octetos::core::Error::write(octetos::core::Error(msg,0,__FILE__,__LINE__));
					return TFALSE;
			   	}
		   	}
		   	stractual = newpath;
		   	int ret = ::mkdir(name.c_str(),0777);
			if(ret == 0) return TTRUE;
	   	}
		
		ERROR:
		//validacion de error
		if(errno != 0)
		{
			std::string msg = "Fail on floor '";
			msg += stractual + "' \n\t";
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
			
			throw octetos::core::Error(msg,errno,__FILE__,__LINE__);
		}
		
		return false;
	}
	
}

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

#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#include "config.h"
#include "shell.hh"

namespace coreutils
{
	int Shell::execute(const std::string& cmd)
	{
		return system(cmd.c_str());
	}
	void Shell::set(std::vector<Enviroment*> v)
	{
		for(const Enviroment* env : v)
		{
			setenv(env->name.c_str(),env->value.c_str(),1);
			//std::cout << env->name << "=" << env->value.c_str() << "\n";			
		}
	}
	const char* Shell::gcwd()
	{
		if(strcwd != NULL)
		{
			free((void*)strcwd);
		}
		strcwd = get_current_dir_name();
		return strcwd;
	}


	bool getPackageInfo(octetos::core::Artifact& packinfo)
	{
		packinfo.name = PACKAGE;
		packinfo.brief = "Similar to coreutils but is a C++ API.";
		packinfo.url = "https://github.com/azaeldevel/octetos-coreutils.git";
		packinfo.name_decorated = "Libreria coreutils de Octetos";
		
		packinfo.version.set(VERSION);
		
		packinfo.licence.type = octetos::core::Licence::Type::GPLv3;		
		packinfo.licence.name_public = PACKAGE;
		packinfo.licence.owner = "Azael Reyes";
		packinfo.licence.year = 2019;
        packinfo.licence.contact = "azael.devel@gmail.com";
		
		return true;	
	}
	
	/*
	bool Shell::cwd(const std::string& path)
	{
		if(path.empty()) 
		{
			if(strcwd and strcwd_malloc)//si tien algun puntero creado con malloc
			{
				free((void*)strcwd);
			}
			strcwd = getcwd(NULL,0);
			strcwd_malloc = true;
			if(strcwd == NULL)
			{
				std::string msg = "Falló al leer el directorio de trabajo actual.";
#if DEBUG
				octetos::core::Error::write(octetos::core::Error(msg,errno,__FILE__,__LINE__));
#else
				octetos::core::Error::write(octetos::core::Error(msg,errno));
#endif
				return false;
			}
		}
		else
		{
			strcwd = path.c_str();
			strcwd_malloc = false;
		}
		

		//iniciando descriptor de archivo.
		fdcwd = open(strcwd,O_RDONLY,S_IRUSR | S_IWUSR | S_IXUSR);
		if(fdcwd == -1)
		{
			std::string msg = "Falló al abrir el directorio de trabajo actual.";
#if DEBUG
			octetos::core::Error::write(octetos::core::Error(msg,errno,__FILE__,__LINE__));
#else
			octetos::core::Error::write(octetos::core::Error(msg,errno));
#endif
			return false;
		}

		//cambiando en directorio
		if(fchdir(fdcwd) == -1)
		{
			std::string msg = "Falló al cambiar el directorio de trabajo actual.";
#if DEBUG
			octetos::core::Error::write(octetos::core::Error(msg,errno,__FILE__,__LINE__));
#else
			octetos::core::Error::write(octetos::core::Error(msg,errno));
#endif
			return false;
		}

		
		//inicando estructura de directorio DIR
		dircwd = fdopendir(fdcwd);
		if(dircwd == NULL)
		{
			std::string msg = "Falló al abrir el directorio de trabajo actual.";
#if DEBUG
			octetos::core::Error::write(octetos::core::Error(msg,errno,__FILE__,__LINE__));
#else
			octetos::core::Error::write(octetos::core::Error(msg,errno));
#endif
			return false;
		}
				
		return true;
	}
	*/
	Shell::Shell(const std::string& default_dir)
	{
		strcwd = NULL;
	}
	Shell::Shell()
	{
		strcwd = NULL;
	}
	Shell::~Shell()
	{
		
	}

	Error::Error(const std::string& msg) throw() : octetos::core::Error(msg)
	{}

}

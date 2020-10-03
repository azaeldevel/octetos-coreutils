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

#ifndef APISHELL_HH
#define APISHELL_HH

#include <string>
#include <list>
#include <octetos/core/Error.hh>
#include <octetos/core/Artifact.hh>
#include <dirent.h>
#include <stdlib.h>


namespace coreutils
{
	
	/**
	 * \brief retorna la informacion del paquete
	 **/
	bool getPackageInfo(octetos::core::Artifact&);

	struct Enviroment
	{
		std::string name;
		std::string value;
	};

	class Error : public octetos::core::Error
	{
	public:
		Error(const std::string&) throw();
	};	

	class Shell
	{
	private:
		DIR* dircwd;
		const char* strcwd;
		/**
		* \brief Inidca si strcdw fua asignada con malloc
		*/
		bool strcwd_malloc;
		int fdcwd;
		//bool cwd(const std::string& = "");

	public:
		Shell();
		Shell(const std::string&);
		~Shell();
		//bool ls(const std::string&, std::list<std::string>&);
		bool ls(std::list<std::string>&);
		bool cd(const std::string&);
		bool mkdir(const std::string&, int mode = 0);
		bool rm(const std::string&);
		bool rename(const std::string&,const std::string&);
		bool touch(const std::string&, int options = 0);
		bool ln(const std::string&, int m = 0);
		bool exists(const std::string&);
		const char* gcwd();
		void set(std::vector<Enviroment*>);
		int execute(const std::string&);
	};


} 

#endif
#ifndef COREUTILS_LS_HH
#define COREUTILS_LS_HH

#include <stdio.h>
#include <dirent.h>
#include <string>
#include <list>
#include <octetos/core/Error.hh>

#include "uname.hh"


namespace coreutils
{
	class Error : public octetos::core::Error
	{
	public:
		Error(const std::string&) throw();
	};
	
	class Apishell
	{
	private:
		DIR* actualDir;

	public:
		Apishell();
		Apishell(const std::string&);
		~Apishell();
		bool ls(const std::string&, std::list<std::string>&);
		bool cd(const std::string&);
		bool mkdir(const std::string&);
		bool mkdir(const std::string&, int mode);
	};

} 

#endif
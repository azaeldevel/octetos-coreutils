#ifndef APISHELL_HH
#define APISHELL_HH

#include <string>
#include <list>
#include <octetos/core/Error.hh>
#include <dirent.h>


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
		bool ls(std::list<std::string>&);
		bool cd(const std::string&);
		bool mkdir(const std::string&);
		bool mkdir(const std::string&, int mode);
		bool rm(const std::string&);
		bool rename(const std::string&,const std::string&);
		bool touch(const std::string&);
	};


} 

#endif
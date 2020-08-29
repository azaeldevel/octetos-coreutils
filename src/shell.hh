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
		bool cwd(const std::string& = "");

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
	};


} 

#endif
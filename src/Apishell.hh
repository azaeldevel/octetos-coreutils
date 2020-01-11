#ifndef APISHELL_HH
#define APISHELL_HH

#include <stdio.h>
#include <dirent.h>
#include <string>
#include <list>
#include <octetos/core/Error.hh>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

//uname
#include <sys/utsname.h>


namespace coreutils
{
	class Error : public octetos::core::Error
	{
	public:
		Error(const std::string&) throw();
	};	

	class uname
	{
	private:
		utsname buffer;
	public:
		uname();
		const char* get_kernel_name()const;
		const char* get_nodename()const;
		const char* get_kernel_release()const;
		const char* get_kernel_version()const;
		const char* get_machine()const;
		//const char* get_processor()const;
		//const char* get_hardware()const;
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
		bool rm(const std::string&);
		bool rename(const std::string&,const std::string&);
	};

} 

#endif
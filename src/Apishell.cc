
#include <iostream>

#include "Apishell.hh"

namespace coreutils
{
	Apishell::Apishell(const std::string& default_dir)
	{
		actualDir = NULL;
		cd(default_dir);
	}
	Apishell::Apishell()
	{
		actualDir = NULL;
		std::string default_dir = ".";
		cd(default_dir);
	}
	Apishell::~Apishell()
	{
		closedir(actualDir);
	}
	





	Error::Error(const std::string& msg) throw() : octetos::core::Error(msg)
	{}



	bool Apishell::cd(const std::string& dir)
	{	
		if(actualDir) closedir(actualDir);
		
		actualDir = opendir(dir.c_str());
		std::string msg = "El parámetro '";
		msg += dir + "' causo error.";
		if (actualDir == NULL)  throw Error(msg);
	}



		
	bool Apishell::ls(const std::string& name, std::list<std::string>& l)
	{
		struct dirent *entry;

  		while((entry = readdir(actualDir)))
		{
			//std::cout << "Directory name : " << entry->d_name << "\n";
			l.push_back(entry->d_name);
		}
	
		return true;
	}
}

#include <dirent.h>
#include <sys/types.h>

#include "Apishell.hh"

namespace coreutils
{
	bool Apishell::ls(const std::string& name, std::list<std::string>& l)
	{
		struct dirent *entry;
		
		DIR* d = opendir(name.c_str());
  		while((entry = readdir(d)))
		{
			l.push_back(entry->d_name);
		}
	
		return true;
	}
	
	bool Apishell::ls(std::list<std::string>& l)
	{
		struct dirent *entry;

  		while((entry = readdir(actualDir)))
		{
			l.push_back(entry->d_name);
		}
	
		return true;
	}
}
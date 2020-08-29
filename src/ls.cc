#include <dirent.h>
#include <sys/types.h>

#include "Apishell.hh"

namespace coreutils
{
	bool Apishell::ls(std::list<std::string>& l)
	{
		struct dirent *entry;

  		while((entry = readdir(dircwd)))
		{
			l.push_back(entry->d_name);
		}
	
		return true;
	}
}
#include <dirent.h>
#include <sys/types.h>

#include "shell.hh"

namespace coreutils
{
	bool Shell::ls(std::list<std::string>& l)
	{
		struct dirent *entry;

  		while((entry = readdir(dircwd)))
		{
			l.push_back(entry->d_name);
		}
	
		return true;
	}
}
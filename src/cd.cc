#include <sys/types.h>
#include <dirent.h>

#include "Apishell.hh"

namespace coreutils
{

	bool Apishell::cd(const std::string& dir)
	{
		if(actualDir)
		{
			closedir(actualDir);
			actualDir = opendir(dir.c_str());
			if(actualDir) return true;
			else return false;
		}
		else
		{
			actualDir = opendir(dir.c_str());
			if(actualDir) return true;
			else return false;
		}
	}
}

#include <sys/types.h>
#include <dirent.h>

#include "Apishell.hh"

namespace coreutils
{

	bool Apishell::cd(const std::string& dir)
	{			
		actualDir = opendir(dir.c_str());
		std::string msg = "El parámetro '";
		msg += dir + "' causo error.";
		if (actualDir) return true;
		return false;
	}
}

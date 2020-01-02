#include "Apishell.hh"

namespace coreutils
{

	bool Apishell::cd(const std::string& dir)
	{	
		if(actualDir) 
		{
			int retClose = closedir(actualDir);
			if(retClose == 0) 
			{
				actualDir = NULL;
			}
			else
			{
				return false;
			}
		}
		
		actualDir = opendir(dir.c_str());
		std::string msg = "El parámetro '";
		msg += dir + "' causo error.";
		if (actualDir) return true;
		return false;
	}
}

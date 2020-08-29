#include <stdio.h>

#include "shell.hh"

namespace coreutils
{
    bool Shell::rename(const std::string& oldname,const std::string& newname)
	{
		int retRm = rename(oldname.c_str(),newname.c_str());
		if(retRm == 0) return true;
		else if(retRm == -1) return false;
		else return false;
	}
}

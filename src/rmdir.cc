#include "Apishell.hh"

namespace coreutils
{

    bool Apishell::rmdir(const std::string& path)
	{
		int retRm = rmdir(path.c_str());
		if(retRm == 0) return true;
		if(retRm == -1) return false;
		return false;
	}
}
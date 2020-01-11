#include "Apishell.hh"

namespace coreutils
{
    bool Apishell::rm(const std::string& path)
	{
		int retRm = remove(path.c_str());
		if(retRm == 0) return true;
		if(retRm == -1) return false;
		return false;
	}
}
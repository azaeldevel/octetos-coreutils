#include "Apishell.hh"

namespace coreutils
{
    bool Apishell::rename(const std::string& oldname,const std::string& newname)
	{
		int retRm = rename(oldname.c_str(),newname.c_str());
		if(retRm == 0) return true;
		if(retRm == -1) return false;
		return false;
	}
}
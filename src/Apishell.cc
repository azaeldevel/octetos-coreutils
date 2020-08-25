

#include "Apishell.hh"

namespace coreutils
{
	Apishell::Apishell(const std::string& default_dir)
	{
		cd(default_dir);
	}
	Apishell::Apishell()
	{
		actualDir = NULL;
		cd("/");
	}
	Apishell::~Apishell()
	{
		closedir(actualDir);
	}





	Error::Error(const std::string& msg) throw() : octetos::core::Error(msg)
	{}


	
}

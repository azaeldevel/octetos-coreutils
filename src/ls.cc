
#include "Apishell.hh"

namespace coreutils
{
	bool Apishell::ls(const std::string& name, std::list<std::string>& l)
	{
		struct dirent *entry;

  		while((entry = readdir(actualDir)))
		{
			//std::cout << "Directory name : " << entry->d_name << "\n";
			l.push_back(entry->d_name);
		}
	
		return true;
	}
}
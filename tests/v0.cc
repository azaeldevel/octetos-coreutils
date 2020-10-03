#include <iostream>

#include <shell.hh>


int main(void)
{
	coreutils::Shell shell;
	
	std::cout << "In " << shell.gcwd() << "\n";
	
	shell.cd("/tmp");
	
	std::cout << "In " << shell.gcwd() << "\n";
	
	shell.execute("echo >>>>>>>>>>>>>>>>");
	std::list<std::string> d;
	shell.ls(d);
	for(std::string s : d)
	{
		std::cout << s << "\n";
	}	
	
    return  EXIT_SUCCESS;
}


#include <iostream>

#include <shell.hh>


int main(void)
{	
	coreutils::Shell shell;
	
	std::cout << "In " << shell.gcwd() << "\n";
	
	shell.cd("/tmp");
	
	std::cout << "In " << shell.gcwd() << "\n";
	
    return  EXIT_SUCCESS;
}


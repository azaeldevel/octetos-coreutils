
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <sys/utsname.h>
#include <iostream>


#include "uname.hh"
#include "Apishell.hh"

int main(void) {


	/*std::cout << "\n";
	coreutils::uname u;
	std::cout << "System Name : " << u.get_kernel_name() << "\n";
	std::cout << "Node Name : " << u.get_nodename() << "\n";
	std::cout << "Node Name : " << u.get_kernel_release() << "\n";
	std::cout << "Node Name : " << u.get_kernel_version() << "\n";
	std::cout << "Node Name : " << u.get_machine() << "\n";*/

	coreutils::Apishell ash;
	
	/*std::list<std::string> dirs;
	ash.ls("/home/azael",dirs);
	for(std::string d : dirs)
	{
		std::cout << "Diretory Name : " << d << "\n";
	}*/
	ash.mkdir("dir.arm");
   return EXIT_SUCCESS;
}
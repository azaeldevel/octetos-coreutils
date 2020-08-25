
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <sys/utsname.h>
#include <iostream>

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
	
	if(!ash.cd("."))
	{
		if(octetos::core::Error::check())
		{			
			std::cout << octetos::core::Error::get().describe() << "\n";
		}
	}
	
	std::string dir = "dir.arm";
	if(ash.mkdir(dir)) 
	{
		std::cout << "Se creo " << dir << "\n";
	}
	else
	{
		if(octetos::core::Error::check())
		{			
			std::cout << octetos::core::Error::get().describe() << "\n";
		}
	}
	/*
	if(ash.rm(dir)) 
	{
		std::cout << "Se elimino '" << dir << "\n";
	}
	else 
	{
		std::cout << "No se elimino '" << dir << "\n";
	}
	
	std::list<std::string> dirs;
	ash.ls(dirs);
	for(std::string d: dirs)
	{
		std::cout << "D :" <<  d << "\n";
	}*/

	
   	return EXIT_SUCCESS;
}
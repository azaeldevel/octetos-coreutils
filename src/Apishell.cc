#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#include "Apishell.hh"

namespace coreutils
{
	bool Apishell::cwd(const std::string& path)
	{
		if(path.empty()) 
		{
			if(strcwd and strcwd_malloc)//si tien algun puntero creado con malloc
			{
				free((void*)strcwd);
			}
			strcwd = getcwd(NULL,0);
			strcwd_malloc = true;
			if(strcwd == NULL)
			{
				std::string msg = "Falló al leer el directorio de trabajo actual.";
#if DEBUG
				octetos::core::Error::write(octetos::core::Error(msg,errno,__FILE__,__LINE__));
#else
				octetos::core::Error::write(octetos::core::Error(msg,errno));
#endif
				return false;
			}
		}
		else
		{
			strcwd = path.c_str();
			strcwd_malloc = false;
		}
		

		//iniciando descriptor de archivo.
		fdcwd = open(strcwd,O_RDONLY,S_IRUSR | S_IWUSR | S_IXUSR);
		if(fdcwd == -1)
		{
			std::string msg = "Falló al abrir el directorio de trabajo actual.";
#if DEBUG
			octetos::core::Error::write(octetos::core::Error(msg,errno,__FILE__,__LINE__));
#else
			octetos::core::Error::write(octetos::core::Error(msg,errno));
#endif
			return false;
		}

		//cambiando en directorio
		if(fchdir(fdcwd) == -1)
		{
			std::string msg = "Falló al cambiar el directorio de trabajo actual.";
#if DEBUG
			octetos::core::Error::write(octetos::core::Error(msg,errno,__FILE__,__LINE__));
#else
			octetos::core::Error::write(octetos::core::Error(msg,errno));
#endif
			return false;
		}

		
		//inicando estructura de directorio DIR
		dircwd = fdopendir(fdcwd);
		if(dircwd == NULL)
		{
			std::string msg = "Falló al abrir el directorio de trabajo actual.";
#if DEBUG
			octetos::core::Error::write(octetos::core::Error(msg,errno,__FILE__,__LINE__));
#else
			octetos::core::Error::write(octetos::core::Error(msg,errno));
#endif
			return false;
		}
				
		return true;
	}
	Apishell::Apishell(const std::string& default_dir)
	{
		strcwd = NULL;
		
	}
	Apishell::Apishell()
	{
		strcwd = NULL;
		cwd();
	}
	Apishell::~Apishell()
	{
		
	}





	Error::Error(const std::string& msg) throw() : octetos::core::Error(msg)
	{}

}

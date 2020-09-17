/**
 * 
 *  This file is part of octetos-coreutils.
 *  octetos-coreutils is a library C++ for coreuitls funtions.
 *  Copyright (C) 2020  Azael Reyes
 * 
 *  This program is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program.  If not, see <http://www.gnu.org/licenses/>.
 * 
 * */

#ifndef UNAME_HH
#define UNAME_HH

#include <sys/utsname.h>

namespace coreutils
{
	class uname
	{
	private:
		utsname buffer;
	public:
		uname();
		const char* get_kernel_name()const;
		const char* get_nodename()const;
		const char* get_kernel_release()const;
		const char* get_kernel_version()const;
		const char* get_machine()const;
		//const char* get_processor()const;
		//const char* get_hardware()const;
	};

}

#endif 

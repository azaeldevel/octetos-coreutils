#include <iostream>
#include <CUnit/Basic.h>
#include <shell.hh>

int init(void)
{
	return 0;
}
int clean(void)
{
	return 0;
}

void funciotns()
{
	coreutils::Shell shell;
	
	/*shell.echo("Begin test.\n");	
	shell.echo("In ");
	shell.echo(shell.cwd());
	shell.echo("\n");*/
	
	if(shell.exists("src"))
	{
		CU_ASSERT(true);
	}
	else 
	{
		CU_ASSERT(false);
	}
	if(shell.exists("/usr"))
	{
		CU_ASSERT(true);
	}
	else 
	{
		CU_ASSERT(false);
	}
	
	if(shell.exists("Debug"))
	{
		if(shell.mkdir("Debug/test1",false))
		{
			CU_ASSERT(true);
		}
		else
		{
			//std::cout << "Fallo la creación de archivo\n";
			CU_ASSERT(false);
		}
		
		if(shell.mkdir("Debug/test2",false))
		{
			CU_ASSERT(true);
		}
		else
		{
			//std::cout << "Fallo la creación de archivo\n";
			CU_ASSERT(false);
		}
		
		if(shell.mkdir("Debug/test3",false))
		{
			CU_ASSERT(true);
		}
		else
		{
			//std::cout << "Fallo la creación de archivo\n";
			CU_ASSERT(false);
		}
	}
	
	
	/*shell.echo("In ");
	shell.cd("/tmp");	
	shell.echo(shell.cwd());
	shell.echo("\n");*/
	
	/*
	shell.execute("echo >>>>>>>>>>>>>>>>");
	std::list<std::string> d;
	shell.ls(d);
	for(std::string s : d)
	{
		std::cout << s << "\n";
	}	
	*/
}

int main(void)
{		
	/* initialize the CUnit test registry */
	if (CUE_SUCCESS != CU_initialize_registry()) return CU_get_error();

	CU_pSuite pSuite = NULL;
	pSuite = CU_add_suite("Testinf coreutils C++", init, clean);
		
	if ((NULL == CU_add_test(pSuite, "Comandos princiaples", funciotns)))
	{
		CU_cleanup_registry();
		return CU_get_error();
	}
	/* Run all tests using the CUnit Basic interface */
	CU_basic_set_mode(CU_BRM_VERBOSE);
	CU_basic_run_tests();
	CU_cleanup_registry();
	return CU_get_error();
	
		
	
    return  EXIT_SUCCESS;
}


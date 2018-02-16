//
//EPITECH PROJECT, 2018
//PSU_2017_malloc
//File description:
//Makefile
//

#include <iostream> 
#include <fstream>
#include "../include/Parser.hpp"
#include "../include/ErrorManage.hpp"

int	main(int argc, char **argv)
{
	ErrorManage	*e = new ErrorManage(argv[1]);

	//e->check_for_empty_line();
	e->check_for_tab();
	
	/*Parser	*p = new Parser(argc, argv);

	p->show_vector();
	p->clean_tab();
	p->show_vector();
*/
	return (0);
}

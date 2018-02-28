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
	if (argc != 2)
		return (84);
	
	ErrorManage	*e = new ErrorManage(argv[1]);

	e->check_for_empty_line();
	e->check_for_tab();
	e->check_for_useless_space();
	e->check_for_name();
	//Parser	*p = new Parser(argc, argv);

	//p->show_vector();
	//p->clean_tab();
	//p->show_vector();
	
	return (0);
}


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

	
	Parser	*p = new Parser(argc, argv, e);

	p->find_links();
	
	return (0);
}


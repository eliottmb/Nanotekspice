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
#include "../include/prompt.hpp"
#include <functional>
int	main(int argc, char **argv)
{
	if (argc != 2)
		return (84);
	
	ErrorManage	*e = new ErrorManage(argv[1]);

	
	Parser	*p = new Parser(argc, argv);

	Prompt	*pr = new Prompt(argv);

	//p->find_links();
	//p->show_killing_death_vector();
	
	return (0);
}


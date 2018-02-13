//
//EPITECH PROJECT, 2018
//PSU_2017_malloc
//File description:
//Makefile
//

#include <iostream>
#include <fstream>
#include "../include/Parser.hpp"

int	main(int argc, char **argv)
{
	Parser	*p = new Parser(argc, argv);

	p->show_vector();
	p->clean_tab();
	p->show_vector();

	return (0);
}

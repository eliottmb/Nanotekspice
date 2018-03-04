//
// EPITECH PROJECT, 2018
// nanotekspice
// File description:
// simulate chipsets
//

#include <iostream>
#include <fstream>
#include "../include/Parser.hpp"
#include "../include/ErrorManage.hpp"
#include "../include/Prompt.hpp"
#include <memory>

int	main(int argc, char **argv)
{
//	if (argc != 2)
//		return (84);
	ErrorManage	*e = new ErrorManage(argv[1]);
	Parser	*p = new Parser(argv[1]);
	Prompt	*pr = new Prompt(argv);

	//p->find_links();
	//p->show_killing_death_vector();
//	p->show_pair();
	pr->print_prompt(p, argv);

	return (0);
}

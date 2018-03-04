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
	ErrorManage	*e = new ErrorManage(argv[1]);
	Parser	*p = new Parser(argv[1]);
	Prompt	*pr = new Prompt(argv);

	pr->print_prompt(p, argv);
	return (0);
}

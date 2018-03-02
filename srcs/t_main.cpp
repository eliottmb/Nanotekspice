//
// EPITECH PROJECT, 2018
// main
// File description:
//
//

#include "../include/ErrorManage.hpp"
#include "../include/Parser.hpp"
#include "../include/prompt.hpp"

int	main(int ac, char **av)
{
	ErrorManage	*e = new ErrorManage(av[1]);
	Parser		*parse = new Parser(ac, av, e);
	Prompt		*prompt = new Prompt(av);

	prompt->print_prompt(parse);
}

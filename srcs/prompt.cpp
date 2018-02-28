//
// EPITECH PROJECT, 2018
// nts
// File description:
//
//

#include <map>
#include <iostream>
#include "prompt.hpp"

int	simulate(Parser *parse)
{
	std::cout << "simulate\n";
}

int	loop(Parser *parse)
{
	std::cout << "loop\n";
}

int	display(Parser *parse)
{
	std::cout << "display\n";
}

int	dump(Parser *parse)
{
	int		i = 0;

	while (i < _ins.size()) {
		std::cout << (*(_ins[i]))->getName() << "=";
		std::cout << (*(_ins[i++]))->compute() << std::endl;
	}
}

int	init_Pins(Parser *parse)
{
	int				i = 0;
	std::string			elem;
	nts::AComponent			*comp;
	std::vector<std::string>	ins;

	comp = new nts::AComponent();
	parse->clean_tab();
	ins = parse->get_Ins();
	while (i < ins.size())
		_ins.push_back(comp->createComponent("input", ins[i++]));
}

int	setInput(std::string str)
{
	int		intState;
	std::string	name;
	nts::Tristate	state;

	name = str.substr(0, str.find("="));
	intState = std::stoi(str.substr(str.find("=") + 1, str.size()));
	if (intState == 1)
		(*(_ins[0]))->setState((nts::Tristate)1);
	else
		(*(_ins[0]))->setState((nts::Tristate)0);
	return (0);
}

int	parse_entry(std::string str, Parser *parse)
{
	std::map<std::string, int (*)(Parser *)>	g_funcs;

	g_funcs["dump"] = &dump;
	g_funcs["simulate"] = &simulate;
	g_funcs["loop"] = &loop;
	g_funcs["display"] = &display;
	if (!g_funcs[str]) {
		if (str == "exit" || (str.find('=') != std::string::npos && setInput(str) == 1))
			return 1;
		if (str.find("=") != std::string::npos)
			setInput(str);
		return 0;
	}
	g_funcs[str](parse);
	return (0);
}

int	main(int ac, char **av)
{
	std::string	entry;
	Parser		*parse = new Parser(ac, av);

	init_Pins(parse);
	do {
		std::cout << ">";
		std::cin >> entry;
	} while (parse_entry(entry, parse) != 1);
}

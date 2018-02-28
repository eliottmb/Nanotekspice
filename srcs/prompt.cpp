//
// EPITECH PROJECT, 2018
// nts
// File description:
//
//

#include <map>
#include <iostream>
#include <csignal>
#include "../include/prompt.hpp"

int	g_sig = 0;
int	g_isLoop = 0;

void	sighandler(int s)
{
	std::cout << std::endl;
	if (g_isLoop == 1)
		g_sig = 1;
	else
		exit(0);
}

int	simulate(Parser *parse)
{
	std::cout << "simulate\n";
}

int	loop(Parser *parse)
{
	g_isLoop = 1;
	std::signal(SIGINT, sighandler);
	while (1)
		if (g_sig != 0)
			break;
	return 0;
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
	std::vector<std::pair<std::string, std::string> >	ins;

	comp = new nts::AComponent();
//	parse->clean_tab();
	ins = parse->get_comps();
	while (i < ins.size())
	{
		std::cout << ins[i].first << " :::: " << ins[i++].second << std::endl;
//		_ins.push_back(comp->createComponent(ins[i].first, ins[i++].second));
	}
}

int	setInput(std::string str)
{
	int		intState;
	std::string	name;
	nts::Tristate	state;
	int		i = 0;

	name = str.substr(0, str.find("="));
	while (i < _ins.size() && (*(_ins[i]))->getName() != name)
		i++;
	intState = std::stoi(str.substr(str.find("=") + 1, str.size()));
	if (intState == 1)
		(*(_ins[i]))->setState((nts::Tristate)1);
	else
		(*(_ins[i]))->setState((nts::Tristate)0);
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
	Parser		*parse;
	ErrorManage	*e = new ErrorManage(av[1]);

	parse = new Parser(ac, av, e);
	init_Pins(parse);
	do {
		g_isLoop = 2;
		std::cout << ">";
		std::cin >> entry;
	} while (parse_entry(entry, parse) != 1);
}

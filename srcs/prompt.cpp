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

Prompt::Prompt(char **av)
{
	g_funcs["dump"] = &Prompt::dump;
	g_funcs["simulate"] = &Prompt::simulate;
	g_funcs["loop"] = &Prompt::loop;
	g_funcs["display"] = &Prompt::display;
	e = std::make_unique<ErrorManage>(av[1]);
}

Prompt::~Prompt()
{
}

void	sighandler(int s)
{
	std::cout << std::endl;
	if (g_isLoop == 1)
		g_sig = 1;
	else
		exit(0);
}

int	Prompt::simulate(Parser *parse)
{
	(*(_ins[14]))->setState((*(_ins[0]))->compute(0), 0);
	(*(_ins[14]))->setState((*(_ins[1]))->compute(0), 1);
	(*(_ins[14]))->compute(2);
}

int	Prompt::loop(Parser *parse)
{
	g_isLoop = 1;
	std::signal(SIGINT, sighandler);
	while (1)
		if (g_sig != 0)
			break;
	return 0;
}

int	Prompt::display(Parser *parse)
{
	std::cout << /*(*(_ins[14]))->getName() << */"=" << (*(_ins[14]))->compute(2) << std::endl;
	std::cout << "display\n";
}

int	Prompt::dump(Parser *parse)
{
	int		i = 0;

	while (i < _ins.size()) {
		std::cout << (*(_ins[i]))->getName() << "=";
		std::cout << (*(_ins[i++]))->compute() << std::endl;
	}
}

int	Prompt::init_Pins(Parser *parse)
{
	int				i = 0;
	std::string			elem;
	nts::AComponent			*comp;
	std::vector<std::pair<std::string, std::string> >	comps;

	comp = new nts::AComponent();
	comps = parse->get_comps();
	std::cout << "test\n";
	while (i < comps.size()) {
		_ins.push_back(comp->createComponent(comps[i].first, comps[i].second));
		i++;
	}
}

int	Prompt::setInput(std::string str)
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
		(*(_ins[i]))->setState((nts::Tristate)1, (size_t)0);
	else
		(*(_ins[i]))->setState((nts::Tristate)0, (size_t)0);
	return (0);
}

int	Prompt::parse_entry(std::string str, Parser *parse)
{


	if (!g_funcs[str]) {
		if (str == "exit" || (str.find('=') != std::string::npos && setInput(str) == 1))
			return 1;
		if (str.find("=") != std::string::npos)
			setInput(str);
		return 0;
	}
	(this->*g_funcs[str])(parse);
	return (0);
}

void	Prompt::print_prompt(Parser *parse)
{
	std::string	entry;

	std::cout << "test\n";
	init_Pins(parse);
	do {
		g_isLoop = 2;
		std::cout << "> ";
		std::cin >> entry;
	} while (parse_entry(entry, parse) != 1);
}

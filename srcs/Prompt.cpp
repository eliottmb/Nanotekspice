//
// EPITECH PROJECT, 2018
// nts
// File description:
//
//

#include <map>
#include <iostream>
#include <csignal>
#include <memory>
#include "../include/Prompt.hpp"

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

int	Prompt::getRightComp(std::string name)
{
	for (int i = 0; i < _ins.size(); i++)
		if ((*(_ins[i]))->getName() == name)
			return (i);
	return -1;
}

int	Prompt::simulate(Parser *parse)
{
	nts::Tristate	state;
	size_t	pin;

	for (int j = 0; j < links.size(); j++) {
		for (int i = 0; i < _ins.size(); i++) {
			if ((*(_ins[i]))->getName() == links[j]._comp)
				for (int k = 0; k < _ins.size(); k++) {
					if ((*(_ins[k]))->getName() == links[j]._comp1)
					(*(_ins[k]))->setState((*(_ins[i]))->getPinAddr(
								       stoul(links[j]._pin) - 1),
							       stoul(links[j]._pin1) - 1);
					(*(_ins[i]))->compute();
				}
		}
	}
	for (int i = 0; i < _ins.size(); i++)
		(*(_ins[i]))->compute();
}

int	Prompt::loop(Parser *parse)
{
	g_isLoop = 1;
	std::signal(SIGINT, sighandler);
	while (1) {
		simulate(parse);
		if (g_sig != 0)
			break;
	}
	return 0;
}

int	Prompt::display(Parser *parse)
{
	std::vector<std::string>	outs = parse->get_out();

	for (int i = 0; i < outs.size(); i++) {
		for (int j = 0; j < _ins.size(); j++)
			if ((*(_ins[j]))->getName() == outs[i])
				(*(_ins[j]))->dump();
	}
}

int	Prompt::dump(Parser *parse)
{
	int		i = 0;

	while (i < _ins.size()) {
		(*(_ins[i++]))->dump();
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
	links = parse->getLinks();
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
	if (i == _ins.size())
	    return 0;
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

void	Prompt::print_prompt(Parser *parse, char **av)
{
	std::string	entry;
	int		i = 2;

	init_Pins(parse);
	if (av[2])
		while (av[i])
			parse_entry(av[i++], parse);
	simulate(parse);
	display(parse);
	do {
		g_isLoop = 2;
		std::cout << "> ";
		std::getline(std::cin, entry);
	} while (!std::cin.eof() && parse_entry(entry, parse) != 1);
}

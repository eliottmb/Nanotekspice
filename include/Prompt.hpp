//
// EPITECH PROJECT, 2018
// nanotekspice
// File description:
// simulate chipsets
//

#ifndef PROMPT_T_
# define PROMPT_T_

# include <iostream>
# include <vector>
# include "../include/IComponent.hpp"
# include <memory>
# include "Parser.hpp"
# include "../components/include/Input.hpp"
# include "../components/include/4081.hpp"
# include "../components/include/Output.hpp"

class	Prompt
{
	std::vector<std::unique_ptr<nts::IComponent> *>		_ins;
	std::vector<std::unique_ptr<nts::IComponent> >		_out;
	std::map<std::string, int (Prompt::*)(Parser *)>	g_funcs;
	std::unique_ptr<ErrorManage>				e;
	std::vector<Link>					links;

public:
	Prompt(char **av);
	~Prompt();

	void	print_prompt(Parser *parse, char **av);
	int	dump(Parser *);
	int	display(Parser *);
	int	loop(Parser *);
	int	simulate(Parser *);
	int	init_Pins(Parser *);
	int	setInput(std::string str);
	int	parse_entry(std::string, Parser *);
	int	getRightComp(std::string);
};

#endif /* PROMPT_H_ */

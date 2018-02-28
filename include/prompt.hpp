//
// EPITECH PROJECT, 2018
// nts
// File description:
//
//

#ifndef PROMPT_T_
# define PROMPT_T_

# include "AComponent.hpp"
# include "IComponent.hpp"
# include "Parser.hpp"
# include "../components/include/Input.hpp"
# include "../components/include/4081.hpp"

int	dump(Parser *);
int	display(Parser *);
int	loop(Parser *);
int	simulate(Parser *);

std::vector<std::unique_ptr<nts::IComponent> *> _ins;
std::vector<std::unique_ptr<nts::IComponent> *> _out;

#endif /* PROMPR_H_ */

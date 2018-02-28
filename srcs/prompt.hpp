//
// EPITECH PROJECT, 2018
// nts
// File description:
//
//

#ifndef PROMPT_T_
# define PROMPT_T_

#include "../include/AComponent.hpp"
#include "../include/IComponent.hpp"
#include "../include/Parser.hpp"
# include "../include/Input.hpp"

int	dump(Parser *);
int	display(Parser *);
int	loop(Parser *);
int	simulate(Parser *);

std::vector<std::unique_ptr<nts::IComponent> *> _ins;

#endif /* PROMPR_H_ */

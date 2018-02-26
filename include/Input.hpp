//
// EPITECH PROJECT, 2018
// Input
// File description:
//
//

#ifndef INPUT_H_
# define INPUT_H_

# include "AComponent.hpp"

namespace	nts {
	class	Input;
};

class	nts::Input : public nts::AComponent
{
	std::string	_name;
	std::vector<nts::Tristate>	_pin;

public:
	Input(const std::string &name);
	virtual ~Input() {};
};

#endif /* INPUT_H_ */

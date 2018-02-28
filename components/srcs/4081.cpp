//
// EPITECH PROJECT, 2018
// 4081
// File description:
//
//

#include "../include/4081.hpp"

nts::C4081::C4081(const std::string &name) : _name(name), nb_in(8), nb_out(4)
{
	for (int i = 0; i < 14; i++)
		_pins.push_back(UNDEFINED);
}

nts::Tristate	nts::C4081::compute(std::size_t pin)
{
	_pins[3] = my_and(_pins[1], _pins[2]);
	_pins[4] = my_and(_pins[5], _pins[6]);
	_pins[10] = my_and(_pins[8], _pins[9]);
	_pins[11] = my_and(_pins[12], _pins[13]);
}

void		nts::C4081::setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin)
{
	return ;
}

void		nts::C4081::dump() const
{
	std::cout << _name << std::endl;
}

std::string	nts::C4081::getName() const
{
	std::cout << _name << std::endl;
}

void		nts::C4081::setState(nts::Tristate state)
{
	return ;
}

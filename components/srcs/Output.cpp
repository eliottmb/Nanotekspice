//
// EPITECH PROJECT, 2018
// output
// File description:
//
//

#include "../include/Output.hpp"

nts::Output::Output(const std::string &name) : _name(name)
{
	_pin.push_back(FALSE);
}

nts::Tristate	nts::Output::compute(std::size_t pin)
{
	return _pin[0];
}

void	nts::Output::setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin)
{
	std::cout << "setLink\n";
}

void	nts::Output::dump() const
{
	std::cout << "dump\n";
}

std::string	nts::Output::getName() const
{
	return _name;
}

void		nts::Output::setState(nts::Tristate state)
{
	_pin[0] = state;
}
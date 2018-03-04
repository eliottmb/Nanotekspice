//
// EPITECH PROJECT, 2018
// nanotekspice
// File description:
// simulate chipsets
//

#include "../include/Output.hpp"

nts::Output::Output(const std::string &name) : _name(name)
{
	_pin.push_back(nts::FALSE);
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
	std::cout << _name << "=";
	if (_pin[0] == nts::UNDEFINED)
		std::cout << "U\n";
	else
		std::cout << _pin[0] << std::endl;
}

std::string	nts::Output::getName() const
{
	return _name;
}

void		nts::Output::setState(nts::Tristate state, size_t pinNumber)
{
	_pin[0] = state;
}

nts::Tristate	nts::Output::getPinAddr(size_t pin)
{
	return _pin[pin];
}

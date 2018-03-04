//
// EPITECH PROJECT, 2018
// nanotekspice
// File description:
// simulate chipsets
//

#include "../include/Input.hpp"

nts::Input::Input(const std::string &name) : _name(name)
{
	_pin.push_back(FALSE);
}

nts::Tristate	nts::Input::compute(std::size_t pin)
{
	return _pin[0];
}

void	nts::Input::setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin)
{
	std::cout << "setLink\n";
}

void	nts::Input::dump() const
{
	std::cout << _name << "=";
	if (_pin[0] == nts::UNDEFINED)
		std::cout << "U\n";
	else
		std::cout << _pin[0] << std::endl;
}

std::string	nts::Input::getName() const
{
	return _name;
}

void		nts::Input::setState(nts::Tristate state, size_t pinNumber)
{
	_pin[pinNumber] = state;
}

nts::Tristate	nts::Input::getPinAddr(size_t pinNum)
{
	return _pin[pinNum];
}

//
// EPITECH PROJECT, 2018
// nanotekspice
// File description:
// simulate chipsets
//

#include "../include/4071.hpp"

nts::C4071::C4071(const std::string &name) : _name(name), nb_in(8), nb_out(4)
{
	for (int i = 0; i < 13; i++)
		_pins.push_back(UNDEFINED);
}

nts::Tristate	nts::C4071::compute(std::size_t pin)
{
	_pins[2] = my_or(_pins[0], _pins[1]);
	_pins[3] = my_or(_pins[4], _pins[5]);
	_pins[9] = my_or(_pins[7], _pins[8]);
	_pins[10] = my_or(_pins[11], _pins[12]);
	return _pins[pin];
}

void		nts::C4071::setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin)
{
	_pins[pin] = other.getPinAddr(otherPin);
}

void		nts::C4071::dump() const
{
	int	i = 0;

	while (i < _pins.size()) {
		std::cout << _name << "[" << i << "]" << "=";
		if (_pins[i] == nts::UNDEFINED)
			std::cout << "U\n";
		else
			std::cout << _pins[i] << std::endl;
		i++;
	}
}

std::string	nts::C4071::getName() const
{
	return _name;
}

void		nts::C4071::setState(nts::Tristate state, size_t pinNumber)
{
	_pins[pinNumber] = state;
}

nts::Tristate	nts::C4071::getPinAddr(size_t pinNum)
{
	return _pins[pinNum];
}

//
// EPITECH PROJECT, 2018
// AComponent
// File description:
//
//

#include "AComponent.hpp"
#include "IComponent.hpp"

std::map<std::string, std::function<std::unique_ptr<nts::IComponent> *(const std::string &value)> > nts::AComponent::_funcs;

nts::AComponent::AComponent()
{
	_funcs.insert(std::make_pair("input", std::bind(&nts::AComponent::createInput, this, std::placeholders::_1)));
	_funcs.insert(std::make_pair("output", std::bind(&nts::AComponent::createOutput, this, std::placeholders::_1)));
}

nts::AComponent::~AComponent() {}

std::unique_ptr<nts::IComponent>        *nts::AComponent::createInput(const std::string &value) const
{
	std::cout << value << std::endl;
}

std::unique_ptr<nts::IComponent>	*nts::AComponent::createOutput(const std::string &value) const
{
	std::cout << value << std::endl;
}

std::unique_ptr<nts::IComponent>	*nts::AComponent::createComponent(const std::string &type, const std::string &value)
{
	_funcs[type](value);
}

nts::Tristate	nts::AComponent::compute(std::size_t pin)
{
	std::cout << "compute\n";
}

void	nts::AComponent::setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin)
{
	std::cout << "setLink\n";
}

void	nts::AComponent::dump() const
{
	std::cout << "dump\n";
}

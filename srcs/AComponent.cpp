//
// EPITECH PROJECT, 2018
// AComponent
// File description:
//
//

#include <functional>
#include "../include/AComponent.hpp"
#include "../include/IComponent.hpp"
#include "../include/Input.hpp"

std::map<std::string, std::function<std::unique_ptr<nts::IComponent> *(const std::string &value)> > nts::AComponent::_funcs;

nts::AComponent::AComponent()
{
//	std::cout << "AComponent created\n";
	_funcs.insert(std::make_pair("output", std::bind(&nts::AComponent::createOutput, this, std::placeholders::_1)));
	_funcs["input"] = std::bind(&nts::AComponent::createInput, this, std::placeholders::_1);
//	std::cout << "funcs inserted\n";
}

nts::AComponent::~AComponent() {}

std::unique_ptr<nts::IComponent>        *nts::AComponent::createInput(const std::string &value) const
{
	return new std::unique_ptr<nts::IComponent>(new nts::Input(value));
}

std::unique_ptr<nts::IComponent>	*nts::AComponent::createOutput(const std::string &value) const
{
	std::cout << value << std::endl;
}

std::unique_ptr<nts::IComponent>	*nts::AComponent::createComponent(const std::string &type, const std::string &value)
{
	_funcs[type](value);
}

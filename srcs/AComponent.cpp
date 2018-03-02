//
// EPITECH PROJECT, 2018
// AComponent
// File description:
//
//

#include "../include/AComponent.hpp"

std::map<std::string, std::function<std::unique_ptr<nts::IComponent> *(const std::string &value)> > nts::AComponent::_funcs;

nts::AComponent::AComponent()
{
	_funcs.insert(std::make_pair("input", std::bind(&nts::AComponent::createInput, this, std::placeholders::_1)));
	_funcs.insert(std::make_pair("output", std::bind(&nts::AComponent::createOutput, this, std::placeholders::_1)));
	_funcs.insert(std::make_pair("4081", std::bind(&nts::AComponent::create4081, this, std::placeholders::_1)));
}

nts::AComponent::~AComponent() {}

std::unique_ptr<nts::IComponent>        *nts::AComponent::createInput(const std::string &value) const
{
	return new std::unique_ptr<nts::IComponent>(new nts::Input(value));
}

std::unique_ptr<nts::IComponent>	*nts::AComponent::createOutput(const std::string &value) const
{
	return new std::unique_ptr<nts::IComponent>(new nts::Input(value));
}

std::unique_ptr<nts::IComponent>	*nts::AComponent::create4081(const std::string &value) const
{
	return new std::unique_ptr<nts::IComponent>(new nts::C4081(value));
}

std::unique_ptr<nts::IComponent>	*nts::AComponent::createComponent(const std::string &type, const std::string &value)
{
	_funcs[type](value);
}

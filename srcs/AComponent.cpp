//
// EPITECH PROJECT, 2018
// nanotekspice
// File description:
// simulate chipsets
//

#include "../include/AComponent.hpp"

std::map<std::string,std::function<std::unique_ptr<nts::IComponent> *(const std::string &value)> > nts::AComponent::_funcs;

nts::AComponent::AComponent()
{
	_funcs.insert(std::make_pair("input", std::bind(&nts::AComponent::createInput, this, std::placeholders::_1)));
	_funcs.insert(std::make_pair("output", std::bind(&nts::AComponent::createOutput, this, std::placeholders::_1)));
	_funcs.insert(std::make_pair("4081", std::bind(&nts::AComponent::create4081, this, std::placeholders::_1)));
	_funcs.insert(std::make_pair("4001", std::bind(&nts::AComponent::create4001, this, std::placeholders::_1)));
	_funcs.insert(std::make_pair("4011", std::bind(&nts::AComponent::create4011, this, std::placeholders::_1)));
	_funcs.insert(std::make_pair("4030", std::bind(&nts::AComponent::create4030, this, std::placeholders::_1)));
	_funcs.insert(std::make_pair("4069", std::bind(&nts::AComponent::create4069, this, std::placeholders::_1)));
	_funcs.insert(std::make_pair("4071", std::bind(&nts::AComponent::create4071, this, std::placeholders::_1)));
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

std::unique_ptr<nts::IComponent>	*nts::AComponent::create4001(const std::string &value) const
{
	return new std::unique_ptr<nts::IComponent>(new nts::C4001(value));
}
std::unique_ptr<nts::IComponent>	*nts::AComponent::create4011(const std::string &value) const
{
	return new std::unique_ptr<nts::IComponent>(new nts::C4011(value));
}
std::unique_ptr<nts::IComponent>	*nts::AComponent::create4030(const std::string &value) const
{
	return new std::unique_ptr<nts::IComponent>(new nts::C4030(value));
}
std::unique_ptr<nts::IComponent>	*nts::AComponent::create4069(const std::string &value) const
{
	return new std::unique_ptr<nts::IComponent>(new nts::C4069(value));
}
std::unique_ptr<nts::IComponent>	*nts::AComponent::create4071(const std::string &value) const
{
	return new std::unique_ptr<nts::IComponent>(new nts::C4071(value));
}

std::unique_ptr<nts::IComponent>	*nts::AComponent::createComponent(const std::string &type, const std::string &value)
{
	_funcs[type](value);
}

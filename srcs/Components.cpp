//
//EPITECH PROJECT, 2018
//PSU_2017_malloc
//File description:
//Makefile
//

#include "Components.hpp"

Components::Components()
{
    this->init_component_tab();
}

Components::~Components()
{

}

void	Components::init_component_tab()
{
	this->_my_components.push_back("4001");
	this->_my_components.push_back("4011");
	this->_my_components.push_back("4030");
	this->_my_components.push_back("4069");
	this->_my_components.push_back("4071");
	this->_my_components.push_back("4081");
}

int		Components::find_in_component_tab(std::string str)
{
	int	i = 0;
	int	tmp;

	while (i < _my_components.size())
	{
		tmp = str.compare(0, 4, this->_my_components[i]);
		if (tmp == 0)
			return (i);
		i = i + 1;
	}
	return (-1);
}

std::vector<std::string>    Components::getComponentTab()
{
    return (this->_my_components);
}
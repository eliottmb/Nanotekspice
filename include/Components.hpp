//
// EPITECH PROJECT, 2018
// nanotekspice
// File description:
// simulate chipsets
//

#ifndef __COMPONENTS_HPP__
# define __COMPONENTS_HPP__

#include <vector>
#include <string>

class	Components
{
public:
	Components();
	~Components();

	void				init_component_tab();
	int				find_in_component_tab(std::string str);
	std::vector<std::string>	getComponentTab();

private:
    std::vector<std::string>	_my_components;
};

#endif /* __COMPONENTS_HPP__ */
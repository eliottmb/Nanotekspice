//
//EPITECH PROJECT, 2018
//PSU_2017_malloc
//File description:
//Makefile
//

#ifndef __4069_HPP__
# define __4069_HPP__

#include "IComponent.hpp"

#include <vector>

namespace nts {
	class C4069;
};

class	C4069 : public nts::IComponent
{
	const int	nb_in;
	const int	nb_out;
	
	std::string			_name;
	std::vector<nts::Tristate>	_pins;

public:
	C4069(std::string);
	virtual ~C4069() {};
};


#endif /* __4069_HPP__ */
//
//EPITECH PROJECT, 2018
//PSU_2017_malloc
//File description:
//Makefile
//

#ifndef __4013_HPP__
# define __4013_HPP__

#include "IComponent.hpp"

#include <vector>

namespace nts {
	class C4013;
};

class	C4013 : public nts::IComponent
{
	const int	nb_in;
	const int	nb_out;
	
	std::string			_name;
	std::vector<nts::Tristate>	_pins;

public:
	C4013(std::string);
	virtual ~C4013() {};
};


#endif /* __4013_HPP__ */
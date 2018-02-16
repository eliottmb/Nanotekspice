//
// EPITECH PROJECT, 2018
// 4081
// File description:
//
//

#ifndef	C4081_H_
# define C4081_H_

#include "IComponent.hpp"

namespace nts {
	class C4081;
};

class	C4081 : public nts::IComponent
{
	std::string			_name;
	std::vector<nts::Tristate>	_pins;

public:
	C4081(std::string);
	virtual ~C4081() {};
};

#endif /* C4081_H_ */

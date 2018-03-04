//
// EPITECH PROJECT, 2018
// 4001
// File description:
//
//

#ifndef	__C4001_HPP__
# define __C4001_HPP__

# include "AComponent.hpp"
# include "gate.hpp"
# include "4001.hpp"
# include <vector>

namespace nts {
	class C4001;
};

class	nts::C4001 : public nts::IComponent
{
	const int	nb_in;
	const int	nb_out;

	std::string			_name;
	std::vector<nts::Tristate>	_pins;

public:
	C4001(const std::string &name);
	virtual ~C4001() {};

public:
	virtual nts::Tristate	compute(std::size_t pin = 1);
	virtual void		setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin);
	virtual void		dump() const;
	virtual std::string	getName() const;
	virtual void		setState(nts::Tristate, size_t);
	virtual nts::Tristate	getPinAddr(size_t);
};

#endif /* __C4001_HPP__ */

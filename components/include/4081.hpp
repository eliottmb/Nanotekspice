//
// EPITECH PROJECT, 2018
// 4081
// File description:
//
//

#ifndef	C4081_H_
# define C4081_H_

# include "../../include/AComponent.hpp"
//# include "../../include/IComponent.hpp"
# include "gate.hpp"

# include <vector>

namespace nts {
	class C4081;
};

class	nts::C4081 : public nts::IComponent
{
	const int	nb_in;
	const int	nb_out;

	std::string			_name;
	std::vector<nts::Tristate>	_pins;

public:
	C4081(const std::string &name);
	virtual ~C4081() {};

public:
	virtual nts::Tristate	compute(std::size_t pin = 1);
	virtual void		setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin);
	virtual void		dump() const;
	virtual std::string		getName() const;
	virtual void	setState(nts::Tristate, size_t);
};

#endif /* C4081_H_ */

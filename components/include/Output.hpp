//
// EPITECH PROJECT, 2018
// Output
// File description:
//
//

#ifndef OUTPUT_H_
# define OUTPUT_H_

# include "../../include/AComponent.hpp"
//# include "../../include/IComponent.hpp"
# include "gate.hpp"

namespace	nts {
	class	Output;
};

class	nts::Output : public nts::IComponent
{
	std::string	_name;
	std::vector<nts::Tristate>	_pin;

public:
	Output(const std::string &name);
	virtual ~Output() {};

public:
	virtual nts::Tristate	compute(std::size_t pin = 1);
	virtual void		setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin);
	virtual void		dump() const;
	virtual std::string		getName() const;
	virtual void	setState(nts::Tristate);
};

#endif /* OUTPUT_H_ */

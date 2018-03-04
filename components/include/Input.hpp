//
// EPITECH PROJECT, 2018
// nanotekspice
// File description:
// simulate chipsets
//

#ifndef INPUT_H_
# define INPUT_H_

# include "../../include/AComponent.hpp"
# include "../../include/IComponent.hpp"
# include "Gate.hpp"

namespace	nts {
	class	Input : public nts::IComponent
	{
		std::string			_name;
		std::vector<nts::Tristate>	_pin;

	public:
		Input(const std::string &name);
		virtual ~Input() {};

	public:
		virtual nts::Tristate	compute(std::size_t pin = 1);
		virtual void		setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin);
		virtual void		dump() const;
		virtual std::string	getName() const;
		virtual void		setState(nts::Tristate, size_t);
		virtual nts::Tristate	getPinAddr(size_t);
	};
};

#endif /* INPUT_H_ */

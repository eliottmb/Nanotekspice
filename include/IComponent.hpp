//
// EPITECH PROJECT, 2018
//
// File description:
//
//

#ifndef ICOMP
# define ICOMP

# include <iostream>

namespace	nts
{
	enum Tristate {
		UNDEFINED = (-true),
		TRUE = true,
		FALSE = false
	};

	class	IComponent
	{
	public:
		virtual	~IComponent() {};

	public:
		virtual nts::Tristate	compute(std::size_t pin = 1) = 0;
		virtual void		setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin) = 0;
		virtual	void		dump() const = 0;
		virtual std::string	getName() const = 0;
		virtual void		setState(nts::Tristate, size_t) = 0;
	};
}

#endif /* ICOMP */

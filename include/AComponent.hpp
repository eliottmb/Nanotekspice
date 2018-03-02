//
// EPITECH PROJECT, 2018
// AComponenet
// File description:
//
//

#ifndef ACOMP_H_
# define ACOMP_H_

# include <functional>
# include <vector>
# include <iostream>
# include <map>
# include <memory>
# include "IComponent.hpp"
# include "../components/include/Input.hpp"
# include "../components/include/Output.hpp"
# include "../components/include/4081.hpp"
namespace	nts {
	class AComponent;
}

class	nts::AComponent
{
	static std::map<std::string, std::function<std::unique_ptr<nts::IComponent> *(const std::string &value)> > _funcs;

public:
	AComponent();
	virtual ~AComponent();

public:
	std::unique_ptr<nts::IComponent>	*createComponent(const std::string &type,
								const std::string &value);

private:
	std::unique_ptr<nts::IComponent>	*createInput(const std::string &value) const;
	std::unique_ptr<nts::IComponent>	*createOutput(const std::string &value) const;
	std::unique_ptr<nts::IComponent>	*create4081(const std::string &value) const;
};

#endif /* ACOMP_H_ */

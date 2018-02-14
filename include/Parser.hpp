//
//EPITECH PROJECT, 2018
//PSU_2017_malloc
//File description:
//Makefile
//

#ifndef __PARSER_HPP__
# define __PARSER_HPP__

#include <fstream>
#include <vector>
#include <string>

class	Parser
{
	int		_state;
	std::ifstream	_file;
	std::string	_str;
	std::vector<std::string>	_in;
	std::vector<std::string>	_out;
	
public:
	
	Parser(int argc, char **argv);
	~Parser();

	void	set_state();
	int	get_state();
	void	show_vector();
	int	find_match();
	void	clean_tab();
	

private:
	bool	error_manage(int argc, char **argv);
};

#endif /* __PARSER_HPP__ */
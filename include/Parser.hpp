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
#include <map>
#include "ErrorManage.hpp"

class	Parser
{
	int		_state;
	std::ifstream	_file;
	std::string	_str;
	ErrorManage					*_err;
	std::vector<std::string>	_in;
	std::vector<std::string>	_out;
	std::vector<std::pair<std::string, std::string> > _comps;
	std::map<std::pair<std::string, std::size_t>, std::pair<std::string, std::size_t> > _my_map;
	
public:
	Parser(int argc, char **argv, ErrorManage *err);
	~Parser();

	void				set_state();
	int				get_state();
	void				show_vector();
	int				find_match();
	void				clean_tab();
	std::vector<std::string>	get_Ins();
	void			get_pair_vector();
	void			show_pair();
	void			fill_map();

private:
	
};

#endif /* __PARSER_HPP__ */
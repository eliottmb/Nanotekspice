//
//EPITECH PROJECT, 2018
//PSU_2017_malloc
//File description:
//Makefile
//

#ifndef __ERRORMANAGE_HPP__
# define __ERRORMANAGE_HPP__

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

class	ErrorManage
{
public:
	ErrorManage(std::string path);
	~ErrorManage();
	
	void		init_component_tab();
	int		find_in_component_tab();
	bool		check_for_empty_line();
	bool		check_for_tab();
	bool		check_for_useless_space();
	bool		check_for_name();
	const char	*to_c_star(std::string str);
	int		my_find(std::string from, char c);
	bool		back_in();
private:
	std::string			_name;
	std::string			_path;
	std::ifstream			_file;
	std::string			_str;
	std::ofstream			_douille;
	std::vector<std::string>	_my_components;
	};

#endif /* __ERRORMANAGE_HPP__ */
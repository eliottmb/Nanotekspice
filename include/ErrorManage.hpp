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
#include "Components.hpp"

class	ErrorManage
{
public:
	ErrorManage(std::string path);
	~ErrorManage();
	
	bool		do_all_checks();
	void		check_for_coms();
	void		check_for_empty_line();
	void		check_for_tabs();
	void		check_for_useless_space();
	bool		check_for_names();
	bool		check_for_struct();
	bool		check_for_links(std::string to_test);
	bool		back_in();

	Components	_my_comps;
	std::string	_path;
	
private:
	std::ifstream	_file;
	std::string	_str;
	std::ofstream	_douille;
	};

#endif /* __ERRORMANAGE_HPP__ */
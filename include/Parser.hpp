//
// EPITECH PROJECT, 2018
// nanotekspice
// File description:
// simulate chipsets
//

#ifndef __PARSER_HPP__
# define __PARSER_HPP__

#include <fstream>
#include <vector>
#include <string>
#include <map>
#include "ErrorManage.hpp"
#include "Link.hpp"

class	Parser
{
	int							_state;
	std::string 						_path;
	std::ifstream						_file;
	std::string						_str;
	Components						_my_comps;
	std::vector<std::string>				_in;
	std::vector<std::string>				_out;
	std::vector<std::pair<std::string, std::string> >	_comps;
	std::vector<Link> 					_my_links;

public:
	Parser(std::string path);
	~Parser();

	void							set_state();
	int							get_state();
	void							show_vector();
	int							find_match();
	void							clean_tab();
	std::vector<std::pair<std::string, std::string>	>	get_comps();
	void							make_pair_vector();
	void							show_pair();
	void							check_names_in_vector();
	void							find_links();
	void							check_links();
	Link							reverse_link(Link l);
	void							fill_map();
	void							show_killing_death_vector();
	std::vector<Link>					getLinks();
	std::vector<std::string>				get_out();

private:
};

#endif /* __PARSER_HPP__ */

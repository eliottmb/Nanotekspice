//
//EPITECH PROJECT, 2018
//PSU_2017_malloc
//File description:
//Makefile
//

#ifndef __PARSER_HPP__
# define __PARSER_HPP__

class	Parser
{
public:
	Parser(int argc, char **argv);
	~Parser();

private:
	bool	error_manage(int argc, char **argv);
};

#endif /* __PARSER_HPP */
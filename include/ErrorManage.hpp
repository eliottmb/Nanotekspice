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

class	ErrorManage
{
public:
    ErrorManage(std::string path);
    ~ErrorManage();
    
    bool        check_for_empty_line();
    bool        check_for_tab();
    const char  *to_c_star(std::string str);
    bool        back_in();
private:
    std::string     _path;
    std::ifstream	_file;
	std::string	    _str;
    std::ofstream   _douille;
};

#endif /* __ERRORMANAGE_HPP__ */
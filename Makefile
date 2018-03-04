##
## EPITECH PROJECT, 2018
## PSU_2017_malloc
## File description:
## Makefile
##

CXX	= g++-6 -I./include/

RM	= rm -f

CXXLAGS	+= -W -Wall -Wextra -Werror -std=c++17

NAME		= nanotekspice

SRCS		= 	  srcs/main.cpp			\
		  	  srcs/Parser.cpp		\
		  	  srcs/ErrorManage.cpp	\
			  srcs/Link.cpp			\
			  srcs/Components.cpp		\
			  srcs/AComponent.cpp		\
			  srcs/gate.cpp			\
			  srcs/prompt.cpp		\
			  components/srcs/Input.cpp	\
			  components/srcs/Output.cpp	\
			  components/srcs/4001.cpp	\
			  components/srcs/4011.cpp	\
			  components/srcs/4030.cpp	\
			  components/srcs/4069.cpp	\
			  components/srcs/4071.cpp	\
			  components/srcs/4081.cpp

OBJS		= $(SRCS:.cpp=.o)

RED             =       \033[0;31m
CYAN            =       \033[0;36m
BLUE            =       \033[1;34m
GREEN           =       \033[0;32m
PURPLE          =       \033[0;35m
UNSET           =       \033[0m

all: $(NAME)

$(NAME):	$(OBJS)
		@$(CXX) -o $(NAME) $(SRCS) $(CXXFLAGS)

clean:
	$(RM) $(OBJS)

fclean:	clean
	$(RM) $(NAME)

re: fclean all

.cpp.o:
	@$(CXX) -c $< -o $(CXXFLAGS) $@
	@printf "$(GREEN)[compiled] $(CYAN) -I./include/ $(BLUE) \
	-W -Wall -Wextra -Werror $(PURPLE)$@\n$(UNSET)"

.PHONY: all clean fclean re
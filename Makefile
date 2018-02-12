##
## EPITECH PROJECT, 2018
## PSU_2017_malloc
## File description:
## Makefile
##

CC	= clang++ #-I./include/

RM	= rm -f

CFLAGS	+= -lm -W -Wall -Wextra # -Werror

NAME		= nanotekspice

SRCS		= srcs/main.cpp

OBJS		= $(SRCS:.cpp=.o)

RED             =       \033[0;31m
CYAN            =       \033[0;36m
BLUE            =       \033[1;34m
GREEN           =       \033[0;32m
PURPLE          =       \033[0;35m
UNSET           =       \033[0m

all: $(NAME)

$(NAME):	$(OBJS)
		@$(CC) -o $(NAME) $(SRCS) $(CFLAGS)

clean:
	$(RM) $(OBJS)

fclean:	clean
	$(RM) $(NAME)

re: fclean all

.c.o:
	@$(CC) -c $< -o $@
	@printf "$(GREEN)[compiled] $(BLUE)$@\n$(UNSET)"



.PHONY: all clean fclean re

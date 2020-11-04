##
## EPITECH PROJECT, 2018
## DANTE_2018
## File description:
## generator_Makefile
##

SRC			=	src/main.cpp	\
					src/randy.cpp	\
					src/body.cpp\
					src/class/entityClass.cpp\
					src/class/settingClass.cpp

OBJ_SRC		=	$(SRC:.cpp=.o)

NAME		=	 generator

CC			=	g++

override CFLAGS	+= -Wall -Wextra -Werror  -lncurses

$(NAME): $(OBJ_SRC)
	@echo -e "\e[36;1m\nMAKE $(NAME)\n\e[0m"
	@$(CC) $(CFLAGS) $^ -o $@

all:$(NAME)

clean:
	@echo -e "\e[31;1mCLEANING OBJ: $(NAME)\e[0m"
	@rm -rf $(OBJ_SRC)

fclean: clean
	@echo -e "\033[31;1mCLEANING: $(NAME)\033[0m"
	@rm -f $(NAME) $(NAME_TESTS)

re:	fclean	all

.PHONY:	all	clean	fclean	re

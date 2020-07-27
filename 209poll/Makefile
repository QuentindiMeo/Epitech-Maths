##
## EPITECH PROJECT, 2020
## 209poll_2019
## File description:
## Makefile
##

SRC	=	src/Tools.cpp	\
		src/Core.cpp	\
		src/Poll.cpp	\

OBJ	=	$(SRC:.cpp=.o)

INCLUDE	=	include/

CC	=	@g++

CFLAGS	=	-Wall -Werror -Wreorder -Wextra --pedantic

CPPFLAGS	=	-I $(INCLUDE)

NAME	=	209poll

all: $(NAME)

$(NAME): $(OBJ)
	@echo Compiling \'$(NAME)\'
	$(CC) -o $(NAME) $(OBJ) $(CPPFLAGS)
	@echo \'$(NAME)\' compiled successfully

clean:
	@rm -rf $(OBJ)
	@echo Cleaned .o for \'$(NAME)\'

fclean:	clean
	@rm -rf $(NAME)
	@echo Cleaned \'$(NAME)\'

re: fclean all

.PHONY: clean fclean re 209poll

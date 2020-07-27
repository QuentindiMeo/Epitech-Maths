##
## EPITECH PROJECT, 2020
## 205IQ_2019
## File description:
## Makefile
##

SRC	=	src/Tools.cpp	\
		src/Core.cpp	\
		src/IQ.cpp	\

OBJ	=	$(SRC:.cpp=.o)

INCLUDE	=	include/

CC	=	@g++

CFLAGS	=	-Wall -Werror -Wreorder -Wextra --pedantic

NAME	=	205IQ

CPPFLAGS	=	-I $(INCLUDE)

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

.PHONY: clean fclean re 205IQ

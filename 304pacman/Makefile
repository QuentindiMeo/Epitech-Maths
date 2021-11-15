##
## EPITECH PROJECT, 2021
## 304pacman
## File description:
## Makefile
##

CP	=	cp -f
RM	=	rm -rf
CHMOD	=	chmod 777
ECHO	=	/bin/echo -e
EXEC	=	python

SRC	=	pacman.py
NAME	=	304pacman
TEST	=	pytest.py
CACHE	=	__pycache__

all: $(NAME)

$(NAME):
	@$(CP) $(SRC) $(NAME)
	@$(CHMOD) $(NAME)
	@$(ECHO) $(GRN) " [OK]" $(BLU)$(SRC)$(DEF)
	@$(ECHO) $(NAME)" rendered "$(BOLDGRN)"successfully"$(DEF)"!"

clean:
	@$(RM) $(NAME)
	@$(RM) $(CACHE)
	@$(ECHO) "Cleaned "$(NAME)

fclean:	clean

re: fclean all

run_tests:
	@$(EXEC) $(TEST) -vb

.PHONY: clean fclean re 304pacman run_tests

DEF	=	"\033[00m"
BLU	=	"\033[1;34m"
GRN	=	"\033[0;32m"
BOLDGRN	=	"\033[1;32m"
RED	=	"\033[1;31m"

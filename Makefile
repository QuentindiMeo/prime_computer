##
## PERSONAL PROJECT, 2019
## prime_computer
## File description:
## Makefile
##

SRC	=	src/prime_computer_readers.c	\
			src/main_prime_computer.c	\

OBJ	=	$(SRC:.c=.o)

HEADER_PATH     =       include/

CC	=	@gcc

LIB     =       include/libmy.a

CFLAGS	=	-I $(HEADER_PATH) -Wall -Werror -Wextra --pedantic

NAME	=	prime_computer

OUTPUTTXT	=	calculations_prime.txt

.PHONY: clean fclean re prime_computer prime_supercomputer

all: $(NAME)

$(NAME): $(OBJ)
	@echo Compiling \'$(NAME)\'
	$(CC) -o $(NAME) $(OBJ) $(LIB)
	@echo \'$(NAME)\' compiled successfully

clean:
	@rm -rf $(OBJ)
	@echo Cleaned .o for \'$(NAME)\'

fclean:	clean
	@rm -rf $(NAME)
	@echo Cleaned \'$(NAME)\'
	@rm -rf $(OUTPUTTXT)
	@echo Cleaned \'$(OUTPUTTXT)\'

re: fclean all

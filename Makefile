##
## PERSONAL PROJECT, 2019
## prime_computer
## File description:
## Makefile
##

SRCNORMAL	=	src/prime_computer_readers.c	\
			src/main_prime_computer.c	\

OBJNORMAL	=	$(SRCNORMAL:.c=.o)

HEADER_PATH     =       include/

CC	=	@gcc

LIB     =       include/libmy.a

CFLAGS	=	-I $(HEADER_PATH) -Wall -Werror -Wextra --pedantic

NAMENORMAL	=	prime_computer

OUTPUTTXT	=	calculations_prime.txt

.PHONY: clean fclean re prime_computer prime_supercomputer

all: $(NAMENORMAL)

$(NAMENORMAL): $(OBJNORMAL)
	@echo Compiling \'$(NAMENORMAL)\'
	$(CC) -o $(NAMENORMAL) $(OBJNORMAL) $(LIB)
	@echo \'$(NAMENORMAL)\' compiled successfully

clean:
	@rm -rf $(OBJNORMAL)
	@echo Cleaned .o for \'$(NAMENORMAL)\'

fclean:	clean
	@rm -rf $(NAMENORMAL)
	@echo Cleaned \'$(NAMENORMAL)\'
	@rm -rf $(OUTPUTTXT)
	@echo Cleaned \'$(OUTPUTTXT)\'

re: fclean all

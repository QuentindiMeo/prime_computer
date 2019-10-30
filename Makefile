##
## PERSONAL PROJECT, 2019
## prime_computer
## File description:
## Makefile
##

SRCNORMAL	=	src/prime_computer_readers.c	\
			src/prime_computer_rdwr.c	\

SRCSUPER	=	src/prime_computer_readers.c	\
			src/prime_supercomputer_rdwr.c	\

OBJNORMAL	=	$(SRCNORMAL:.c=.o)

OBJSUPER	=	$(SRCSUPER:.c=.o)

HEADER_PATH     =       include/

CC	=	@gcc

LIB     =       include/libmy.a

CFLAGS	=	-I $(HEADER_PATH) -Wall -Werror -Wextra --pedantic

NAMENORMAL	=	prime_computer

NAMESUPER	=	prime_supercomputer

.PHONY: clean fclean re prime_computer prime_supercomputer

all: $(NAMENORMAL) $(NAMESUPER)

$(NAMENORMAL): $(OBJNORMAL)
	@echo Compiling \'$(NAMENORMAL)\'
	$(CC) -o $(NAMENORMAL) $(OBJNORMAL) $(LIB)
	@echo \'$(NAMENORMAL)\' compiled successfully

$(NAMESUPER): $(OBJSUPER)
	@echo Compiling \'$(NAMESUPER)\'
	$(CC) -o $(NAMESUPER) $(OBJSUPER) $(LIB)
	@echo \'$(NAMESUPER)\' compiled successfully

clean:
	@rm -rf $(OBJNORMAL)
	@echo Cleaned .o for \'$(NAMENORMAL)\'
	@rm -rf $(OBJSUPER)
	@echo Cleaned .o for \'$(NAMESUPER)\'

fclean:	clean
	@rm -rf $(NAMENORMAL)
	@echo Cleaned \'$(NAMENORMAL)\'
	@rm -rf $(NAMESUPER)
	@echo Cleaned \'$(NAMESUPER)\'

re: fclean all

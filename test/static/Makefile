CC=gcc
CFLAGS=-Wall -Werror -Wextra

HARDWARE := $(shell uname -m)
OS := $(shell uname -s)

STATIC_LIB_NAME	= my_printf_$(HARDWARE)-$(OS)
LIB_DIR=../..
SRC= $(wildcard *.c)
OBJ= $(SRC:.c=.o)
DEPS = $(wildcard *.h)
LDFLAGS=
RM=rm -rf					
CLEAN=clean	
EXEC=a.out


all: $(OBJ)

main.o: ${DEPS}

%.o: %.c
	$(CC) $(CFLAGS) main.c -L$(LIB_DIR) -l$(STATIC_LIB_NAME)

.PHONY: all clean fclean re

clean:
	$(RM) -rf $(OBJ)

fclean: clean
	$(RM) $(EXEC)

re: fclean all


CC=gcc
CFLAGS=-Wall -Werror -Wextra

HARDWARE := $(shell uname -m)
OS := $(shell uname -s)

STATIC_LIB	= my_printf_static
DYNAMIC_LIB = my_printf_dynamic

STATIC_LIB_NAME	= libmy_printf_$(HARDWARE)-$(OS).a
DYNAMIC_LIB_NAME = libmy_printf_$(HARDWARE)-$(OS).so

SRC= $(wildcard *.c)
OBJ= $(SRC:.c=.o)
DEPS = $(wildcard *.h)
LDFLAGS=
RM=rm -rf					
CLEAN=clean	

all: $(STATIC_LIB) $(DYNAMIC_LIB)  

$(STATIC_LIB): $(OBJ)
	ar rc $(STATIC_LIB_NAME) $(OBJ)
	ranlib $(STATIC_LIB_NAME)

#$(STATIC_LIB): $(OBJ)
#	ar rc $(STATIC_LIB_NAME) $(OBJ)
#	ranlib $(STATIC_LIB_NAME)

$(DYNAMIC_LIB): $(OBJ)
	echo "Make $(DYNAMIC_LIB)"

main.o: ${DEPS}

%.o: %.c
	$(CC) -o $@ -c $< $(CFLAGS)

.PHONY: all clean fclean re

clean:
	$(RM) -rf $(OBJ)

fclean: clean
	$(RM) $(STATIC_LIB_NAME) $(DYNAMIC_LIB_NAME)

re: fclean all


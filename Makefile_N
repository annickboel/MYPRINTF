CC=gcc
CFLAGS=-Wall -Werror -Wextra
SRC= $(wildcard *.c)
OBJ= $(SRC:.c=.o)
DEPS = $(wildcard *.h)
LDFLAGS=
EXEC=my_printf
RM=rm -rf					
CLEAN=clean	

all: $(EXEC)

$(EXEC): $(OBJ)
	$(CC) -o $@ $^ $(LDFLAGS)

main.o: ${DEPS}

%.o: %.c
	$(CC) -o $@ -c $< $(CFLAGS)

.PHONY: all clean fclean re

clean:
	@rm -rf $(OBJ)

fclean: clean
	@rm -rf $(EXEC)

re: fclean all


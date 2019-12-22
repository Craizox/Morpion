CC = gcc
CFLAGS = -Wall -Werror -Wextra -std=c99
OBJS = $(addprefix src/, main.o check_win.o board.o)
BIN = morpion

all: $(BIN)

debug: CFLAGS += -g -fsanitize=address
debug: all

$(BIN): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

clean:
	$(RM) $(BIN) $(OBJS)

.PHONY: all clean debug

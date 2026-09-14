CC := cc
CFLAGS := -Wall -Wextra -Werror -g -O0 -march=native

SRC := ./main.c
OUT := ./data

all: $(SRC)
	$(CC) $(CFLAGS) $(SRC) -o $(OUT)

clean:
	rm -rf $(OUT)

run:
	$(OUT)

.PHONY: all clean run

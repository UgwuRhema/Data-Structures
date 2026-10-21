CC := cc
CFLAGS := -Wall -Wextra -Werror -g -O0 -march=native

SRC := ./main.c
OUT := ./data

VEC_IN := ./type_wise_vector.c
VEC := ./vec

all: $(SRC)
	$(CC) $(CFLAGS) $(SRC) -o $(OUT)

clean:
	rm -rf $(OUT)

tyv:
	$(CC) $(CFLAGS) -o $(VEC) $(VEC_IN)

run:
	$(OUT)

.PHONY: all clean run

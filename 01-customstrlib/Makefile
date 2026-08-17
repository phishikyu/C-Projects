# Variables
CC = gcc
CFLAGS = -Wall -Wextra -g
SRC = test.c customstrlib.c
HDR = customstrlib.h

OUTFILE = test
DEBUG_OUTFILE = test_debug

all: $(SRC) $(HDR)
	$(CC) $(CFLAGS) $(SRC) -o $(OUTFILE)

clean:
	rm -f $(OUTFILE) && rm -f $(DEBUG_OUTFILE)

run:
	make test && ./test

debug: $(SRC) $(HDR)
	$(CC) $(CFLAGS) -fsanitize=address $(SRC) -o $(DEBUG_OUTFILE)

rundebug: 
	make debug && ./test_debug
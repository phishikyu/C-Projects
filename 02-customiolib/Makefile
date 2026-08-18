# Variables
CC = gcc
CFLAGS = -Wall -Wextra -g
SRC = main.c customiolib.c
HDR = customiolib.h

OUTFILE = main
DEBUG_OUTFILE = main_debug

all: $(SRC) $(HDR)
	$(CC) $(CFLAGS) $(SRC) -o $(OUTFILE)

clean:
	rm -f $(OUTFILE) && rm -f $(DEBUG_OUTFILE)

run:
	make all && ./$(OUTFILE)

debug: $(SRC) $(HDR)
	$(CC) $(CFLAGS) -fsanitize=address $(SRC) -o $(DEBUG_OUTFILE)

rundebug: 
	make debug && ./$(DEBUG_OUTFILE)
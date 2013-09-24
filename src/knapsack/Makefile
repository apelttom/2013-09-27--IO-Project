#
# Simple Makefile
#
CC=gcc
SOURCES= knapsack.c
CFLAGS=-g
PROGRAM= knapsack

.PHONY: clean

OBJECTS:= $(SOURCES:.c=.o)

## Generic compilation rule
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

## Rule for making the actual target (link)
$(PROGRAM): $(OBJECTS)
	$(CC) $(OBJECTS) -o $@

clean:
	rm -f $(PROGRAM), rm -f $(OBJECTS)

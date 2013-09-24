#
# Simple Makefile
#
CC=gcc
SOURCES= main.c generator.c
SRC_DIR= ./src/
DIST_DIR= ./dist/
OBJ_DIR= ./obj/
HEADERS= header.h
CFLAGS=-g
PROGRAM= main

.PHONY: clean

OBJECTS:= $(SOURCES:.c=.o)

## Generic compilation rule
%.o: $(SRC_DIR)%.c $(SRC_DIR)$(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

## Rule for making the actual target (link)
$(DIST_DIR)$(PROGRAM): $(OBJECTS)
	$(CC) $(OBJECTS) -o $@

clean:
	rm -f $(DIST_DIR)$(PROGRAM), rm -f $(OBJECTS)

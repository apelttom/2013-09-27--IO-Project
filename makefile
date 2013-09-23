#
# Simple Makefile
#
CC=gcc
SOURCES= main.c generator.c
HEADERS= header.h
CFLAGS=-g
PROGRAM= main

.PHONY: clean

OBJECTS= $(SOURCES:.c=.o)

%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

$(PROGRAM): $(OBJECTS)
	$(CC) $(OBJECTS) -o $@

clean:
	rm -f $(PROGRAM) $(OBJECTS)

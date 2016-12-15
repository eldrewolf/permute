P = permute
CC = gcc
CFLAGS = -Wall -g -lm -O3 --std=c99
OBJECTS =
PREFIX = /usr/local

$(P): $(OBJECTS)

.PHONY: uninstall
uninstall:
	rm $(PREFIX)/bin/permute

.PHONY: install
install:
	mv permute $(PREFIX)/bin

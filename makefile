# Makefile for aipm.
#
# Author: Logan Savage
# Copyright (c) 2022 Logan Savage. Some Rights Reserved. See LICENSE.

TARGET := bin/aipm

# Compiler
CC       = gcc
CC_FLAGS = -pedantic -Wimplicit-function-declaration -Wreturn-type -g -c

# Linker
LINKER		 = gcc
LINKER_FLAGS =

# Get a list of the source files, header files, and object files for the
# compilation process
SOURCES  := $(wildcard src/*.c) 
HEADERS  := $(wildcard src/*.h)
OBJECTS  := $(SOURCES:src/%.c=obj/%.o)

###############################################################################

all: link

# Link the object files into a binary
link: $(OBJECTS)
	if [ ! -d "bin" ]; then mkdir bin; fi
	$(LINKER) $(LINKER_FLAGS) -o $(TARGET) $^

# Generate object file
obj/%.o: src/%.c
	if [ ! -d "obj" ]; then mkdir obj; fi
	$(CC) $(CC_FLAGS) -o $@ $<

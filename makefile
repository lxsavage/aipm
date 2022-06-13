# Makefile for aipm.
# Author: Logan Savage

###############################################################################

# Name of the outputted binary
TARGET	= bin/aipm

# Compiler
CC				= gcc
CC_FLAGS	= -pedantic -Wimplicit-function-declaration -Wreturn-type -O2 -c

# Linker
LINKER				= gcc
LINKER_FLAGS	=

# Get a list of the source files, header files, and object files for the
# compilation process
SOURCES	= $(wildcard src/*.c)
HEADERS	= $(wildcard src/*.h)
OBJECTS	= $(SOURCES:src/%.c=obj/%.o)

###############################################################################

# Build the project for installation by default
all: build

# Rebuild the project
rebuild: clean build

# Link the object files into a binary
build: $(OBJECTS)
	if [ ! -d "bin" ]; then mkdir bin; fi
	$(LINKER) $(LINKER_FLAGS) -o $(TARGET) $^

# Clear out all building files and binaries
clean:
	rm -rf bin/ obj/

# Generate object file
obj/%.o: src/%.c
	if [ ! -d "obj" ]; then mkdir obj; fi
	$(CC) $(CC_FLAGS) $(CC_FLAGS_RELEASE) -o $@ $<

##############################################################################

# Shell script aliases
install: install.sh
	./install.sh

uninstall: uninstall.sh
	./uninstall.sh

upgrade: upgrade.sh
	./upgrade.sh

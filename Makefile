# Compiler
COMPILER := g++

# Flags
FLAGS := -Wall -Wextra -Wshadow -Wnon-virtual-dtor -pedantic -Werror -Wconversion -g

# Include Directory
INCLUDES := -I ./include

# C++ Version
VERSION := -std=c++17

# Main file
MAIN := src/main.cpp

# Source Files
SOURCES := $(wildcard src/**/*.cpp)

# Object Files
OBJECTS := $(SOURCES:.cpp=.o)

# Executable
EXECUTABLE := app.exe

# Debug Executable
DEBUG_EXECUTABLE := debug_app.exe

# Test Source Files
TEST_SOURCES := $(shell find test -name '*.cpp')

# Test Object Files
TEST_OBJECTS := $(TEST_SOURCES:.cpp=.o)

# Test Executables
TEST_EXECUTABLES := $(TEST_OBJECTS:.o=.exe)

all: $(EXECUTABLE)

test: $(TEST_EXECUTABLES)

debug: $(DEBUG_EXECUTABLE)

%.exe: %.cpp $(OBJECTS) include/catch.o
	$(COMPILER) $(FLAGS) $(INCLUDES) $(VERSION) include/catch.o $< $(OBJECTS) -o $@

$(EXECUTABLE): $(OBJECTS) $(MAIN)
	$(COMPILER) $(FLAGS) $(INCLUDES) $(VERSION) $(OBJECTS) $(MAIN) -o $(EXECUTABLE)

$(DEBUG_EXECUTABLE): $(OBJECTS) $(MAIN)
	$(COMPILER) $(FLAGS) $(INCLUDES) $(VERSION) $(OBJECTS) $(MAIN) -o $(DEBUG_EXECUTABLE)

%.o: %.cpp
	$(COMPILER) $(FLAGS) $(INCLUDES) $(VERSION) -c $< -o $@

clean:
	rm -f $(OBJECTS) $(TEST_OBJECTS) $(EXECUTABLE) $(DEBUG_EXECUTABLE) $(TEST_EXECUTABLES) include/catch.o

.PHONY: all test clean debug

# Add separate debug and testing support in makefile
# Separate directory for external libraries
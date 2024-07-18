# Compiler
COMPILER := g++

# Flags
FLAGS := -Wall -Wextra -Wshadow -Wnon-virtual-dtor -pedantic -Werror

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

# Test Source Files
TEST_SOURCES := $(wildcard test/*.cpp) $(wildcard test/unit_tests/**/*.cpp)

# Test Object Files
TEST_OBJECTS := $(TEST_SOURCES:.cpp=.o)

# Test Executables
TEST_EXECUTABLES := $(TEST_OBJECTS:.o=.exe)

all: $(EXECUTABLE)

test: $(TEST_EXECUTABLES)

%.exe: %.cpp $(OBJECTS)
	$(COMPILER) $(FLAGS) $(INCLUDES) $(VERSION) $< $(OBJECTS) -o $@

$(EXECUTABLE): $(OBJECTS)
	$(COMPILER) $(FLAGS) $(INCLUDES) $(VERSION) $(OBJECTS) -o $(EXECUTABLE)

%.o: %.cpp
	$(COMPILER) $(FLAGS) $(INCLUDES) $(VERSION) -c $< -o $@

clean:
	rm -f $(OBJECTS) $(TEST_OBJECTS) $(EXECUTABLE)

.PHONY: all test clean
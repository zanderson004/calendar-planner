# Compiler
COMPILER = g++

# Flags
FLAGS = -Wall -Wextra -Wshadow -Wnon-virtual-dtor -pedantic -Werror -I ./include -std=c++17
#-Wall -Wextra -Wshadow -Wnon-virtual-dtor -pedantic

# Executable Target
TARGET = app.out

# Source Files
SOURCES = src/main.cpp src/implementations/*.cpp

# Object Files

all:
	$(COMPILER) $(FLAGS) $(SOURCES) -o $(TARGET)

run: all
	./$(TARGET)

clean:
	rm -f $(OBJS) $(TARGET)
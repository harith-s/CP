# Variables
CXX = g++
CXXFLAGS = -Wall -g -std=c++11

# Pattern rule to compile .cpp files to .o files
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Target to compile all .cpp files to .o files

OBJ_FILES = $(patsubst %.cpp, %.o, $(wildcard *.cpp))

all: $(OBJ_FILES)

# Clean up object files
clean:
	rm -f *.o
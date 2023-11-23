# Makefile for simple C++ project

CXX = g++  # Compiler
CXXFLAGS = -std=c++20 -Wall  # Compiler flags
SRC = main.cc Node.cc Calculator.cc  # Source files
TARGET = run  # Executable name

all: $(TARGET)

$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(SRC)

clean:
	rm -f $(TARGET)

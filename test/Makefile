SRC=$(wildcard *.cpp)
BIN=$(SRC:%.cpp=%)

CXX=g++
CXXFLAGS=-Wall -g -std=c++11

.PHONY: all
all:$(BIN)

.PHONY: clean
clean:
	rm -f $(BIN)

CXX = g++
CXXFLAGS = -std=c++14 -g -Wall -Wextra -Wpedantic
DEP_DIR = ./dependencies

all: tictactoe_unittest test

tictactoe_unittest: tictactoe_unittest.cc
	$(CXX) $(CXXFLAGS) -I$(DEP_DIR)/include -L$(DEP_DIR)/lib tictactoe_unittest.cc -lgtest_main -lgtest -lgmock -pthread -o $@

test:
	./tictactoe_unittest

clean:
	rm -f tictactoe_unittest

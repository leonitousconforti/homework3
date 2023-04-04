CXX=g++
CXXFLAGS = -std=c++14 -g -Wall
DEP_DIR= ../dependencies

all: fingerprinting fingerprinting_correct

fingerprinting: fingerprinting.cc
	$(CXX) $(CXXFLAGS) -I$(DEP_DIR)/include -L$(DEP_DIR)/lib fingerprinting.cc -lgtest_main -lgtest -lgmock -pthread -o $@

fingerprinting_correct: fingerprinting.cc
	$(CXX) $(CXXFLAGS) -I$(DEP_DIR)/include -L$(DEP_DIR)/lib fingerprinting.cc -lgtest_main -lgtest -lgmock -pthread -o $@

clean:
	rm -f fingerprinting

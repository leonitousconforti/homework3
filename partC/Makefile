CXX = g++
CXXFLAGS = -std=c++14 -g
DEP_DIR = ../dependencies

all: lightrail_unittest lightrail

lightrail: main.cc obj/*
	$(CXX) $(CXXFLAGS) -I$(DEP_DIR)/include -Iinclude -L$(DEP_DIR)/lib main.cc obj/* -o $@

lightrail_unittest: lightrail_unittest.cc obj/*
	$(CXX) $(CXXFLAGS) -I$(DEP_DIR)/include -Iinclude -L$(DEP_DIR)/lib lightrail_unittest.cc obj/* -lgtest_main -lgtest -lgmock -pthread -o $@

clean:
	rm -f lightrail_unittest lightrail

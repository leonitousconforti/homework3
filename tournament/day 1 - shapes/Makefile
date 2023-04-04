CXX=g++
CXXFLAGS = -std=c++14 -g
DEP_DIR= ../../dependencies

CLASSNAME = shapes

EXE = $(CLASSNAME).o

all: $(CLASSNAME)_unittest $(CLASSNAME)

$(CLASSNAME): $(EXE) main.cc
	$(CXX) $(CXXFLAGS) -I$(DEP_DIR)/include -Iinclude -L$(DEP_DIR)/lib $(EXE) main.cc -o $@

$(CLASSNAME)_unittest: $(EXE) $(CLASSNAME)_unittest.cc
	$(CXX) $(CXXFLAGS) -I$(DEP_DIR)/include -Iinclude -L$(DEP_DIR)/lib $(CLASSNAME)_unittest.cc $(EXE) -lgtest_main -lgtest -lgmock -pthread -o $@

clean:
	rm -f $(CLASSNAME)_unittest $(CLASSNAME)

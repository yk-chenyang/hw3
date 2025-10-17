CXX := g++
CXXFLAGS := -g -Wall --std=c++11
VALGRIND := valgrind --tool=memcheck --leak-check=yes

OBJS := llrec-tests.o llrec.o

all: llrec-test

#-----------------------------------------------------
# ADD target(s) to build your llrec-test executable
#-----------------------------------------------------
llrec-tests: $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $(OBJS)
llrec-tests.o: llrec-tests.cpp
	$(CXX) $(CXXFLAGS) -o $@ -c llrec-tests.cpp
llrec.o: llrec.cpp llrec.h
	$(CXX) $(CXXFLAGS) -o $@ -c llrec.cpp

clean:
	rm -f *.o rh llrec-test *~

.PHONY: clean
CXX = g++
CC  = $(CXX)

DEPFLAGS = -MT $@ -MMD -MP -MF $*.d

CPPFLAGS = -std=c++11 -I.
CXXFLAGS = -O2 -Wall -Wextra -pedantic-errors -Wold-style-cast 
CXXFLAGS += -std=c++11 
CXXFLAGS += -g
CXXFLAGS += $(DEPFLAGS)
LDFLAGS = -g 

PROG = A4_program

SRCS = vns.cc mns.cc umns.h hns.h
OBJS = $(SRCS:.cc=.o)

TEST_PROG = nstest
TEST_SRCS = nstest.cc
TEST_OBJS = $(TEST_SRCS:.cc=.o)

all: $(TEST_PROG)

$(PROG): $(OBJS)
	$(CXX) $(LDFLAGS) -o $@ $^


vns_test: vns.o
	$(CXX) $(LDFLAGS) -o $@ $^

%.o: %.cc
	$(CXX) $(CXXFLAGS) -c $< -o $@

test: $(TEST_PROG)
	./vns_test
	./mns_test 
	./umns_test 
	./hns_test 

.PHONY: all clean distclean

clean:
	rm -f *.o $(PROG) $(TEST_PROG)

distclean: clean
	rm -f *.d

SRC = $(wildcard *.cc)
-include $(SRC:.cc=.d)

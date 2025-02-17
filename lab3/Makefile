CXX = g++
CC  = $(CXX)

DEPFLAGS = -MT $@ -MMD -MP -MF $*.d

CPPFLAGS = -std=c++11 -I.
CXXFLAGS = -O2 -Wall -Wextra -pedantic-errors -Wold-style-cast 
CXXFLAGS += -std=c++11 
CXXFLAGS += -g
CXXFLAGS += $(DEPFLAGS)
LDFLAGS = -g 

PROG = A3_program

SRCS = date.cc date_test.cc
OBJS = $(SRCS:.cc=.o)

TEST_PROG = date_test
TEST_SRCS = date_test.cc
TEST_OBJS = $(TEST_SRCS:.cc=.o)

all: $(TEST_PROG)

$(PROG): $(OBJS)
	$(CXX) $(LDFLAGS) -o $@ $^


date_test: date_test.o date.o
	$(CXX) $(LDFLAGS) -o $@ $^

%.o: %.cc
	$(CXX) $(CXXFLAGS) -c $< -o $@

test: $(TEST_PROG)
	./date_test

.PHONY: all clean distclean

clean:
	rm -f *.o $(PROG) $(TEST_PROG)

distclean: clean
	rm -f *.d

SRC = $(wildcard *.cc)
-include $(SRC:.cc=.d)

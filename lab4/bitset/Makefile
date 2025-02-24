CXX = g++
CC  = $(CXX)

DEPFLAGS = -MT $@ -MMD -MP -MF $*.d

CPPFLAGS = -std=c++14 -I.
CXXFLAGS = -O2 -Wall -Wextra -pedantic-errors -Wold-style-cast 
CXXFLAGS += -g
CXXFLAGS += $(DEPFLAGS)
LDFLAGS = -g 

# Test executables
TEST_PROGS = bitsettest1 bitsettest2 simplebitsettest

# Common sources
COMMON_SRCS = bitset.cc bitreference.cc bitsetiterator.cc
COMMON_OBJS = $(COMMON_SRCS:.cc=.o)

# Specific sources for simplebitset
SIMPLEBITSET_SRCS = simplebitset.cc
SIMPLEBITSET_OBJS = $(SIMPLEBITSET_SRCS:.cc=.o)

# All targets
all: $(TEST_PROGS)

# Build each test separately with the correct dependencies
bitsettest1: $(COMMON_OBJS) bitsettest1.o
	$(CXX) $(LDFLAGS) -o $@ $^

bitsettest2: $(COMMON_OBJS) bitsettest2.o
	$(CXX) $(LDFLAGS) -o $@ $^

simplebitsettest: $(COMMON_OBJS) $(SIMPLEBITSET_OBJS) simplebitsettest.o
	$(CXX) $(LDFLAGS) -o $@ $^

%.o: %.cc
	$(CXX) $(CXXFLAGS) -c $< -o $@

.PHONY: all clean distclean

clean:
	rm -f *.o $(TEST_PROGS)

distclean: clean
	rm -f *.d

SRC = $(wildcard *.cc)
-include $(SRC:.cc=.d)

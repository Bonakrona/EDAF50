CXX = g++
CC  = $(CXX)

DEPFLAGS = -MT $@ -MMD -MP -MF $*.d

CPPFLAGS =  -std=c++11 -I.
CXXFLAGS =  -O2 -Wall -Wextra -pedantic-errors -Wold-style-cast 
CXXFLAGS += -std=c++11 
CXXFLAGS += -g
CXXFLAGS += $(DEPFLAGS)
LDFLAGS =   -g 

PROG = trigram_program

SRCS = IO.cc trigram.cc
OBJS = $(SRCS:.cc=.o)

all: $(PROG)

$(PROG): $(OBJS)
	$(CXX) $(LDFLAGS) -o $@ $^

%.o: %.cc
	$(CXX) $(CXXFLAGS) -c $< -o $@

.PHONY: all clean distclean

clean:
	rm -f *.o $(PROG)

distclean: clean
	rm -f *.d

SRC = $(wildcard *.cc)
-include $(SRC:.cc=.d)

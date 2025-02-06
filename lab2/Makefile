CXX = g++
CC  = $(CXX)

DEPFLAGS = -MT $@ -MMD -MP -MF $*.d

CPPFLAGS = -std=c++11 -I.
CXXFLAGS = -O2 -Wall -Wextra -pedantic-errors -Wold-style-cast 
CXXFLAGS += -std=c++11 
CXXFLAGS += -g
CXXFLAGS += $(DEPFLAGS)
LDFLAGS = -g 

PROG = trigram_program

# Include the edit_distance.cc file for the main program.
SRCS = spell.cc dictionary.cc trigram.cc word.cc edit_distance.cc
OBJS = $(SRCS:.cc=.o)

# Default target (for spell checker program):
all: $(PROG)

$(PROG): $(OBJS)
	$(CXX) $(LDFLAGS) -o $@ $^

# To build and run tests:
test: test_edit_distance.o edit_distance.o
	$(CXX) $(LDFLAGS) -o test_edit_distance $^
	./test_edit_distance

# Compile the test_edit_distance program separately
test_edit_distance.o: test_edit_distance.cc edit_distance.h
	$(CXX) $(CXXFLAGS) -c test_edit_distance.cc -o test_edit_distance.o

# Rule for compiling .cc files into .o object files
%.o: %.cc
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean up object files and program
.PHONY: all clean distclean

clean:
	rm -f *.o $(PROG) test_edit_distance

distclean: clean
	rm -f *.d

SRC = $(wildcard *.cc)
-include $(SRC:.cc=.d)

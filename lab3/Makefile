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

SRCS = html_remove_tags.cc
OBJS = $(SRCS:.cc=.o)

GTEST_DIR = /usr/src/gtest
GTEST_LIBS = -lgtest -lgtest_main -pthread
GTEST_INCLUDE = -I/usr/include/gtest

TEST_PROG = test_html_tags
TEST_SRCS = test_html_tags.cc
TEST_OBJS = $(TEST_SRCS:.cc=.o)

all: $(PROG) $(TEST_PROG)

$(PROG): $(OBJS)
	$(CXX) $(LDFLAGS) -o $@ $^

$(TEST_PROG): $(TEST_OBJS) $(OBJS)
	$(CXX) $(LDFLAGS) $(GTEST_LIBS) -o $@ $^

%.o: %.cc
	$(CXX) $(CXXFLAGS) -c $< -o $@

test: $(TEST_PROG)
	./$(TEST_PROG)

.PHONY: all clean distclean

clean:
	rm -f *.o $(PROG) $(TEST_PROG)

distclean: clean
	rm -f *.d

SRC = $(wildcard *.cc)
-include $(SRC:.cc=.d)

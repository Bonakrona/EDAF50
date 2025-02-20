# Compiler
CXX = g++
CXXFLAGS = -std=c++11 -Wall -Wextra -O2

# Source files
SRCS = nstest.cc vns.cc mns.cc umns.cc hns.cc
OBJS = $(SRCS:.cc=.o)

# Output binary
TARGET = nameserver

# Default rule
all: $(TARGET)

# Link object files into the final executable
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

# Compile source files into object files
%.o: %.cc
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean up compiled files
clean:
	rm -f $(OBJS) $(TARGET)

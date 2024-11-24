# Define the sources and objects
SOURCES=$(wildcard src/*.cpp)
OBJS=$(SOURCES:.cpp=.o)

# Define library flags and compiler options
LIBFLAGS = -Iinclude -L. -ltcod -ltcodxx -Wall
CXXFLAGS = -Iinclude -Wall -g

# Define the output executable
TARGET = brogue

# Default target
all: $(TARGET)

# Link the object files to create the executable
$(TARGET): $(OBJS)
	g++ $(OBJS) -o $(TARGET) $(LIBFLAGS)

# Compile source files to object files
src/%.o: src/%.cpp
	g++ $(CXXFLAGS) -c $< -o $@

# Clean up build files
clean:
	rm -f $(OBJS) $(TARGET)

# Phony targets
.PHONY: all clean
re: clean all
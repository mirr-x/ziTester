# Define the compiler
CC = gcc

# Define the target executable and source files
TARGET = ziTester
ROOT = /home/$(USER)/ziTester/zi_tester
SRC = $(ROOT)/tools/*.c $(ROOT)/days/C0*/*.c $(ROOT)/zi.c

# Default rule to build the target
all: $(TARGET)

# Rule to compile and link the source files into the executable
$(TARGET):
	$(CC) $(SRC) -o $@

# Rule to clean up generated files
clean:
	rm -f $(TARGET)

# Rule to rebuild the project
re: clean all

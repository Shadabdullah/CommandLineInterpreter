# Define variables
CC = gcc                # The compiler to use
CFLAGS = -Wall -g       # Compiler flags, -Wall enables all warnings, -g for debugging
OUTPUT = cshell         # The name of the output program
SRC = main.c tokenizer.c readinput.c  # Source files

# Default rule to build the program
all: $(OUTPUT)

# Rule to link object files and create the executable
$(OUTPUT): main.o tokenizer.o readinput.o
	$(CC) $(CFLAGS) $^ -o $@

# Rules for compiling each source file into an object file
main.o: main.c tokenizer.h readinput.h
	$(CC) $(CFLAGS) -c main.c

tokenizer.o: tokenizer.c tokenizer.h
	$(CC) $(CFLAGS) -c tokenizer.c

readinput.o: readinput.c readinput.h tokenizer.h
	$(CC) $(CFLAGS) -c readinput.c

# Clean up compiled files
clean:
	rm -f $(OUTPUT) *.o

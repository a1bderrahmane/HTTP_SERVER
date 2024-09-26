# Compiler and flags
CC = g++
CFLAGS = -Wall -g
INCLUDES = -I../Server -I../

# Object files
OBJ = Client.o Request.o

# Default target: compile the object files
all: $(OBJ)

# Compile Client.cpp into an object file
Client.o: Client.cpp Client.h Request.h
	$(CC) $(CFLAGS) $(INCLUDES) -c Client.cpp

# Compile Request.cpp into an object file
Request.o: Request.cpp Request.h
	$(CC) $(CFLAGS) $(INCLUDES) -c Request.cpp

# Clean target to remove object files
clean:
	@echo "Cleaning up object files"
	rm -f *.o

# Indicate that 'all' and 'clean' are not file targets
.PHONY: all clean

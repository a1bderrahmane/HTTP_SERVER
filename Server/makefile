# Server/makefile
CC = g++
CFLAGS = -Wall -g
INCLUDES = -I../Client -I../

# Object files
OBJ = Server.o Response.o

# The target library
all: libserver.a

# Create the static library from object files
libserver.a: $(OBJ)
	@echo "Creating static library libserver.a"
	ar rcs libserver.a $(OBJ)

# Compile Server.cpp
Server.o: Server.cpp Server.h
	$(CC) $(CFLAGS) $(INCLUDES) -c Server.cpp

# Compile Response.cpp
Response.o: Response.cpp Response.h
	$(CC) $(CFLAGS) $(INCLUDES) -c Response.cpp

# Clean target
clean:
	@echo "Cleaning up object files and library"
	rm -f *.o libserver.a

# Indicate that 'all' and 'clean' are not file targets
.PHONY: all clean

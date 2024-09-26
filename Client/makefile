# Client/makefile
CC = g++
CFLAGS = -Wall -g
INCLUDES = -I../Server -I../

# Object files
OBJ = Client.o Request.o




# Compile Client.cpp
Client.o: Client.cpp Client.h
	$(CC) $(CFLAGS) $(INCLUDES) -c Client.cpp

# Compile Request.cpp
Request.o: Request.cpp Request.h
	$(CC) $(CFLAGS) $(INCLUDES) -c Request.cpp

# Clean target
clean:
	@echo "Cleaning up object files and library"
	rm -f *.o libclient.a

# Indicate that 'all' and 'clean' are not file targets
.PHONY: all clean

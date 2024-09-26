# Tests/makefile
CC = g++
CFLAGS = -Wall -g
INCLUDES = -I../Client -I../Server

# Object files for test cases
OBJ_TESTS = ClientTests.o ServerTests.o Client.o Request.o Server.o Response.o

# Targets for the executables
SERVER_TEST_EXEC = server_test_executable
CLIENT_TEST_EXEC = client_test_executable

# Compile both test cases without using libraries
all: tests

# Compile both test cases directly from sources
tests: $(CLIENT_TEST_EXEC) $(SERVER_TEST_EXEC)

# Compile client tests (includes Client and Request sources)
$(CLIENT_TEST_EXEC): ClientTests.o Client.o Request.o
	$(CC) $(CFLAGS) $(INCLUDES) -o $(CLIENT_TEST_EXEC) ClientTests.o Client.o Request.o

# Compile server tests (includes Server and Response sources)
$(SERVER_TEST_EXEC): ServerTests.o Server.o Response.o
	$(CC) $(CFLAGS) $(INCLUDES) -o $(SERVER_TEST_EXEC) ServerTests.o Server.o Response.o

# Compile individual test object files
ClientTests.o: ClientTests.cpp
	$(CC) $(CFLAGS) $(INCLUDES) -c ClientTests.cpp

ServerTests.o: ServerTests.cpp
	$(CC) $(CFLAGS) $(INCLUDES) -c ServerTests.cpp

# Compile Client and Request source files
Client.o: ../Client/Client.cpp ../Client/Client.h
	$(CC) $(CFLAGS) $(INCLUDES) -c ../Client/Client.cpp

Request.o: ../Client/Request.cpp ../Client/Request.h
	$(CC) $(CFLAGS) $(INCLUDES) -c ../Client/Request.cpp

# Compile Server and Response source files
Server.o: ../Server/Server.cpp ../Server/Server.h
	$(CC) $(CFLAGS) $(INCLUDES) -c ../Server/Server.cpp

Response.o: ../Server/Response.cpp ../Server/Response.h
	$(CC) $(CFLAGS) $(INCLUDES) -c ../Server/Response.cpp

# Clean object files and executables
clean:
	rm -f *.o $(CLIENT_TEST_EXEC) $(SERVER_TEST_EXEC)

# Run server tests in the current terminal
run_server_tests: $(SERVER_TEST_EXEC)
	./$(SERVER_TEST_EXEC)

# Run client tests in the current terminal
run_client_tests: $(CLIENT_TEST_EXEC)
	./$(CLIENT_TEST_EXEC)

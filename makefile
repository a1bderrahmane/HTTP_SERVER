# Root makefile
.PHONY: all client server tests run clean

# Target for building everything
all: client server tests

# Target for building the client
client:
	$(MAKE) -C Client

# Target for building the server
server:
	$(MAKE) -C Server

# Target for building the tests and main executable
tests:
	$(MAKE) -C Tests

# Command to run the entire project
run:
	$(MAKE) -C Tests run

# Clean all components
clean:
	$(MAKE) -C Client clean
	$(MAKE) -C Server clean
	$(MAKE) -C Tests clean

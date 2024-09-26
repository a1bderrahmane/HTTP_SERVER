# Compile the client and server in their respective directories
gnome-terminal -- bash -c "cd Client && make"
gnome-terminal -- bash -c "cd Server && make"

# Compile the tests
gnome-terminal -- bash -c "cd Tests && make"

# Wait for the compilation to finish and the server to be ready
sleep 2

# Run the server test in a new terminal
gnome-terminal -- bash -c "cd Tests && ./server_test_executable; exec bash"

sleep 2

gnome-terminal -- bash -c "cd Tests && ./client_test_executable; exec bash"

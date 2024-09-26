# Compile the client and server in their respective directories
# gnome-terminal -- bash -c "cd Client && make"
# gnome-terminal -- bash -c "cd Server && make"

# # Compile the tests
# gnome-terminal -- bash -c "cd Tests && make"
gnome-terminal -- bash -c " make"

# Wait for the compilation to finish and the server to be ready
sleep 5
# Run the server test in a new terminal
gnome-terminal -- bash -c "cd Tests && ./server_test_executable; exec bash"

# sleep 0.01

gnome-terminal -- bash -c "cd Tests && ./client_test_executable; exec bash"

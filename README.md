# CppExample_UDP_ServerClient

This is a very basic example on C++ UDP Server and Client for Linux

The project uses CMake, and in order to build the server and client perform the following

1. Create a build folder
    
        mkdir build

2. Inside the build folder run

        cmake ..

3. Still inside the build folder run

        make

Inside the build folder the two application server and client will be present, if the building proccess succeeded. Run the binaries with

    ./server <Port>

    ./client <IPv4> <Port>
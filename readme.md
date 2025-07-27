A simple, custom-built Remote Procedure Call (RPC) framework in C++ using the POCO libraries. It demonstrates client-server communication using TCP sockets and JSON-based messaging.

## Tech Stack


**Language:** C++17  
**Libraries:** POCO (Net, JSON, Util)  
**Build System:** CMake  
**Platform:** Windows  
**Package Manager:** vcpkg  
**IDE:** Visual Studio Code or Visual Studio Build Tools


## Requirements

- CMake 3.10+
- Visual Studio 2019 or later (with MSVC)
- vcpkg
- Poco C++ libraries
## Installation

1. Clone the repository
```bash
git clone https://github.com/SurajSetty01/MyRPCFramework.git
cd MyRPCFramework
```
2. Install dependencies using vcpkg after making sure you've already set up vcpkg and then run:
```bash
cd C:/path/to/vcpkg
./vcpkg install poco[net,json,util]
vcpkg install poco[net,json,util,xml] --triplet x64-windows
```

3. Build the project
```bash
cd C:/MyRPCFramework
mkdir build && cd build
cmake .. -DCMAKE_TOOLCHAIN_FILE=C:/path/to/vcpkg/scripts/buildsystems/vcpkg.cmake
cmake --build . --config Debug
```


    
## Run Locally
Run the server (in one terminal)
```bash
./Debug/rpc_server.exe
```
Run the client (in another terminal)
```bash
./Debug/rpc_client.exe
```



## Features

- JSON-RPC style request and response
- TCP-based client-server communication using POCO
- Modular code with clear separation of concerns
- Easy to extend with new methods
- CMake-based build system

## Documentation

- `message.cpp` / `message.h`: JSON message creation and parsing
- `server_handler.cpp` / `server_handler.h`: Logic to handle incoming requests
- `server.cpp`: Starts TCP server
- `client.cpp`: Sends a sample RPC request to the server


## Optimizations

- Used newline to mark end of request (easy JSON parsing)
- Added error handling for unsupported methods
- Modular handlers allow future scalability


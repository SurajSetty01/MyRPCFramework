# cmake_minimum_required(VERSION 3.10)
# project(MyRPCFramework)

# set(CMAKE_CXX_STANDARD 17)

# add_executable(rpc_server src/server.cpp)
# add_executable(rpc_client src/client.cpp)

# # Include directories if needed
# target_include_directories(rpc_server PRIVATE include)
# target_include_directories(rpc_client PRIVATE include)

# # Link Poco libraries
# find_package(Poco REQUIRED COMPONENTS Net JSON Util Foundation)
# target_link_libraries(rpc_server PRIVATE Poco::Net Poco::JSON Poco::Util Poco::Foundation)
# target_link_libraries(rpc_client PRIVATE Poco::Net Poco::JSON Poco::Util Poco::Foundation)

# add_executable(test_message src/test_message.cpp src/message.cpp)
# target_include_directories(test_message PRIVATE include)
# target_link_libraries(test_message PRIVATE Poco::Net Poco::JSON Poco::Util Poco::Foundation)

# cmake_minimum_required(VERSION 3.10)
# project(MyRPCFramework)

# set(CMAKE_CXX_STANDARD 17)

# find_package(Poco REQUIRED COMPONENTS Net JSON Util Foundation)

# add_executable(test_message src/test_message.cpp src/message.cpp)
# target_include_directories(test_message PRIVATE include)
# target_link_libraries(test_message PRIVATE Poco::Net Poco::JSON Poco::Util Poco::Foundation)

# add_executable(rpc_server src/server.cpp src/server_handler.cpp src/message.cpp)
# target_include_directories(rpc_server PRIVATE include)
# target_link_libraries(rpc_server PRIVATE Poco::Net Poco::JSON Poco::Util Poco::Foundation)

# cmake_minimum_required(VERSION 3.10)
# project(MyRPCFramework)

# set(CMAKE_CXX_STANDARD 17)

# # Find Poco using vcpkg
# find_package(Poco REQUIRED COMPONENTS Net JSON Util Foundation)

# # Build the actual RPC server
# add_executable(rpc_server
#     src/server.cpp
#     src/server_handler.cpp
#     src/message.cpp
# )

# target_include_directories(rpc_server PRIVATE include)
# target_link_libraries(rpc_server PRIVATE Poco::Net Poco::JSON Poco::Util Poco::Foundation)

cmake_minimum_required(VERSION 3.10)
project(MyRPCFramework)

set(CMAKE_CXX_STANDARD 17)

# Find Poco with required components
find_package(Poco REQUIRED COMPONENTS Net JSON Util Foundation)

# 🔹 rpc_server
add_executable(rpc_server
    src/server.cpp
    src/server_handler.cpp
    src/message.cpp
)
target_include_directories(rpc_server PRIVATE include)
target_link_libraries(rpc_server PRIVATE Poco::Net Poco::JSON Poco::Util Poco::Foundation)

# 🔹 rpc_client
add_executable(rpc_client
    src/client.cpp
    src/message.cpp
)
target_include_directories(rpc_client PRIVATE include)
target_link_libraries(rpc_client PRIVATE Poco::Net Poco::JSON Poco::Util Poco::Foundation)


# MyRPCFramework

A lightweight C++ Remote Procedure Call (RPC) framework using the [Poco C++ Libraries](https://pocoproject.org/). This framework demonstrates basic client-server communication using the JSON-RPC 2.0 protocol over TCP sockets.

---

## 📌 Features

- 🧠 Custom JSON-RPC message structure (`method`, `params`, `id`)
- 🔗 TCP server using Poco's `TCPServer`
- 🧾 Simple request handler with a built-in `add(a, b)` method
- ⚙️ Easily extendable for new RPC methods
- 🔄 Uses `Poco::JSON`, `Poco::Net`, and `Poco::Util`

---

## 📁 Project Structure

MyRPCFramework/
├── src/
│ ├── client.cpp # Client that sends JSON-RPC requests
│ ├── server.cpp # Starts the TCP server
│ ├── server_handler.cpp # Handles each client request
│ └── message.cpp # Utilities for JSON message parsing
├── include/
│ ├── server_handler.h
│ └── message.h
├── CMakeLists.txt
├── .gitignore
└── README.md ✅ ← you're here!

yaml
Copy
Edit

---

## ⚙️ Requirements

- CMake 3.10+
- Visual Studio 2019 or later (with MSVC)
- [vcpkg](https://github.com/microsoft/vcpkg)
- Poco C++ libraries

---

## 🧰 Setup & Build Instructions (Windows)

### 1. Clone the Repository

```bash
git clone https://github.com/YOUR_USERNAME/MyRPCFramework.git
cd MyRPCFramework
2. Install Dependencies via vcpkg
Make sure you've already set up vcpkg and then run:

bash
Copy
Edit
vcpkg install poco[net,json,util,xml] --triplet x64-windows
🔁 If it says “already installed,” you’re good to go.

3. Build the Project
bash
Copy
Edit
mkdir build
cd build
cmake .. -DCMAKE_TOOLCHAIN_FILE=C:/path/to/vcpkg/scripts/buildsystems/vcpkg.cmake
cmake --build . --config Debug
Replace C:/path/to/vcpkg with your actual vcpkg path (e.g., C:/Users/Asus/Downloads/vcpkg).

🚀 How to Run
Terminal 1 – Run the Server
bash
Copy
Edit
cd build
.\Debug\rpc_server.exe
You should see:

arduino
Copy
Edit
Server running on port 9999...
Terminal 2 – Run the Client
bash
Copy
Edit
cd build
.\Debug\rpc_client.exe
Output:

sql
Copy
Edit
Result from server: 10
🧪 Sample JSON Exchange
Client Request
json
Copy
Edit
{
  "jsonrpc": "2.0",
  "method": "add",
  "params": [4, 6],
  "id": 1
}
Server Response
json
Copy
Edit
{
  "jsonrpc": "2.0",
  "result": 10,
  "id": 1
}
✅ Future Improvements
Add more RPC methods like subtract, multiply, divide

Async/threaded client handling

Add a GUI or CLI tool to test methods dynamically

Error logging and metrics

🧠 Author
Suraj S
Third-year student, passionate about systems programming, networking, and C++ frameworks.
# Distributed Key-Value Store 🗃️

A simple fault-tolerant key-value store built in **C++** using **TCP socket programming**. Supports `PUT`, `GET`, and `DELETE` operations from a CLI-based client. This project demonstrates core distributed systems concepts like concurrency, storage, and request-response handling.

---

## ✨ Features

- 🔐 In-memory thread-safe key-value store
- 📡 Client-server architecture using TCP sockets
- ✅ Basic unit tests included
- 💻 Linux & Windows compatible (via Winsock/Git Bash/WSL)
- ⚙️ Ready for extension with replication and leader election

---

---

## 🚀 Getting Started

### 🔧 Build (Linux / Git Bash with make)

```bash
make        # Builds server, client, test
make test   # Runs test cases
make clean  # Cleans up binaries

```
### Compile Manually 
```
g++ -std=c++17 src/server.cpp src/kv-store.cpp -o server -lws2_32
g++ -std=c++17 src/client.cpp -o client -lws2_32
g++ -std=c++17 test/test_cases.cpp src/kv-store.cpp -o test/test_kvstore -lws2_32

```
### Run App

```
./server 5000
```

```
./client
```

### Test Commands
```
PUT name Garvit
PUT email garvit@example.com
GET name
DELETE email
```

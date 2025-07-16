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
```bash
g++ -std=c++17 src/server.cpp src/kv-store.cpp -o server -lws2_32
g++ -std=c++17 src/client.cpp -o client -lws2_32
g++ -std=c++17 test/test_cases.cpp src/kv-store.cpp -o test/test_kvstore -lws2_32

```
### Run App

```bash
./server 5000
```

```bash
./client 5000 # another teminal
```

### Test Commands
```bash
PUT name Garvit
PUT email garvit@example.com
GET name
DELETE email
```

---

## 🔮 Future Improvements (Fault Tolerance and Scaling)

- 🔁 **Replication**: Implement a `ReplicaManager` to forward all `PUT`/`DELETE` commands to follower servers
- 🗳️ **Leader Election**: Use the Bully algorithm or Raft to elect a new leader when the current one fails
- ❤️ **Heartbeat Monitoring**: Add regular “I'm alive” messages between nodes to detect leader failure
- 📜 **Write-Ahead Logging**: Log all operations to disk before execution to allow replay after a crash
- 💾 **Persistence**: Periodically save the key-value store to disk and load it on server startup
- 🔀 **Multi-key Fetch (MGET)**: Add support to fetch multiple key-values in one command (e.g., `MGET name email`)
- 🌐 **Quorum Reads/Writes**: Extend with read/write quorum logic for better consistency during network partitions
- 🔧 **Dockerization**: Package server and client in Docker containers for simplified deployment

---

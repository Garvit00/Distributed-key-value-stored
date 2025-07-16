CXX = g++
CXXFLAGS = -std=c++17 -Wall
LDFLAGS = 
RM = rm -f

UNAME_S := $(shell uname -s)

ifeq ($(UNAME_S),Windows_NT)
    CXXFLAGS += -lws2_32
    RM = del /Q
    TEST_EXE = test\\test_kvstore.exe
else
    TEST_EXE = test/test_kvstore
endif

SRC_DIR = src
TEST_DIR = test

SERVER_SRC = $(SRC_DIR)/server.cpp $(SRC_DIR)/kv-store.cpp
CLIENT_SRC = $(SRC_DIR)/client.cpp
TEST_SRC   = $(TEST_DIR)/test_cases.cpp $(SRC_DIR)/kv-store.cpp

all: server client test

server: $(SERVER_SRC)
	$(CXX) $(CXXFLAGS) -o server $(SERVER_SRC) $(LDFLAGS)

client: $(CLIENT_SRC)
	$(CXX) $(CXXFLAGS) -o client $(CLIENT_SRC) $(LDFLAGS)

test: $(TEST_SRC)
	$(CXX) $(CXXFLAGS) -o $(TEST_EXE) $(TEST_SRC) $(LDFLAGS)
	./$(TEST_EXE)

clean:
	-$(RM) server client test/test_kvstore test\\test_kvstore.exe 2>/dev/null || exit 0

#pragma once
#include <unordered_map>
#include <string>
#include <mutex>

class KeyValueStore {
private:
    std::unordered_map<std::string, std::string> store;
    std::mutex mtx;

public:
    std::string put(const std::string& key, const std::string& value);
    std::string get(const std::string& key);
    std::string del(const std::string& key);
};
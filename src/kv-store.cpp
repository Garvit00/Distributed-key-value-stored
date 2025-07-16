#include "kv-store.hpp"

std::string KeyValueStore::put(const std::string& key, const std::string& value) {
    std::lock_guard<std::mutex> lock(mtx);
    store[key] = value;
    return "OK";
}

std::string KeyValueStore::get(const std::string& key) {
    std::lock_guard<std::mutex> lock(mtx);
    if (store.find(key) != store.end()) return store[key];
    return "NOT_FOUND";
}

std::string KeyValueStore::del(const std::string& key) {
    std::lock_guard<std::mutex> lock(mtx);
    if (store.erase(key)) return "OK";
    return "NOT_FOUND";
}
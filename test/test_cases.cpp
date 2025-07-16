#include "../src/kv-store.hpp"
#include <cassert>
#include <iostream>

int main() {
    KeyValueStore kv;

    // Test PUT
    assert(kv.put("name", "Garvit") == "OK");

    // Test GET
    assert(kv.get("name") == "Garvit");
    assert(kv.get("nonexistent") == "NOT_FOUND");

    // Test DELETE
    assert(kv.del("name") == "OK");
    assert(kv.get("name") == "NOT_FOUND");
    assert(kv.del("name") == "NOT_FOUND");

    std::cout << "✅ All test cases passed!\n";
    return 0;
}
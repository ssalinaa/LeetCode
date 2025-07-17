#include <iostream>
#include <unordered_set>

int main() {

    std::unordered_set<int> hashSet;
    hashSet.insert(10);
    hashSet.insert(20);
    hashSet.insert(30);
    hashSet.insert(10);

    if(hashSet.find(20) != hashSet.end()) {
        std::cout << "20 is in the set";
    }
    hashSet.erase(10);
}
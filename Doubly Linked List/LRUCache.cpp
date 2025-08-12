#include <iostream>
#include <unordered_map>

class LRUCache {
private:
    struct Node {
        int key, value;
        Node* next;
        Node* previous;

        Node(int key, int value) : key(key), value(value), next(nullptr), previous(nullptr) { }
    };

    int capacity;
    std::unordered_map<int, Node*> cache;
    Node* head;
    Node* tail;

    void remove(Node* node) {
        node->previous->next = node->next;
        node->next->previous = node->previous;
    }

    void insert(Node* node) {
        node->next = head->next;
        node->previous = head;

        head->next->previous = node;
        head->next = node;
    }

public:
    LRUCache(int capacity) : capacity(capacity) {
        head = new Node(0, 0);
        tail = new Node(0, 0);
        head->next = tail;
        tail->previous = head;
    }

    int get(int key) { 
        if(cache.find(key) != cache.end()) {
            Node* node = cache[key];
            remove(node);
            insert(node);
            return node->value;
        }
        return -1;
    }

    void put(int key, int value) {
        if (cache.find(key) != cache.end()) {
            remove(cache[key]);
            delete cache[key];  
        }

        Node* node = new Node(key, value);
        insert(node);
        cache[key] = node;

        if (cache.size() > capacity) {
            Node* lru = tail->previous;
            remove(lru);
            cache.erase(lru->key);
            delete lru;
        }
    }

    ~LRUCache() {
        Node* current = head;
        while (current) {
            Node* next = current->next;
            delete current;
            current = next;
        }
    }
};

int main() {

    LRUCache lRUCache(2);
    lRUCache.put(1, 1);
    lRUCache.put(2, 2);
    std::cout << lRUCache.get(1) << std::endl; 
    lRUCache.put(3, 3);              
    std::cout << lRUCache.get(2) << std::endl; 
    lRUCache.put(4, 4);              
    std::cout << lRUCache.get(1) << std::endl; 
    std::cout << lRUCache.get(3) << std::endl; 
    std::cout << lRUCache.get(4) << std::endl; 
    
    return 0;
}
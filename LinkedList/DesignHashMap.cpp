#include <iostream>

class MyHashMap {
private:
    struct ListNode {
    int value;
    int key;
    ListNode* next;
    ListNode() : value(0), next(nullptr) { }
    ListNode(int value) : value(value), next(nullptr) { }
    ListNode(int value, int key, ListNode* next = nullptr) : value(value), key(key), next(next) { }
    };
    ListNode* head;
public:
    MyHashMap() : head(nullptr) { }
    void put(int key, int value) {
        ListNode* newListNode = new ListNode(key, value);
        if(!head) {
            head = newListNode;
            return;
        }

        ListNode* current = head;
        ListNode* previous = nullptr;
        while(current) {
            if(current->key == key) {
                current->value = value;
                return;
            }
            previous = current;
            current = current->next;
        }
        previous->next = newListNode;
    }
    int get(int key) {
        if(!head) {
            throw std::invalid_argument("Empty map!");
        }
        ListNode* current = head;
        while(current) {
            if(current->key == key) {
                return current->value;
            }
            else {
                current = current->next;
            }
        }
        return -1;
    }
    void remove(int key) {
        if(!head) {
            throw std::invalid_argument("Empty map!");
        }
        if(head->key == key) {
            ListNode* toBeDeleted = head;
            head = head->next;
            delete toBeDeleted;
            return;
        }
        ListNode* current = head;
        ListNode* previous = nullptr;
        while(current) {
            if(current->key == key) {
                previous->next = current->next;
                delete current;
                return;
            }
            previous = current;
            current = current->next;
        }
    }
};

int main() {

    MyHashMap myHashMap;
    myHashMap.put(1, 1);
    myHashMap.put(2, 2);
   
    std::cout << "Get key 1: " << myHashMap.get(1) << std::endl; 
    std::cout << "Get key 3: " << myHashMap.get(3) << std::endl; 

    myHashMap.put(2, 1);
    std::cout << "Get key 2 after update: " << myHashMap.get(2) << std::endl; 
    myHashMap.remove(2);
    std::cout << "Get key 2 after removal: " << myHashMap.get(2) << std::endl; 

    return 0;
}
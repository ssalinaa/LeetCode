#include <iostream>

class MyHashSet {
private:
    struct ListNode {
    int value;
    ListNode* next;
    ListNode() : value(0), next(nullptr) { }
    ListNode(int value) : value(value), next(nullptr) { }
    ListNode(int value, ListNode* next) : value(value), next(next) { }
    };
    ListNode* head;
public:
    MyHashSet() : head(nullptr) { }

    void add(int key) {
        if(contains(key)) return;
        ListNode* newListNode = new ListNode(key);
        if(!head) {
            head = newListNode;
            return;
        }

        ListNode* current = head;
        while(current->next) {
            current = current->next;
        }
        current->next = newListNode;
    }
    bool contains(int key) {
        if(!head) return false;
        ListNode* current = head;
        while(current) {
            if(current->value == key) {
                return true;
            }
            current = current->next;
        }
        return false;
    }
    void remove(int key) {
        if(!head) throw std::invalid_argument("Empty set!");
        if(!contains(key)) {
            throw std::invalid_argument("Set does not conatin such value!");
        }
        while(head && head->value == key) {
            ListNode* toBeDeleted = head;
            head = head->next;
            delete toBeDeleted;
        }
        ListNode* current = head;
        while(current && current->next) {
            if(current->next->value == key) {
                ListNode* toBeDeleted = current->next;
                current->next = toBeDeleted->next;
                delete toBeDeleted;
            } else {
                current = current->next;
            }
        }
    }
};

int main() {

    MyHashSet myHashSet;
    myHashSet.add(1);
    myHashSet.add(2);

    std::cout << "Contains 1: " << std::boolalpha << myHashSet.contains(1) << std::endl; 
    std::cout << "Contains 3: " << std::boolalpha << myHashSet.contains(3) << std::endl; 

    myHashSet.add(2);
    std::cout << "Contains 2: " << std::boolalpha << myHashSet.contains(2) << std::endl; 

    myHashSet.remove(2);
    std::cout << "Contains 2 after removal: " << std::boolalpha << myHashSet.contains(2) << std::endl; 

    myHashSet.remove(3);

    return 0;
}
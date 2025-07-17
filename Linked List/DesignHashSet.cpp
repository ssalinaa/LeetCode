#include <iostream>

class MyHashSet {
private:
    struct Node {
        int value;
        Node* next;
        
        Node() : value(0), next(nullptr) { }
        Node(int value) : value(value), next(nullptr) { }
        Node(int value, Node* next) : value(value), next(next) { }
    };
    Node* head;
public:
    MyHashSet() : head(nullptr) { }

    void add(int key) { 
        if(contains(key)) return;
        Node* newNode = new Node(key);
        if(!head) {
            head = newNode;
            return;
        }

        Node* current = head;
        while(current->next) {
            current = current->next;
        }
        current->next = newNode;
    }

    bool contains(int key) { 
        if(!head) return false;
        Node* current = head;
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
            throw std::invalid_argument("Set does not contain such value!");
        }
        while(head && head->value == key) {
            Node* toBeDeleted = head;
            head = head->next;
            delete toBeDeleted;
        }
        Node* current = head;
        while(current && current->next) {
            if(current->next->value == key) {
                Node* toBeDeleted = current->next;
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
    myHashSet.add(10);
    myHashSet.add(20);
    myHashSet.add(30);
    myHashSet.add(40);
    myHashSet.add(50);

    std::cout << "Contains 10: " << std::boolalpha << myHashSet.contains(10) << std::endl;
    std::cout << "Contains 50: " << std::boolalpha << myHashSet.contains(50) << std::endl;
    std::cout << "Contains 60: " << std::boolalpha << myHashSet.contains(60) << std::endl;

    myHashSet.remove(50);
    std::cout << "Contains 50 after removal: " << std::boolalpha << myHashSet.contains(50) << std::endl;

    return 0;
}

#include <iostream>

struct Node {
    int value;
    Node* next;

    Node(int value, Node* next = nullptr) {
        this->value = value;
        this->next = next;
    }
};

bool isPresentRecursive(Node* head, int key) {
    if(!head) return false;
    if(head->value == key) return true;

    return isPresentRecursive(head->next, key);
}

int main() {

    Node* head = new Node(14);
    head->next = new Node(15);
    head->next->next = new Node(21);
    head->next->next->next = new Node(13);
    head->next->next->next->next = new Node(30);
    head->next->next->next->next->next = new Node(10);
    int key = 13;
    if(isPresentRecursive(head, key)) {
        std::cout << "Yes" << std::endl;
    } else {
        std::cout << "No" << std::endl;
    }

    return 0;
}
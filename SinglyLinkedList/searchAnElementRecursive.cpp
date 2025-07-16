#include <iostream>

struct Node {
    int value;
    Node* next;

    Node(int value, Node* next = nullptr) {
        this->value = value;
        this->next = next;
    }
};


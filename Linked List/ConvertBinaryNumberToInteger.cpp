#include <iostream>
#include <cmath>

struct Node {
    int value;
    Node* next;
    
    Node() : value(0), next(nullptr) { }
    Node(int value) : value(value), next(nullptr) { }
    Node(int value, Node* next) : value(value), next(next) { }
};

int getLength(Node* head) {
    int length = 0;
    while(head) {
        length++;
        head = head->next;
    }
    return length;
}

int getNumber(Node* head) {
    int number = 0;
    int length = getLength(head);
    Node* current = head;
    while(current) {
        number += current->value * std::pow(2, length - 1);
        length--;
        current = current->next;
    }
    return number;
}

int main() {
    
    Node* head = new Node(1);
    head->next = new Node(0);
    head->next->next = new Node(1);
    std::cout << "The number is: " << getNumber(head) << std::endl;
    
    return 0;
}

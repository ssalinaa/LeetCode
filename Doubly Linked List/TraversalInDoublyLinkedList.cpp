#include <iostream>

struct Node {
    int value;
    Node* next;
    Node* previous;

    Node(int value) : value(value), next(nullptr), previous(nullptr) { }
    Node(int value, Node* next, Node* previous) : value(value), next(next), previous(previous) { }
};

void forwardTraversal(Node* head) {
    Node* current = head;
    while(current) {
        std::cout << current->value << " ";
        current = current->next;
    }
    std::cout << std::endl;
}

void forwardTraversalRecursive(Node* head) {
    if(!head) return;
    std::cout << head->value << " ";

    forwardTraversalRecursive(head->next);
}

void backwardTraversal(Node* tail) {
    Node* current = tail;
    while(tail) {
        std::cout << tail->value << " ";
        tail = tail->previous;
    }
    std::cout << std::endl;
}

void backwardTraversalRecursive(Node* tail) {
    if(!tail) return;
    std::cout << tail->value << " ";

    backwardTraversalRecursive(tail->previous);
}

int main() {
    Node* first = new Node(1);
    Node* second = new Node(2);
    Node* third = new Node(3);

    first->next = second;
    second->previous = first;
    second->next = third;
    third->previous = second;

    std::cout << "Forward traversal: ";
    forwardTraversal(first);

    std::cout << "Forward traversal recursive: ";
    forwardTraversal(first);

    std::cout << "Backward traversal: ";
    backwardTraversal(third);

    std::cout << "Backward traversal recursive: ";
    backwardTraversal(third);

    return 0;
}
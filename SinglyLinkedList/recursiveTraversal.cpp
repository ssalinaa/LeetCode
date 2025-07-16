#include <iostream>

struct Node {
    int data;
    Node* next;

    Node(int data, Node* next = nullptr) {
        this->data = data;
        this->next = next;
    }
};

void recursiveTraversal(Node* head) {
    if(!head) return;

    std::cout << head->data << " ";
    recursiveTraversal(head->next);
}

int main() {

    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);
    recursiveTraversal(head);

    return 0;
}
#include <iostream>

struct Node {
    int value;
    Node* next;

    Node(int value, Node* next = nullptr) {
        this->value = value;
        this->next = next;
    }
};

int findLengthRecursive(Node* head) {
    if(!head) return 0;

    return 1 + findLengthRecursive(head->next);
}

int main() {

    Node* head1 = new Node(1);
    head1->next = new Node(3);
    head1->next->next = new Node(1);
    head1->next->next->next = new Node(2);
    head1->next->next->next->next = new Node(1);
    std::cout << "Count of nodes is: " << findLengthRecursive(head1) << std::endl;

    Node* head2 = new Node(2);
    head2->next = new Node(4);
    head2->next->next = new Node(1);
    head2->next->next->next = new Node(9);
    head2->next->next->next->next = new Node(5);
    head2->next->next->next->next->next = new Node(3);
    head2->next->next->next->next->next->next = new Node(6);
    std::cout << "Count of nodes is: " << findLengthRecursive(head2) << std::endl;

    return 0;
}
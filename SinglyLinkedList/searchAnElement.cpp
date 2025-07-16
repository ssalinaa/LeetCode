#include <iostream>

struct Node {
    int value;
    Node* next;

    Node(int value, Node* next = nullptr) {
        this->value = value;
        this->next = next;
    }
};

bool isPresent(Node* head, int key) {
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

int main() {

    Node* head1 = new Node(14);
    head1->next = new Node(21);
    head1->next->next = new Node(11);
    head1->next->next->next = new Node(30);
    head1->next->next->next->next = new Node(10);
    int key1 = 14;

    if(isPresent(head1, key1)) {
        std::cout << "Yes" << std::endl;
    } else {
        std::cout << "No" << std::endl;
    }

    Node* head2 = new Node(6);
    head2->next = new Node(21);
    head2->next->next = new Node(17);
    head2->next->next->next = new Node(30);
    head2->next->next->next->next = new Node(10);
    head2->next->next->next->next->next = new Node(8);
    int key2 = 13;

    if(isPresent(head2, key2)) {
        std::cout << "Yes" << std::endl;
    } else {
        std::cout << "No" << std::endl;
    }

    return 0;
}

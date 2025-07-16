#include <iostream>

struct Node {
    int value;
    Node* next;

    Node(int value, Node* next = nullptr) {
        this->value = value;
        this->next = next;
    }
};

Node* deleteAtSpecificPosition(Node* head, int position) {
    if(!head || position <= 0) return head;
    if(position == 1) {
        Node* toBeDeleted = head;
        head = head->next;
        delete toBeDeleted;
        return head;
    }
    Node* current = head;
    for (size_t i = 1; i < position - 1 && current && current->next; i++)
    {
        current = current->next;
    }
    if(!current || !current->next) return head;
    Node* toBeDeleted = current->next;
    current->next = toBeDeleted->next;
    delete toBeDeleted;
    return head;
}

void printList(Node* head) {
    Node* current = head;
    while(current) {
        std::cout << current->value << " ";
        current = current->next;
    }
    std::cout << std::endl;
}

int main() {

    Node* head = new Node(2);
    head->next = new Node(3);
    head->next->next = new Node(4);
    head->next->next->next = new Node(5);
    head->next->next->next->next = new Node(6);

    std::cout << "Original Linked list: ";
    printList(head);

    std::cout << "After deleting the node at the specific position: ";
    int position = 2;
    head = deleteAtSpecificPosition(head, position);
    printList(head);

    return 0;
}
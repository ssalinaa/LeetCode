#include <iostream>

#include <iostream>

struct Node {
    int value;
    Node* next;

    Node(int value, Node* next = nullptr) {
        this->value = value;
        this->next = next;
    }
};

Node* insertAtSpecificPosition(Node* head, int position, int newValue) {
    Node* newNode = new Node(newValue);
    if(position < 1) {
        return head;
    }
    if(position == 1) {
        newNode->next = head;
        return newNode;
    }
    Node* current = head;
    for (size_t i = 1; i < position - 1 && current; i++)
    {   
        current = current->next;
    }
    if(!current) {
        return head;
    }
    newNode->next = current->next;
    current->next = newNode;
    
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

    Node* head = new Node(3);
    head->next = new Node(5);
    head->next->next = new Node(8);
    head->next->next->next = new Node(10);

    std::cout << "Original Linked list: ";
    printList(head);

    std::cout << "After inserting new node at the end: ";
    int value = 12, position = 3;
    head = insertAtSpecificPosition(head, position, value);
    printList(head);

    return 0;
}
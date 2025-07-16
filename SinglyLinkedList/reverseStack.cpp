#include <iostream>
#include <stack>

struct Node {
    int value;
    Node* next;

    Node(int value, Node* next = nullptr) {
        this->value = value;
        this->next = next;
    }
};

Node* reverseStack(Node* head) {
    std::stack<Node*> s;
    Node* current = head;
    while(current->next) {
        s.push(current);
        current = current->next;
    }
    head = current;
    while(!s.empty()) {
        current->next = s.top();
        s.pop();
        current = current->next;
    }
    current->next = nullptr;
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

    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);

    std::cout << "Original list: ";
    printList(head);
    std::cout << "After reversing list: ";
    head = reverseStack(head);
    printList(head);

    return 0;
}
#include <iostream>

struct Node {
    int value;
    Node* next;
    Node() : value(0), next(nullptr) { }
    Node(int value) : value(value), next(nullptr) { }
    Node(int value, Node* next) : value(value), next(next) { }
};

Node* removeDuplicates(Node* head) {
    if(!head) return head;
    Node* newList = new Node(0);
    newList->next = head;

    Node* current = head;
    while(current && current->next) {
        if(current->value == current->next->value) {
            Node* toBeDeleted = current->next;
            current->next = toBeDeleted->next; 
            delete toBeDeleted;
        }
        current = current->next;
    }
    return newList->next;
}

void printList(Node* head) {
    Node* current = head;
    while(current) {
        std::cout << current->value << " -> ";
        current = current->next;
    }
    std::cout << "nullptr";
    std::cout << std::endl;
}

void deallocate(Node* head) {
    while(head) {
        Node* toBeDeleted = head;
        head = head->next;
        delete toBeDeleted;
    }
}

int main() {

    Node* head1 = new Node(1);
    head1->next = new Node(1);
    head1->next->next = new Node(2);

    Node* newList1 = removeDuplicates(head1);
    printList(newList1);

    Node* head2 = new Node(1);
    head2->next = new Node(1);
    head2->next->next = new Node(2);
    head2->next->next->next = new Node(3);
    head2->next->next->next->next = new Node(3);
    
    Node* newList2 = removeDuplicates(head2);
    printList(newList2);

    deallocate(head1);
    deallocate(head2);
    deallocate(newList1);
    deallocate(newList2);

    return 0;
}
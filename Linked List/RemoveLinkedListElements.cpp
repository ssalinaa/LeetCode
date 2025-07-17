#include <iostream>

struct Node {
    int value;
    Node* next;
    Node() : value(0), next(nullptr) { }
    Node(int value) : value(value), next(nullptr) { }
    Node(int value, Node* next) : value(value), next(next) { }
};

Node* removeElements(Node* head, int value) {
    if(!head) return head;
    while(head && head->value == value) {
        Node* toBeDeleted = head;
        head = head->next;
        delete toBeDeleted;
    }

    Node* current = head;
    while(current && current->next) {
        if(current->next->value == value) {
            Node* toBeDeleted = current->next;
            current->next = toBeDeleted->next;
            delete toBeDeleted;
        } else {
            current = current->next;
        }
    }
    return head;
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
    head1->next = new Node(2);
    head1->next->next = new Node(6);
    head1->next->next->next = new Node(3);
    head1->next->next->next->next = new Node(4);
    head1->next->next->next->next->next = new Node(5);
    head1->next->next->next->next->next->next = new Node(6);

    Node* newList1 = removeElements(head1, 6);
    printList(newList1);

    Node* head2 = new Node(7);
    head2->next = new Node(7);
    head2->next->next = new Node(7);
    head2->next->next->next = new Node(7);
   
    Node* newList2 = removeElements(head2, 7);
    printList(newList2);

    deallocate(head1);
    deallocate(newList1);
    deallocate(head2);
    deallocate(newList2);

    return 0;
}
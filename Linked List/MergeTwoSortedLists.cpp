#include <iostream>

struct Node {
    int value;
    Node* next;
    Node() : value(0), next(nullptr) { }
    Node(int value) : value(value), next(nullptr) { }
    Node(int value, Node* next) : value(value), next(next) { }
};

Node* mergeLists(Node* head1, Node* head2) {
    Node* newList = new Node(0);
    Node* current = newList;
 
    while(head1 && head2) {
        if(head1->value < head2->value) {
            current->next = head1;
            head1 = head1->next;
        } else {
            current->next = head2;
            head2 = head2->next;
        }
        current = current->next;
    }
    if(head1) {
        current->next = head1;
    } else if(head2) {
        current->next = head2;
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
    head1->next = new Node(2);
    head1->next->next = new Node(4);

    Node* head2 = new Node(1);
    head2->next = new Node(3);
    head2->next->next = new Node(4);
    
    Node* mergedLists = mergeLists(head1, head2);
    printList(mergedLists);
    deallocate(head1);
    deallocate(head2);
    deallocate(mergedLists);

    return 0;
}
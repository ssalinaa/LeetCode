#include <iostream>

struct Node {
    int value;
    Node* next;
    Node() : value(0), next(nullptr) { }
    Node(int value) : value(value), next(nullptr) { }
    Node(int value, Node* next) : value(value), next(next) { }
};

int getLength(Node* head) {
    int length = 0;
    while(head) {
        length++;
        head = head->next;
    }
    return length;
}

Node* intersection(Node* head1, Node* head2) {

    Node* current1 = head1;
    Node* current2 = head2;
    int length1 = getLength(current1);
    int length2 = getLength(current2);

    while(length1 > length2) {
        current1 = current1->next;
        length1--;
    }
    while(length2 > length1) {
        current2 = current2->next;
        length2--;
    }
    while(current1 && current2) {
        if(current1 == current2) {
            return current1;
        }
        current1 = current1->next;
        current2 = current2->next;
    }
    return nullptr;
}

void deallocate(Node* head) {
    while(head) {
        Node* toBeDeleted = head;
        head = head->next;
        delete toBeDeleted;
    }
}

int main() {

    Node* commonPart = new Node(8);
    commonPart->next = new Node(4);
    commonPart->next->next = new Node(4);

    Node* head1 = new Node(4);
    head1->next = new Node(1);
    head1->next->next = commonPart;

    Node* head2 = new Node(5);
    head2->next = new Node(6);
    head2->next->next = new Node(1);
    head2->next->next->next = commonPart;
    
    Node* intersectionNode = intersection(head1, head2);
    if(intersectionNode) {
        std::cout << "Intersection at node with value: " << intersectionNode->value << std::endl;
    } else {
        std::cout << "No intersection found. " << std::endl;
    }
   
    deallocate(head1);
    deallocate(head2);
    deallocate(intersectionNode);

    return 0;
}
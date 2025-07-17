#include <iostream>

struct Node {
    int value;
    Node* next;
    Node() : value(0), next(nullptr) { }
    Node(int value) : value(value), next(nullptr) { }
    Node(int value, Node* next) : value(value), next(next) { }
};

bool hasCycle(Node* head) {
    if(!head || !head->next) return false;

    Node* slow = head;
    Node* fast = head;
    while(fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast) {
            return true;
        }
    }
    return false;
}

void deallocate(Node* head) {
    while(head) {
        Node* toBeDeleted = head;
        head = head->next;
        delete toBeDeleted;
    }
}

int main() {

    Node* head1 = new Node(3);
    head1->next = new Node(2);
    head1->next->next = new Node(0);
    head1->next->next->next = new Node(-4);
    head1->next->next->next->next = head1->next;
    std::cout << std::boolalpha << hasCycle(head1) << std::endl;

    Node* head2 = new Node(1);
    head2->next = new Node(2);
    head2->next->next = head2;
    std::cout << std::boolalpha << hasCycle(head2) << std::endl;

    Node* head3 = new Node(1);
    std::cout << std::boolalpha << hasCycle(head3) << std::endl;

    deallocate(head1);
    deallocate(head2);
    deallocate(head3);

    return 0;
}
#include <iostream>

struct Node {
    int value;
    Node* next;
    Node() : value(0), next(nullptr) { }
    Node(int value) : value(value), next(nullptr) { }
    Node(int value, Node* next) : value(value), next(next) { }
};

Node* reverseList(Node* head) {
   if(!head) return head;

   Node* current = head;
   Node* previous = nullptr;
   Node* next;
   while(current) {
        next = current->next;
        current->next = previous;
        previous = current;
        current = next;
   }
   return previous;
}

Node* copyList(Node* head) {
    if(!head) return nullptr;
    Node* newHead = new Node(head->value);
    Node* currentNew = newHead;
    Node* currentOld = head->next;

    while(currentOld) {
        currentNew->next = new Node(currentOld->value);
        currentNew = currentNew->next;
        currentOld = currentOld->next;
    }
    return newHead;
}

bool isPalindrome(Node* head) {
    Node* copied = copyList(head);
    Node* reversed = reverseList(copied);

    Node* p1 = head;
    Node* p2 = reversed;

    while(p1 && p2) {
        if(p1->value != p2->value) {
            deallocate(reversed);
            return false;
        }
        p1 = p1->next;
        p2 = p2->next;
    }
    deallocate(reversed);
    return true;
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
    head1->next->next = new Node(2);
    head1->next->next->next = new Node(1);

    std::cout << std::boolalpha << isPalindrome(head1) << std::endl;    
    
    Node* head2 = new Node(1);
    head2->next = new Node(2);
    head2->next->next = new Node(3);
    head2->next->next->next = new Node(1);

    std::cout << std::boolalpha << isPalindrome(head2) << std::endl;    
    deallocate(head1);
    deallocate(head2);

    return 0;
}
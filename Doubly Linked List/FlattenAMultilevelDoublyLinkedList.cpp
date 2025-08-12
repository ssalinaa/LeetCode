#include <iostream>

class Node {
public:
    int value;
    Node* previous;
    Node* next;
    Node* child;

    Node(int value) : value(value), previous(nullptr), next(nullptr), child(nullptr) {}
};

class Solution {
public:
    Node* flatten(Node* head) {
        if(!head) return nullptr;
        flattenDFS(head);
        return head;
    }
private:
    Node* flattenDFS(Node* node) {
        Node* current = node;
        Node* last = nullptr;

        while(current) {
            Node* next = current->next;
            if(current->child) {
                Node* childHead = current->child;
                Node* childTail = flattenDFS(childHead);

                current->next = childHead;
                childHead->previous = current;

                if(next) {
                    childTail->next = next;
                    next->previous = childTail;
                }

                current->child = nullptr;
                last = childTail;
            } else {
                last = current;
            }
            current = next;
        }
        return last;
    }
};

void printList(Node* head) {
    Node* current = head;
    while (current) {
        std::cout << current->value;
        if (current->next) std::cout << " -> ";
        current = current->next;
    }
    std::cout << std::endl;
}

int main() {
   
    Node* n1 = new Node(1);
    Node* n2 = new Node(2);
    Node* n3 = new Node(3);
    Node* n4 = new Node(4);
    Node* n5 = new Node(5);
    Node* n6 = new Node(6);

    n1->next = n2;
    n2->previous = n1;
    n2->next = n3;
    n3->previous = n2;
    n3->next = n4;
    n4->previous = n3;
    n4->next = n5;
    n5->previous = n4;
    n5->next = n6;
    n6->previous = n5;

    Node* n7 = new Node(7);
    Node* n8 = new Node(8);
    Node* n9 = new Node(9);
    Node* n10 = new Node(10);

    n7->next = n8;
    n8->previous = n7;
    n8->next = n9;
    n9->previous = n8;
    n9->next = n10;
    n10->previous = n9;

    n3->child = n7;

    Node* n11 = new Node(11);
    Node* n12 = new Node(12);

    n11->next = n12;
    n12->previous = n11;

    n8->child = n11;

    Solution solution;
    Node* flatHead = solution.flatten(n1);
    printList(flatHead);

    return 0;
}
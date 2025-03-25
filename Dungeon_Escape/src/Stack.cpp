#include "../header/Stack.h"

// stack implementation through linked-list
Stack::Stack() : topNode(nullptr) {}

Stack::~Stack() {
    clear();
}

void Stack::push(Room* room) {
    Node* newNode = new Node(room);
    newNode->next = topNode;
    topNode = newNode;
}

void Stack::pop() {
    // deallocate memory occupied by the node in the stack
    if (topNode) {
        Node* temp = topNode;
        topNode = topNode->next;
        delete temp;
    }
}

Room* Stack::top() const {
    return (topNode) ? topNode->room : nullptr;
}

bool Stack::isEmpty() const {
    return topNode == nullptr;
}

void Stack::clear() {
    while (!isEmpty()) {
        pop();
    }
}

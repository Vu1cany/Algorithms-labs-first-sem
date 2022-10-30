#include <iostream>

struct My_stack{
    struct Node{
        int data = 0;
        Node* next = nullptr;
    };

    Node* Head = nullptr;

    bool Empty() {
        return Head == nullptr;
    }

    void Push(int _data) {
        Node* n = new Node;
        n->data = _data;
        n->next = Head;
        Head = n;
    }

    int Pop() {
        if (!Empty()) {
            int data = Head->data;
            Head = Head->next;
            return data;
        }
        return 0;
    }
};

int main() {
    My_stack stack1;
    std::cout << stack1.Empty() << "\n";
    stack1.Push(2);
    std::cout << stack1.Empty() << "\n";
    std::cout << stack1.Pop() << "\n";
    std::cout << stack1.Empty() << "\n";
    std::cout << stack1.Pop() << "\n";
    std::cout << stack1.Empty() << "\n";
    return 0;
}
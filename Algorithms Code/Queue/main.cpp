#include <iostream>

struct My_queue{
    struct Node{
        int data;
        Node* next = nullptr;
    };

    Node* Head = nullptr;
    Node* Tail = nullptr;

    bool Empty() {
        return Head == nullptr;
    }

    void Push(int _data) {
        Node* n = new Node;
        n->data = _data;
        if (Empty()) {
            Tail = n;
            Head = n;
            Head->next = Tail;
        } else {
            Tail->next = n;
            Tail = n;
        }
    }

    int Pop() {
        if (Empty()) return 0;
        int data = Head->data;
        Head = Head->next;
        return data;
    }
};

int main() {
    My_queue Queue1;
    std::cout << Queue1.Empty() << "\n";
    Queue1.Push(2);
    Queue1.Push(6);
    std::cout << Queue1.Pop() << "\n";
    std::cout << Queue1.Empty() << "\n";
    std::cout << Queue1.Pop() << "\n";
    std::cout << Queue1.Empty() << "\n";
    std::cout << Queue1.Pop() << "\n";
    return 0;
}
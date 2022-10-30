#include <iostream>

struct stack{
    struct Node {
        int data;
        Node *next = nullptr;
        Node *prev = nullptr;
    };

    Node *first = nullptr;
    Node *last = nullptr;

    bool empty() {
        return first == nullptr;
    }

    void add(int _data) {
        Node *p = new Node;
        p-> data = _data;
        if (empty()) {
            first = p;
            last = p;
            return;
        }
        last->next = p;
        p->next = nullptr;
        p->prev = last;
        last = p;
    }

    void delLast() {
        if (empty()) return;
        std::cout << last->data << "\n";
        if (last == first) {
            last = nullptr;
            first = nullptr;
            return;
        }
        Node *p = last;
        last = p->prev;
        last-> next = nullptr;
        delete p;
    }

};

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n;
    std::cin >> n;
    char command;
    int value;
    stack Stack;
    for (int i = 0; i < n; ++i) {
        std::cin >> command;
        if (command == '+') {
            std::cin >> value;
            Stack.add(value);
        } else if (command == '-') {
            Stack.delLast();
        }
    }
    return 0;
}
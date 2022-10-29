#include <iostream>

struct Queue {
    struct Node {
        int data;
        Node *next = nullptr;
    };

    Node *first = nullptr;
    Node *last = nullptr;

    bool empty() {
        return first == nullptr;
    }

    void add(int val) {
        Node *p = new Node;
        p-> data = val;
        if (empty()) {
            first = p;
            last = p;
        } else {
            last-> next = p;
            last = p;
        }
    }

    void del_first() {
        if (empty()) return;
        std::cout << first-> data << "\n";
        Node *p = first;
        first = p-> next;
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
    Queue Queue1;
    for (int i = 0; i < n; ++i) {
        std::cin >> command;
        if (command == '+') {
            std::cin >> value;
            Queue1.add(value);
        } else if (command == '-') {
            Queue1.del_first();
        }
    }
    return 0;
}